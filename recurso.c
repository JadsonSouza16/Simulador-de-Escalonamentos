/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "recurso.h"

void main () {

  // Contagem de processos
  int n_process;

  printf("\nInsira o número que representa a quantidade de processos a serem executados: ");
  scanf("%d", &n_process);

  // Preenchendo a estrutura do bcp de cada processo
  struct BCP process[n_process];

  int i, aux; //Variáveis auxiliares
   
  for(i=0; i<n_process; i++){
    process[i].id = i + 1;
    process[i].prioridade = 1 + rand() % 20;
    process[i].burst = 1 + rand() % 12;
    process[i].temp_cheg = rand() % 30;
    strcpy(process[i].status, "Novo");
    aux = rand() % 3;
    if(aux == 1 || aux == 3){
      strcpy(process[i].tipo_process, "CPU bound");
    } else {
      strcpy(process[i].tipo_process, "I/O bound");
    };
    if(strcmp(process[i].tipo_process, "I/O bound") == 0){
      process[i].burst = 2;
    }
  }
  
  //Exibindo a lista de processos
  printf("\n\n_______________________________________________________LISTA DE PROCESSOS________________________________________________________________\n\n");
  for(i=0;i<n_process;i++){
    printf("\n\tID: T%d\t\tTipo de processo: %s\t\tTempo de chegada: %d ms\t\tPrioridade: %d\t\tStatus: %s\t\tburst: %d ms\n", process[i].id, process[i].tipo_process, process[i].temp_cheg, process[i].prioridade, process[i].status, process[i].burst);
	}
  
  //Menu de escolha do algoritmo desejado
  int opc;
	do
  {
  printf("\n\nEscolha o tipo de algoritmo de escalonamento para tratar os processos:\n\n1) First-come, first-serve (FCFS)\n2) Prioridade não-preemptivo\n3) Round Robin\n4) Shortest Job First\n\n");
  scanf("%d", &opc); /*Variável opc recolhe a opção do usuário*/
  if(opc != 1 && opc != 2 && opc != 3 && opc != 4){
    printf("\nESCOLHA UMA OPÇÃO VÁLIDA\n\n");
  }
  } while (opc != 1 && opc != 2 && opc != 3 && opc != 4);

  //Invocando o algoritmo de escalonamento escolhido
  escalonador(opc, process, n_process);
 
};