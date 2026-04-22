#include <stdio.h>
#include "limpa_buffer.h"
#include "aluno.h"

int Remover_aluno(Aluno alunos[],int qntd){
    
  if(qntd!=0){
    int opcao = 0;
    Listar_alunos(alunos,qntd);

    printf(" \n Selecione uma das opções para remover o aluno: ");
    scanf("%d",&opcao);
    limpa_buffer();

    int ii = opcao-1; //Representa o índice

    if (ii!=(qntd-1)){
      Aluno temp = alunos[qntd-1];
      alunos[qntd-1] = alunos[ii];
      alunos[ii] = temp;
    }

    --qntd;  
    printf(" \n\nAluno(a) removido com sucesso!\n\n");
    return qntd;
  }else{
    printf(" \n\nNão existem alunos cadastrado.\n\n");
    return 0;
  }
}