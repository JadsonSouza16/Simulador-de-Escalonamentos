/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SJF.h"
#include "cpu.h"
#include "cpu_2.h"

//Escalonamento SJF
void SJF(struct BCP process[], int n_process) {
printf("\n\t\tAlgoritmo escolhido: Shortest Job First\n");

int i, j;
struct BCP aux[n_process];

//Ordenando por ordem de chegada
for(i=0; i<n_process; i++){
  for(j=i+1; j<n_process; j++){
    if(process[i].temp_cheg>process[j].temp_cheg){
      aux[i]= process[i];
      process[i]= process[j];
      process[j] = aux[i];
    }
  }
}  

//Verificando e ordenando por ordem de menor tempo de execução
for(i=0; i<n_process; i++){
  for(j=i+1; j<n_process; j++){
    if(process[i].temp_cheg == process[j].temp_cheg){
      if(process[i].burst > process[j].burst){
        aux[i]= process[i];
        process[i]= process[j];
        process[j] = aux[i];
      }
    }
  }
}  

/*Variáveis lock representam a disponibilidade das CPU, sendo 0 livre e 1 para ocupada
aux_1 e aux_2 representam os instantens em que a CPU 1 e a CPU 2 estarão livres, respectivamente*/
int lock_1 = 0, lock_2 = 0, instante = 0, aux_1 = 0, aux_2 = 0, menor = 0;
float espera = 0, retorno = 0, sum_1 = 0, sum_2 = 0; 
float count_TA = 0, count_WT = 0;
    
printf("\n\n___________________________________________________________________________________________\n");
printf("\n\nEscalonamento Shortest Job First\n\n");

while(instante < 100){
  for(i=0; i<n_process; i++){
    //Checando se no instante em questão as CPUs estão livres ou ocupadas
    if( instante == aux_1){
      lock_1 = 0;
    }
    if(instante < aux_1){
      lock_1 = 1;
    }
    if( instante == aux_2){
      lock_2 = 0;
    }
    if(instante < aux_2){
      lock_2 = 1;
    }
    //Verificando se algum processo chega nesse instante 
    if(instante == process[i].temp_cheg){
      printf("__________________________________________________________________________________");
      printf("\nInstante %d: \n", instante);
      if(lock_1 == 0){ //verifica se a CPU 1 tá livre
        strcpy(process[i].status, "Pronto");
        printf("\nProcesso T%d na fila de pronto\tStatus: %s", process[i].id, process[i].status);
        aux_1 = instante + process[i].burst;
        CPU_1(process, i);
        printf("\t\tTempo de execução na CPU: %d ms\n", process[i].burst);
        retorno += process[i].burst;
      }
      if(lock_2 == 0 && lock_1 == 1){ //verifica se a CPU 2 tá livre
        strcpy(process[i].status, "Pronto");
        printf("\nProcesso T%d na fila de pronto\tStatus: %s", process[i].id, process[i].status);
        aux_2 = instante + process[i].burst;
        CPU_2(process, i);
        printf("\t\tTempo de execução na CPU: %d ms\n", process[i].burst);
        retorno += process[i].burst;
      }
      if(lock_1 == 1 && lock_2 == 1){//Condição em que as duas CPUs estão ocupadas
        if(aux_1 < aux_2){ //Nessa condição é checada qual a CPU estará disponível no menor tempo
          menor = aux_2;
        }else{
          menor = aux_1;
        };
        espera += menor - instante;
        retorno += espera;
        process[i].temp_cheg = menor; //Adiciona-se o menor instante da próxima CPU livre para que o processo volte e consiga ser executado
        strcpy(process[i].status, "Pronto");
        printf("\nO processo T%d entrou na fila de pronto e aguarda por uma CPU livre\t Status: %s\t\tTempo de execução: %d ms\n", process[i].id, process[i].status, process[i].burst);
        //Verificando e ordenando por ordem de menor tempo de execução
        for(i=0; i<n_process; i++){
          for(j=i+1; j<n_process; j++){
            if(process[i].temp_cheg == process[j].temp_cheg){
              if(process[i].burst > process[j].burst){
                aux[i]= process[i];
                process[i]= process[j];
                process[j] = aux[i];
              }
            }
          }
        } 
      }
    }  
  }
         
 instante++;
}

count_TA = retorno / n_process; count_WT = espera / n_process;
printf("__________________________________________________________________________________");
printf("\n\nTempo médio de retorno: %.2f ms\t\tTempo médio de espera: %.2f ms\n\n", count_TA, count_WT);

//Após executadas todas tarefas
printf("\n\t\tFila de pronto inativa\n\n");

system("read -p 'Press Enter to continue...' var");
  
};
