/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * DESCRIPTION
 * The ArduinoGateway prints data received from sensors on the serial link. 
 * The gateway accepts input on seral which will be sent out on radio network.
 *
 * The GW code is designed for Arduino Nano 328p / 16MHz
 *
 * Wire connections (OPTIONAL):
 * - Inclusion button should be connected between digital pin 3 and GND  
 * - RX/TX/ERR leds need to be connected between +5V (anode) and digital pin 6/5/4 with resistor 270-330R in a series
 *
 * LEDs (OPTIONAL):
 * - To use the feature, uncomment WITH_LEDS_BLINKING in MyConfig.h
 * - RX (green) - blink fast on radio message recieved. In inclusion mode will blink fast only on presentation recieved
 * - TX (yellow) - blink fast on radio message transmitted. In inclusion mode will blink slowly
 * - ERR (red) - fast blink on error during transmission error or recieve crc error 
 * 
 */

#define NO_PORTB_PINCHANGES  

#include <MySigningNone.h>
#include <MyTransportRFM69.h>
#include <MyTransportNRF24.h>
#include <MyHwATMega328.h>
#include <MySigningAtsha204Soft.h>
#include <MySigningAtsha204.h>

#include <SPI.h>  
#include <MyParserSerial.h>  
#include <MySensor.h>  
#include <stdarg.h>
#include <PinChangeInt.h>
#include "GatewayUtil.h"

#define INCLUSION_MODE_TIME 1 // Number of minutes inclusion mode is enabled
#define INCLUSION_MODE_PIN  3 // Definição do pino digital para botão
#define RADIO_ERROR_LED_PIN 4  // Pino do LED de erro
#define RADIO_RX_LED_PIN    6  // Pino do LED de recebimento
#define RADIO_TX_LED_PIN    5  // Pino do LED de transmissão

// NRFRF24L01 radio driver (transmissão de baixa potência) 
MyTransportNRF24 transport(RF24_CE_PIN, RF24_CS_PIN, RF24_PA_LEVEL_GW);
//MyTransportRFM69 transport;

// Definição do tipo do Hardware(Microcontrolador) 
MyHwATMega328 hw;

// Definição e criação do argumento gw do tipo MySensor a partir do parâmetro WITH_LEDS_BLINKING de MyConfig.h
#ifdef WITH_LEDS_BLINKING
MySensor gw(transport, hw /*, signer*/, RADIO_RX_LED_PIN, RADIO_TX_LED_PIN, RADIO_ERROR_LED_PIN);
#else
MySensor gw(transport, hw /*, signer*/);
#endif

char inputString[MAX_RECEIVE_LENGTH] = "";    // String para manter comandos de entrada serial/ethernet
int inputPos = 0;
boolean commandComplete = false;  // Se a string está completa

void parseAndSend(char *commandBuffer);

// Função para saída serial
void output(const char *fmt, ... ) {
   va_list args;
   va_start (args, fmt );
   vsnprintf_P(serialBuffer, MAX_SEND_LENGTH, fmt, args);
   va_end (args);
   Serial.print(serialBuffer);
}

// Função de configuração
void setup()  
{ 
  gw.begin(incomingMessage, 0, true, 0);

  setupGateway(INCLUSION_MODE_PIN, INCLUSION_MODE_TIME, output);

  // Adicionando interrupção para inclusão de pino.
  PCintPort::attachInterrupt(pinInclusion, startInclusionInterrupt, RISING);


  // Enviar mensagem da inicialização serial.
  serial(PSTR("0;0;%d;0;%d;Gateway startup complete.\n"),  C_INTERNAL, I_GATEWAY_READY);
}

void loop()  
{ 
  gw.process();

  checkButtonTriggeredInclusion();
  checkInclusionFinished();
  
  // Verifica se um comando serial foi emitido
  if (commandComplete) {
    // Comando serial tentará ser enviado ao atuador
    parseAndSend(gw, inputString);
    commandComplete = false;  
    inputPos = 0;
  }
}


/*
  SerialEvent ocorre sempre que for acionado o pino de
 recebimento(RX). Esta rotina é executada sempre que a
 função loop() for executada, portanto a resposta pode
 sofrer atraso.
 */
void serialEvent() {
  while (Serial.available()) {
    // Pega o novo byte:
    char inChar = (char)Serial.read(); 
    // se o caractere de entrada é uma nova linha, gere uma flag (sinalizador).
    // tratamento no loop principal
    if (inputPos<MAX_RECEIVE_LENGTH-1 && !commandComplete) { 
      if (inChar == '\n') {
        inputString[inputPos] = 0;
        commandComplete = true;
      } else {
        // adicionando uma string de entrada (inputString):
        inputString[inputPos] = inChar;
        inputPos++;
      }
    } else {
       // Mensagens antigas são deletadas. 
        inputPos = 0;
    }
  }
}



