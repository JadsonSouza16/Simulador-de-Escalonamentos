# Simulador-de-Escalonamentos
Integrantes:
Discentes do curso de Engenharia Mecatrônica da Universidade Federal De Uberlândia: 
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
_______________________________________________________________________________________________________
Esse projeto fez parte da segunda parte do trabalho da disciplina de Sistemas Operacionais, sendo que o mesmo teve como objetivo de simular o funcionamento de algoritmos de escalonamentos, tais como FCFS, Prioridade não preemptivo, Round Robin e SJF.
E para a simulação, as condições dadas foram de receber uma estrutura do BCP de processos CPU bound e I/O bound, tendo duas CPUs disponíveis e um dispositivo para tratar processos I/O, e durante a execução apresentar as mudanças de estados de cada processo. Por fim, apresentar o Tempo Médio de Retorno e o Tempo Médio de Espera dos processos.

------------------------------------------------------------------------------------------------------------------------------------

Para execução e compilação:

Utilizando make:

1) Esteja com o terminal aberto na pasta do projeto.

2) Digite: "make" para compilar. (sem aspas)

3) Depois digite: "./recurso" para executar. (sem aspas)

Sem utilizar o make:

1) Esteja com o terminal aberto na pasta do projeto.

2) Digite: "gcc -o recurso recurso.c fcfs.c prioridade.c cpu.c round_robin.c SJF.c E_S.c cpu_2.c" para compilar. (sem aspas)

3) Depois digite: "./recurso" para executar. (sem aspas)


---------------------------------------------------------------------------------------------------------------------------------------

Inventário de Arquivos: 

- recurso.c: Faz a leitura da quantidade de tarefas a serem escalonadas e de maneira aleatória gera o burst para processos, também gera o tempo de chegada para cada processo. Após isso as tarefas são colocadas em uma lista, invoca o escalonador de processo com uma função denominada escalonador( ). Descrição detalhada abaixo.

- cpu.c: Esse arquivo representa uma das CPUs. Em seu conteúdo há a função de escalonamento responsável pelo método Round Robin, também há uma função denominada CPU_1 que recebe o processo e faz a verificação de CPU Bound ou I/O bound. Caso seja I/O, a tarefa é destinada ao recurso de I/O. Caso seja CPU Bound, a função realoca o processo à CPU para execução. 

- cpu_2.c: Esse arquivo representa a outra CPU. Há uma função denominada CPU_2 que recebe o processo e faz a verificação de CPU Bound ou I/O bound. Caso seja I/O, a tarefa é destinada ao recurso de I/O. Caso seja CPU Bound, a função realoca o processo à CPU para execução.

- makefile: Contém a diretiva necessária para fazer a compilação dos arquivos "recurso.c", "cpu.c", "cpu_2.c ", "E_S.c", "fcfc.c", "prioridade.c", "round_robin.c" e "SJF.c" para criar os arquivos executáveis.


Paste "Exemplos" - Prints dos resultados de cada escalonamento exibidoa no terminal, sendo que cada um está separados por pastas referentes a cada escalonamento.

Descrição dos arquivos .h:

"bcp.h":
	- Biblioteca responsável por representar o BCP de cada processo.

"recurso.h":
	- Biblioteca responsável pela função escalonador() que recebe 3 parâmetros, sendo eles: tipo de escalonament, lista de processos e número total de processos.

"cpu.h":
	- Simboliza as funções presentes no "cpu.c".

"cpu_2.h":
	- Simboliza a função presente no "cpu_2.c".

"E_S.h":
	- Representa a função dispositivo() presente no arquivo  "E_S.c".

"fcfs.h", "prioridade.h", "round_robin.h" e "SJF.h":
	- Bibliotecas que representam as funções presentes nos respectivos arquivos de escalonamento.
	

Descrição dos arquivos .c:
"recurso.c":
	- Responsável por criar a lista dos processos, receber a opção que dita o tipo de escalonamento e fornece ambos paramentros para o escalonador().

"cpu.c":
	- Possui a função prox_tarefa_rr() que representa a função de escalonamento Round Robin na CPU. 
	- Possui a função CPU_1() que representa a primeira CPU.

"cpu_2.c": 
	- Possui a função CPU_2() que representa a segunda CPU.

"E_S.c":
	- Possui a função dispositivo() que representa o dispostivo de entrada e saída.

"fcfs.c", "prioridade.c", "round_robin.c" e "SJF.c":
	- Funções que representam os tipos de escalonamentos.
