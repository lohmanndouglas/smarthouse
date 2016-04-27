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
 * REVISION HISTORY
 * Version 1.0 - Henrik Ekblad
 * 
 * DESCRIPTION
 * Motion Sensor example using HC-SR501 
 * http://www.mysensors.org/build/motion
 *
 */

#include <MySensor.h>  
#include <SPI.h>

unsigned long SLEEP_TIME = 120000; // tempo de espera (em milisegundos)
#define DIGITAL_INPUT_SENSOR 3   // Definição do pino digital 3 para o sensor de movimento.
#define INTERRUPT DIGITAL_INPUT_SENSOR-2 // Pino para interrupção
#define CHILD_ID 1   // Id do sensor movimento

int node_id = 3;

MySensor gw;
// Inicialização do sensor (id do sensor e seu valor inicial)
MyMessage msg(CHILD_ID, V_TRIPPED);

void setup()  
{  
  gw.begin(NULL, node_id);

  // Envio de informações do sensor (tipo e versão)
  gw.sendSketchInfo("Motion Sensor", "1.0");

  pinMode(DIGITAL_INPUT_SENSOR, INPUT);      // pino 3 se torna um pino de entrada.
  // Registra todos os sensores no Gateway
  gw.present(CHILD_ID, S_MOTION);
  
}

void loop()     
{     
  // Le e compara o valor do pino de entrada com "ALTO", o resultado insere na variavel tripped
  boolean tripped = digitalRead(DIGITAL_INPUT_SENSOR) == HIGH; 
        
  Serial.println(tripped);
  gw.send(msg.set(tripped?"1":"0"));  // Envia valor da variavel tripped para o Gateway
 
  // Caso houver mudança no valor do sensor, o tempo de espera é encerrado e gera ma interrupção
  gw.sleep(INTERRUPT,CHANGE, SLEEP_TIME);
}
