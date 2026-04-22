#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "aluno.h"

void Ordena_alunos(Aluno alunos[], int qntd){

 //ESSA FUNÇÃO ORDENA OS NOMES POR ORDEM ALFABÉTICA
  

  for (int i=0; i<(qntd-1) ;++i)
  {
    for (int j=i+1; j<qntd ;++j)
    {
      if (strcmp(alunos[i].nome,alunos[j].nome)>0){
        Aluno temp = alunos[i];
        alunos[i] = alunos[j];
        alunos[j] = temp;
      }
    }  
  }
}