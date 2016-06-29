Estrutura da Internet das Coisas
================================

Uma característica essencial em IoT é a capacidade dos dispositivos se comunicar, direta ou indiretamente, com a Internet. Uma arquitetura típica para isto consiste na construção de uma rede de dispositivos IoT com uma unidade de controle como dispositivo central, sensores que coletam informação do meio ambiente, atuadores e módulos de comunicação. O dispositivo central, neste caso, é encarregado da comunicação com a Internet.

A unidade de controle, no contexto de internet das Coisas, são dispositivos que utilizam um   microcontrolador, o qual é responsável por processar informações. Na oficina utilizamos a plataforma de hardware aberto Arduino, pois este contém uma vasta quantidade de exemplos disponíveis e possui uma comunidade ativa para suporte. 

Os módulos de comunicação são responsáveis pela comunicação entre dispositivos da rede IoT. Alguns dos módulos avaliados foram os módulos WiFi, Bluetooth, nRF24l01 e ZigBee. Um fator importante na escolha do módulo é a existência de uma framework para dar suporte a implementação da rede. Considerando tais fatores, nesta implementação foi escolhido o módulo nRF24l01. Ele é um chip transceptor de baixo custo, projetado para aplicações sem fio, de baixa potencia e suportado por um framework compatível com Arduino, chamado de MySensors. 

MySensors é uma API que possibilita a construção de uma rede de sensores de baixo custo. Além disso, essa API fornece ferramentas para gerenciar e analisar os dados dos sensores. A biblioteca facilita a implementação por possuir muitos exemplos e abstrair protocolos de comunicação entre os nós da rede.   


.. figure:: InternetDasCoisas.png
   :scale: 50 %
   :align: center
   :alt: map to buried treasure

   Figura 2:Estrutura da Internet das Coisas


Utilizando a biblioteca e as plataformas descritas, é possível configurar uma infraestrutura para a rede IoT, como ilustra a Figura 2. A rede implementada  basicamente é constituída por três componentes:  controlador, gateway e nós finais, que são nós sensores e atuadores. Os nós sensores e atuadores são responsáveis pela interação com o ambiente, seja pela coleta de informações por meio de sensores, emissão de sinais de alerta ou ativação de certos dispositivos por meio de atuadores, por exemplo o ar condicionado ou uma lâmpada.

Nó Gateway 
===========

O gateway atua na ligação entre o controlador e rede de rádios. Ele traduz as mensagens do rádio para um protocolo que pode ser entendido por um controlador. 

Na biblioteca MySensors exitem tres implementações de Gateway, o Ethernet Gateway, SerialGateway e MQTTGateway. Nesse material vamos utilizar o SerialGateway pela facilidade de implementação e também pela compatibilidade com o controlador escolhido.


Nó Sensor
===========

blabla

Nó Atuador
===========

blabla

Nó Repetidor
============

Esse nó só é necessário quando os nós sensores e gateway não conseguem se comunicar, devido à distancia em que estão localizados, por esse motivo não está representado na Figura 2. Esse nó tem como função repetir as dados para outros nós a fim de aumentar a distancia de comunicação entre os nós. Em muitas aplicações esse nó não esta presente.


Nó Controlador
==============

O controlador é responsável pela comunicação com a Internet. Na Figura 2 podemos observar que o controlador está diretamente conectado ao gateway e à Internet. Diferentemente dos outros nós, este componente da rede necessita de maior poder de processamento e deve ser implementado em hardware mais robusto, como a Raspberry Pi, BeagleBone ou até mesmo um desktop.

O controlador pode realizar as seguintes funções:

 - Enviar parâmetros de configuração para os sensores na rede de rádio (tempo e identificadores de sensores únicos);
 - Acompanhar os dados mais recentes enviados pelos sensores e atuadores;
 - Fornecer informações de status de volta para sensores e atuadores; por exemplo o estado atual (on / off / loadLevel) para uma luz;
 - Fornecer controles de interface do usuário para atuadores;
 - Executa horários predefinidos ou cenas; por exemplo. ao pôr do sol acender as luzes do jardim.