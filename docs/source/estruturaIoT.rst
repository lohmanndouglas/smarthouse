Estrutura da Internet das Coisas
================================

.. figure:: InternetDasCoisas.png
   :scale: 50 %
   :align: center
   :alt: map to buried treasure

   Estrutura da Internet das Coisas

Nó Gateway 
===========

O gateway atua na ligação entre o controlador e rede de rádios. Ele traduz as mensagens do rádio para um protocolo que pode ser entendido por um controlador. 

Na biblioteca MySensors exitem tres implementações de Gateway, o Ethernet Gateway, SerialGateway e MQTTGateway. Nesse material vamos utilizar o SerialGateway pela facilidade de implementação e também pela compatibilidade com o controlador escolhido.


Nó Sensor
===========

Nó Atuador
===========

Nó Repetidor
============

Esse nó só é necessário quando os nós sensores e gateway não conseguem se comunicar, devido à distancia em que estão localizados, por esse motivo não está representado na Figura~\ref{fig:iot}. Esse nó tem como função repetir as dados para outros nós a fim de aumentar a distancia de comunicação entre os nós. Em muitas aplicações esse nó não esta presente.


Nó Controlador
==============

O controlador pode realizar as seguintes funções:

 - Enviar parâmetros de configuração para os sensores na rede de rádio (tempo e identificadores de sensores únicos);
 - Acompanhar os dados mais recentes enviados pelos sensores e atuadores;
 - Fornecer informações de status de volta para sensores e atuadores; por exemplo o estado atual (on / off / loadLevel) para uma luz;
 - Fornecer controles de interface do usuário para atuadores;
 - Executa horários predefinidos ou cenas; por exemplo. ao pôr do sol acender as luzes do jardim.