Implementação da Estrutura da Internet das Coisas
=================================================

Para a implementação da estrutura de uma rede IoT devemos construir um nó gateway, um controlador e nós finais (Sensores e Atuadores). 

O rádio nRF24l01+ se comunica com Arduino via interface SPI. O rádio deve ser alimentado com uma tensão de 3.3 volts. 

Como o radio possui conector de 8 pinos não é possível conecta-lo a protoboard. Então devemos utilizar conectores macho-fêmea, como ilustra a Figura 3, para fazer ligação ou construir um shield para adaptação do módulo.

.. figure:: gateway.png
   :scale: 60%
   :align: center
   :alt: map to buried treasure

   Figura 1: Conectando nRF24l01 no Arduino.

Os próximos tópicos descrevem detalhes  para construção de cada tipo de nó.

Implementação Nó Gateway 
======================

Neste tópico vamos demostrar a contrução de nó gateway, que como vimos é responsável pela comunicação entre os nós finais e o controlador. 

Para implementação deste nó devemos conectar o rádio nRf24l01+ no arduino e utilizarmos o código:

.. literalinclude:: ../../codigos/SerialGateway.ino
   :language: c
   :linenos:

Implementação Nó Sensor
======================

A implementação de nós sensores consiste básicamente na conexão de arduino com o rádio nRF24l01+ e a ligação do sensor desejado. A Figura 1 ilustra a ligação do arduino com o nRF24l01 a partir desse ligação deve-se adaptar para adicionar o sensor. Nos subtópicos temos a implementação de alguns sensores. 

.. toctree::
   :maxdepth: 2

	Sensor de Temperatura e umidade <sensor_temp_umidade.rst>
 	Sensor de Luminosidade <sensor_luminosidade.rst>


Implementação Nó Atuador
======================

Os nós atuadores são responsáveis pela interação com o ambiente, são esses nós que realizam ações sobre os meios externos. Para implementação de um nó atuador devemos primeiro conectar o rádio no arduino, como ilustra a Figura 1 e depois devemos adicionar o atuador. Nos subtópicos temos o exemplo da implementação de alguns atuadores. 

.. toctree::
   :maxdepth: 2

	Atuador Servo Motor <atuador_servo_motor.rst>

Implementação Nó Repetidor
=======================

Quando a distancia entre dois nós é maior que a distancia de alcance do rádio é necessário a implementação de um nó repetidor, esse nó utiliza apenas um arduino e um rádio, a comunicação do arduino com o rádio é feita como na Figura 1. Abaixo segue o código utilizado para o nó repetidor.

.. literalinclude:: ../../codigos/RepeaterNode.ino
   :language: c
   :linenos:

Implementação Nó Controlador
=========================

O nó controlador é responsável pela interface entre a rede contruida e a Internet, existem várias opções de controladores disponíveis, neste material utilizamos o MyController.org ou o Pimatic. Ambos podem ser utilizados em um computador pessoal ou até mesmo na raspberry ou na beaglebone. 

.. toctree::
   :maxdepth: 2

	Controlador Pimatic <pimatic.rst>
 	Controlador Mycontroller.org <mycontroller.rst>

Uma lista de controladores com suporte para a biblioteca mysensors esta disponível em https://www.mysensors.org/controller/. 