# smarthouse

Toda documentação desse projeto está disponível online no [ReadTheDocs](http://smarthouse.readthedocs.org/en/latest/).

## Resumo
Este trabalho descreve a elaboração do projeto intitulado “Automação Residencial
Utilizando IoT”. Tem como objetivo produzir atividades práticas desafiadoras utilizando Internet das Coisas (do inglês, Internet of Things - IoT) para apresentar noções de sistemas computacionais na disciplina de Introdução à Ciência da Computação. Dentre os contextos de utilização de IoT, foi utilizado a automação residencial, pois concilia aplicações do cotidiano e conceitos de computação, tais como redes de sensores e atuadores. Como finalização foi desenvolvido uma maquete de uma residência e um repositório online para realização das práticas em sala de aula. Como resultado desse trabalho temos um REA sobre a aplicação de IoT em casas inteligentes, sendo mais uma forma de auxiliar no ensino-aprendizado de informática, contribuindo para desenvolvimento da ciência e disseminação do conhecimento.  

## Introdução
A integração entre sensores e atuadores sobre a Internet forma a base tecnológica para o conceito de ambientes inteligentes, nos quais a informação gerada por um objeto pode ser compartilhada entre diversas aplicações [1].  Esta integração, denominada Internet das Coisas (IoT -- Internet of Things), apresenta inovações para que pessoas, animais e coisas do nosso cotidiano possam estar conectados à rede e interagirem entre si. 

Uma aplicação de Internet das Coisas é a implementação de casas inteligentes. Com este novo paradigma se faz possível a implementação de novas funcionalidades nas residências, visando o conforto e sustentabilidade.

Os conteúdos abordados neste recursos educacionais abertos geram grande interesse nos alunos, o que pode ser um agente estimulante para o aprendizado de outros conteúdos relacionados a computação e eletrônica. O público alvo são professores e alunos da rede pública de ensino. Sendo assim, pôde-se definir métodos e técnicas para elaboração dos recursos educacionais e suas aplicações. Como foco principal, buscou-se redigir um material disponibilizado em meio web de fácil interpretação com o intuito de fornecer conhecimento para que as aplicações do mesmo fossem replicadas pelo público alvo. Para fins didáticos foi executado a construção de um protótipo físico de casa, para o qual, os alunos, teriam de forma visual e prática a materialização dos projetos estudados durante a execução da oficina.

## Método
Para a concepção da aplicação, utilizou-se a junção entre a programação na plataforma Arduino (com a utilização principal em cima dos conceitos e códigos disponibilizados pela MySensor), componentes eletrônicos básicos (leds, sensores, servos, etc) e também as necessidades encontradas em uma residência. Práticas ágeis de engenharia de software foram utilizadas para a definição e implementação das funcionalidades da residência, com a definição de histórias e implementação em iterações, buscando agregar valor à aplicação a cada passo. Desta forma, como foco inicial, definiram-se os passos que a serem seguidos juntamente com algumas histórias básicas a serem implantadas, sendo por exemplo, o monitoramento de temperatura e umidade, sensores de proximidade, sensores para iluminação, entre outros.

Muitas informações sobre a utilização destes componentes se encontram em bibliotecas especializadas (como a do MySensor). Assim, a utilização delas facilitam a implementação de diversas outras histórias. Para que fosse feita a ligação de todos os componentes foi utilizado, como base central, o controlador MyController, pois é uma plataforma de fácil acesso e dessa forma facilitando a independência do público alvo.

Após a criação e execução de todos os códigos, passou a ser inevitável a aplicação do mesmo em um meio físico, ou seja, foi inserida a construção de uma maquete, tanto para fins de teste como também sendo meio facilitador na execução de minicursos. Dessa forma, os alunos teriam de forma visual e prática a materialização dos projetos estudados durante a execução da oficina.

Finalmente, após concluída todas as etapas, buscou-se redigir um material disponibilizado em meio web de fácil interpretação com o intuito de fornecer conhecimento para que as aplicações do mesmo fossem replicadas pelo público alvo. 

## Referências
[1] Gubbi, J., Buyya, R., Marusic, S., e Palaniswami, M. (2013). "Internet of things (iot): A vision, architectural elements, and future directions". Future Generation Computer Systems, 29(7):1645-1660.

