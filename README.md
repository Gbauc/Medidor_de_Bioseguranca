# Trabalho-do-James
Nesse trabalho faremos a construção de um dispositivo para o monitoramento das condições climáticas e de biossegurança do laboratório de ciência da vida.  

<b>Hardware</b> - foi montado um circuito composto por quatro sensores de gás. Cada um desses sensores tem a capacidade de detectar um tipo específico de gás: gases tóxicos, hidrogênio, etanol/álcool e monóxido de carbono (MQ-8, MQ-3, ~MQ-135, MQ-7). Além da utilização de um sensor de umidade e outro de temperatura e pressão. Todos os sensores foram ligados a portas analógicas do Arduino, senso alimentados por uma saída 5v. 
Além dos sensores, foi utilizado um Buzzer de tipo passivo, com o intuito de oferecer ao usuário uma interface simples de comunicação. 
Para possibilitar o armazenamento dos dados fornecidos pelos sensores e permitir o monitoramento de seu funcionamento, o Arduino foi equipado com um Shield de data logger. 	Esse Shield é capaz de registrar as informações provenientes das portas do Arduino em um cartão SD, possibilitando o armazenamento dos dados de forma conveniente e acessível. 
Com o objetivo de tornar o projeto mais user-friendly, optou-se por desenvolver uma interface física utilizando o software ShaprCAD. A case projetada oferece um design simples e sofisticado, com os sensores posicionados de forma externa, facilitando o contato com o ar ambiente. Além disso, foram providenciadas aberturas e acesso fácil a todas as entradas e saídas do Arduino, visando a comodidade na conexão e manipulação dos componentes. 
<center><img src="Imagem do Arduino-02.jpeg" style="width:350px;height:200px"/></center>
<b>Software</b> – estamos desenvolvendo a leitura dos sensores, junto a gráficos que explicitem de maneira gráfica aos usuários. Estamos estudando formas de armazenamento de dados ou saída desses para a internet. 

