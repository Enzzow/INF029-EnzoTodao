#include <stdio.h>
#include "aluno.h"

void Listar_alunos(Aluno alunos[],int qntd){
  
  if(qntd==0){
    printf("\n\n Não existem alunos cadastrados.\n\n");
  }else{
   printf(" \n\n Lista de nomes: \n\n");

    Ordena_alunos(alunos,qntd);
    
    for (int i=0; i<qntd ;++i){
      printf("%d- %s\n",i+1,alunos[i].nome);
    }
  }
}