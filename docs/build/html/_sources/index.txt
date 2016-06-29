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

	- engenharia de software
	- requisitos
	- scrum 

		Scrum board disponível em:
		https://waffle.io/lohmanndouglas/smarthouse/join

	- diagrama de classes

Hardware
=======================================
	
	- sistemas embarcados
	- microcontroladores
	- sensores
	- atuadores

Arduino 
=======================================

	- Hardware
	- IDE
	- MySensors

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

	- inserir planta da casa
	- inserir planta da casa com sensores
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

