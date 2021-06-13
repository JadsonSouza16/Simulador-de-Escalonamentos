/*Integrantes:
Jadson Silva Souza - 11721EMT017
Rafael Marques Borges Pacheco - 11721EMT019
Vitor Vieira Ferreira - 11721EMT005
*/

#include <stdio.h>
#include <stdlib.h>

#include "bcp.h"
#include "fcfs.h"
#include "prioridade.h"
#include "round_robin.h"
#include "SJF.h"

#ifndef RECURSO_H
#define RECURSO_H

void escalonador(int tipo, struct BCP process[], int n_process){

  if(tipo==1){
    fcfs(process, n_process);
  }
  if(tipo==2){
    prioridade(process,n_process);
  }
  if(tipo==3){
    rr(process,n_process);
  }
  if(tipo==4){
    SJF(process,n_process);
  }
};

#endif