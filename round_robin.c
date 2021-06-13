/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "round_robin.h"
#include "cpu.h"
#include "cpu_2.h"

//Escalonamento Round Robin
void rr(struct BCP process[], int n_process) {
printf("\n\t\tAlgoritmo escolhido: Round Robin\n");

int i, j;
struct BCP aux[n_process];

//Verificando e ordenando por ordem de chegada
for(i=0; i<n_process; i++){
  for(j=i+1; j<n_process; j++){
    if(process[i].temp_cheg>process[j].temp_cheg){
      aux[i]= process[i];
      process[i]= process[j];
      process[j] = aux[i];
    }
  }
}  

//Invocando a função próxima tarefa do escalonamento
prox_tarefa_rr(process, n_process);

//Após executadass todas tarefas
printf("\n\t\tFila de pronto inativa\n\n");

system("\nread -p 'Press Enter to continue...' var");
  
};