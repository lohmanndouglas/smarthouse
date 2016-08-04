.. smart-house documentation master file, created by
   sphinx-quickstart on Wed Apr 13 10:56:41 2016.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Sobre o Projeto
======================================

Este projeto tem como objetivo apresentar os fundamentos computacionais para 
construção de uma casa inteligente. Nas proximas seçoes serão apresentados todos 
os passos do desenvolvimento de softawere necessario para construção da casa e 
todos os conteudos necessesarios para o entendimento dessa. 

O projeto visa a construção de Recurso educacional aberto (REA). Segundo o Projeto 
Brasileiro sobre Recursos Educacionais Abertos, REA são materiais de ensino, 
aprendizado e pesquisa, fixados em qualquer suporte ou mídia, que estejam sob domínio
público ou licenciados de maneira aberta, permitindo que sejam utilizados ou adaptados por terceiros.
Para maiores informações sobre REA acesse: http://www.rea.net.br/site/.

Os arquivos e códigos fonte do projetos estão disponíveis em: https://github.com/lohmanndouglas/smarthouse.git. 

Licença
=======================================

Este projeto é um software livre; você pode redistribuí-lo e/ou 
modificá-lo dentro dos termos da Licença Pública Geral GNU como 
publicada pela Fundação do Software Livre (FSF); na versão 3 da 
Licença.

.. toctree::
   :maxdepth: 2

	Licença <license.rst>

Casa inteligente 
=======================================

	- escrever introdução

Internet das Coisas
=======================================

A Internet pode ser dividida em três fases. A primeira fase é a Internet como uma rede de computadores. A segunda fase a Internet pode ser considerada uma rede de pessoas e comunidades. Atualmente estamos vivendo a evolução para terceira fase, a Internet das Coisas (do inglês, Internet of Things - IoT). Nesta fase a rede passa a interligar vários tipos de objetos e dispositivos inteligentes do nosso cotidiano que vão interagir entre si e conosco.

.. toctree::
   :maxdepth: 2

	Internet das Coisas <internetDasCoisas.rst>

Processo de desenvolvimento de software
=======================================

Para começarmos o desenvolvimento de sistema de software exitem vários métodos e ferramentas que auxiliam no controle do desenvolvimento do projeto, neste trabalho utilizamos o método kanban, que é uma metódo ágil de desenvolvimento de software baseado nas práticas Lean, e tem como objetivo otimizar o processo de desenvolvimento de software. Para auxiliar na utilização desse metódo vamos usar a ferramenta Waffle.io. 

Para contrução da casa devemos em primeiro momento realizar um levantamento dos requisitos necessário para que está atenda todas as necessidades desejadas, feito o levantamento dos requisitos dividimos estes em tarefas e as distribuimos no Kanban Board. 

		Board disponível em:
		https://waffle.io/lohmanndouglas/smarthouse/join

Hardware
=======================================
	
	- sistemas embarcados
	- microcontroladores
	- sensores
	- atuadores

Arduino 
=======================================

Arduino - https://www.arduino.cc/en/Guide/Introduction - é uma plataforma de prototipagem de código aberto baseada na fácil utilização do software e hardware. As placas Arduino são capazes de efetuarem leitura de uma entrada (sensores) e transformar em uma de saída (Atuadores). O projeto Arduino nasceu no Ivrea Interaction Design Institute como uma ferramenta fácil para prototipagem rápida, destinado a estudantes sem conhecimento aprofundado em eletrônica e programação. 

A plataforma Arduino possui uma IDE para a programação e para gravar códigos na placa, a IDE está possui suporte a Linux, Mac e Windows. 

Existem diversas placas de hardware Arduino, sendo a mais comum a Arduino Uno. As placas diferem basicamente no microcontrolador embutido, no número de entradas/saídas, na frequência de processamento e entre outras configurações.

Neste Material vamos utilizar o Arduino Uno por ser facilmente encontrado no mercado e apresentar baixo custo de aquisição se comparado com outras plataformas de hardware.

O Arduino Uno - https://www.arduino.cc/en/Main/ArduinoBoardUno - opera com uma velocidade de clock de 16 MHz, possui 14 pinos de entrada e saída digitais e 6 pinos de entrada e saída analógica, memória flash 32 KB (0.5 KB usados pelo Bootloader), memória SRAM de 2 KB e 1 KB de memória EEPROM. 

A placa pode ser alimentada pela conexão USB ou por uma fonte de alimentação externa. Para alimentação externa é utilizado um conector Jack com positivo no centro, sendo que a placa suporta alimentação de 6 à 20 volts. Porém, é recomendado que a fonte de alimentação externa possua tensão entre 7 e 12 volts. 

A Figura 1 ilustra o Arduino Uno utilizado neste projeto, ele tem 14 pinos de entradas/saídas digitais. Alguns desses pinos possuem funções especificas como PWM (pinos 3, 5, 6, 9, 10 e 11 ), comunicação serial (pinos 0 e 1) e interrupção externa (pinos 2 e 3).
Para interface com o mundo analógico, a placa Arduino UNO possui 6 entradas, onde cada uma tem a resolução de 10 bits.

.. figure:: arduino.jpg
   :scale: 60%
   :align: center
   :alt: map to buried treasure

   Figura 1: Arduino Uno.

Estrutura IoT
=======================================
 
 A seguir é descrito uma estrutura para IoT, composta pelos componentes de hardware e software
 citados nos tópicos anteriores. 

 .. toctree::
   :maxdepth: 2

   Estrutura Iot <estruturaIoT.rst>


Implementação da Estrutura IoT
=======================================
 
Os próximos tópicos descrevem a implementação básica da infraestrutura IoT.

 .. toctree::
   :maxdepth: 2

   Implementação Iot <implementacaoIoT.rst>

Conhecida a implementação da estrutura básica IoT podemos facilmente adaptar essa estrutura para o contexto
de casas inteligentes. Podemos utilizando a plataforma Waffle.io descrever os requisitos desejaveis em uma casa
inteligente no formato de estórias e assim realizarmos a construção do sistema. O próximo tópico apresenta alguns exemplos para auxiliar na implementação de requisitos desejaveis em uma casa inteligente.  


Estrutura da Casa Inteligente
=======================================


O contexto deste projeto, pode ser muitas vezes considerado amplo, pois o mesmo gera aplicações em praticamente qualquer espaço e necessidade apresentada em uma casa. Para que fosse possível obter resultados, foi necessário focar em alguns objetivos mais específicos e, a partir destes, criar soluções com a utilização de arduíno e outros tipos de componentes.

	- Planta da casa
	- Planta da casa com sensores
	- estorias

Abaixo temos alguns exemplos de estórias ja implementadas. 

.. toctree::
   :maxdepth: 2

	Exemplo<primeiro_exemplo.rst>


Como contribuir com esse projeto? 
=======================================


.. Indices and tables
.. ==================

.. * :ref:`genindex`
.. * :ref:`modindex`
.. * :ref:`search`

