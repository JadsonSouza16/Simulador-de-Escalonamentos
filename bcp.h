/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
*/

#ifndef BCP_H
#define BCP_H

// Estrutura para o bcp dos processos

struct BCP{
    int id;                   //Identifição do processo                          
    int prioridade;           //Prioridade do processo
    int burst;           //Tempo na cpu ou/Tempo de I/O
    int temp_cheg;           //Tempo de chegada
    char tipo_process[15];       //Tipo de processo (CPU bound/ I/0 bound)
    char status[15];         //Estados do processos

    struct BCP *process_prox;
};

#endif
