/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira ferreira - 11721EMT005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fcfs.h"
#include "prioridade.h"
#include "round_robin.h"
#include "SJF.h"
#include "E_S.h"
#include "cpu.h"
#include "cpu_2.h"


//Para o escalonamento Round Robin
void prox_tarefa_rr(struct BCP process[], int n_process){
    int quantum = 5;
    int posi_fila = 0, count_fila = n_process;
    int time = 0, init = 0, final, i=0;
    float count_TA = 0, count_WT = 0;
    float retorno = 0;


    
    printf("\n\n___________________________________________________________________________________________\n");
    printf("\n\nEscalonamento Round-Robin - Quantum %d ms \n\n", quantum);

    //Chama o processo de acordo com a chegada e o executa
    while(count_fila != 0) {
        while(process[posi_fila].burst <= 0 && strcmp(process[posi_fila].status, "Finalizado") == 0){ //Tira os processos que não tem mais tempo na CPU da primeira posição
            posi_fila++;
            if(posi_fila >= n_process){
                posi_fila = 0;
            } //Faz a rotação    
        }
        //CPU_1(process, posi_fila);
        strcpy(process[posi_fila].status, "Pronto");
        printf("\nO processo T%d entrou na fila de pronto\tStatus: %s\n\n", process[posi_fila].id, process[posi_fila].status);
        printf("\n\nO processo T%d vai para a execução na CPU com um tempo de CPU de %d ms", process[posi_fila].id, process[posi_fila].burst);
        //printf("\nExecuta até %d ms", quantum);
        printf("\nTempo de espera: %d\n", init);
        process[posi_fila].burst = process[posi_fila].burst - quantum;        //Descontando o quantum no tempo de execução
        
        if(process[posi_fila].burst <= 0){
            strcpy(process[posi_fila].status, "Finalizado");
            printf("E sai da fila.\t\tStatus: %s\n", process[posi_fila].status);
            //printf("\nE sai da fila.\n");
            count_fila--;
            retorno += process[count_fila].burst;
            init += quantum + process[posi_fila].burst;
        }
        else{
            printf("\nE vai pro final da fila com o tempo de CPU de %d  ms restantes.\n", process[posi_fila].burst);
            retorno - process[posi_fila].burst;
        }

        posi_fila++;                               //Atualiza primeira posição
        if(posi_fila>=n_process){
            posi_fila = 0;
        }    //Faz a rotação
    }
    count_TA = retorno / n_process;
    count_WT += init;
    printf("\n\nTempo médio de rertono: %.2f ms\tTempo médio de espera: %.2f ms\n\n", count_TA, count_WT);

    printf("\n\n_____________________________________________________________________________________________\n");

};

//Para CPU 1
void CPU_1(struct BCP process[], int posicao){
    
    //Para processos I/O bound
    if(strcmp(process[posicao].tipo_process, "I/O bound") == 0 &&  process[posicao].burst == 0){
        printf("\n\nProcesso T%d em execução na CPU 1 para finalizar\n", process[posicao].id);
        strcpy(process[posicao].status, "Finalizado");
        printf("\n\nProcesso T%d\tStatus: %s\n\n", process[posicao].id, process[posicao].status);
    }
    if(strcmp(process[posicao].tipo_process, "I/O bound") == 0 &&  process[posicao].burst > 0){
        dispositivo(process, posicao);
    }

    //Para processos CPU bound
    if(strcmp(process[posicao].tipo_process, "CPU bound") == 0 && strcmp(process[posicao].status, "Pronto") == 0 ){
        strcpy(process[posicao].status, "Execução");
        printf("\n\nProcesso T%d em execução na CPU 1\tStatus: %s\n\n", process[posicao].id, process[posicao].status);
        strcpy(process[posicao].status, "Finalizado");
        printf("\n\nProcesso T%d\tStatus: %s\n\n", process[posicao].id, process[posicao].status);
    }
};


