/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "E_S.h"
#include "cpu.h"
#include "cpu_2.h"

//Dispositvo de entrada e saída
void dispositivo(struct BCP process[], int posicao) {

    int block = 2;

    //Adiciona o tempo de bloqueio para o processo voltar para a fila de pronto
    process[posicao].temp_cheg += block;
   
    //Muda o status para bloqueado enquanto vai utilizar o recurso E/S
    strcpy(process[posicao].status, "Bloqueado");

    printf("\n\nProcesso T%d requisitando por dispositivo de entrada e saída\nStatus: %s\n\n", process[posicao].id, process[posicao].status);

    //Consome todo burst
    process[posicao].burst = 0;

    //Muda o status para voltar para a fila de pronto
    strcpy(process[posicao].status, "Pronto");

    printf("\n\nProcesso T%d em execução no recurso de entrada e saída\n\nProcesso T%d voltou para fila de pronto\t\nStatus: %s\n\n", process[posicao].id, process[posicao].id, process[posicao].status);
};