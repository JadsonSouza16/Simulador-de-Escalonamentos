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

//Para a CPU 2
void CPU_2(struct BCP process[], int posicao){
    
    //Para processos I/O bound
    if(strcmp(process[posicao].tipo_process, "I/O bound") == 0 &&  process[posicao].burst == 0){
        printf("\n\nProcesso T%d em execução na CPU 2 para finalizar\n", process[posicao].id);
        strcpy(process[posicao].status, "Finalizado");
        printf("\n\nProcesso T%d\tStatus: %s\n\n", process[posicao].id, process[posicao].status);
    }
    if(strcmp(process[posicao].tipo_process, "I/O bound") == 0 &&  process[posicao].burst > 0){
        dispositivo(process, posicao);
    }

    //Para processos CPU bound
    if(strcmp(process[posicao].tipo_process, "CPU bound") == 0 && strcmp(process[posicao].status, "Pronto") == 0 ){
        strcpy(process[posicao].status, "Execução");
        printf("\n\nProcesso T%d em execução na CPU 2\tStatus: %s\n\n", process[posicao].id, process[posicao].status);
        strcpy(process[posicao].status, "Finalizado");
        printf("\n\nProcesso T%d\tStatus: %s\n\n", process[posicao].id, process[posicao].status);
    }
};
