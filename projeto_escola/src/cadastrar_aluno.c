#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "valida_nome.h"
#include "valida_cpf.h"
#include "valida_matricula.h"
#include "valida_sexo.h"
#include "valida_nascimento.h"
#include "aluno.h"
#include "limpa_buffer.h"
#define ANO 2026

int Cadastrar_aluno(Aluno alunos[],int qntd){
  
  printf(" \n\n Cadastro aluno: \n\n");
  
  //SOLICITA O NOME 
  bool nome_valido = false;
 do{  
    printf(" Informe o nome do(a) aluno(a): ");
    fgets(alunos[qntd].nome,sizeof(alunos[qntd].nome),stdin);
  
   //Remove o '\n' da string
   alunos[qntd].nome[strcspn(alunos[qntd].nome, "\n")] = '\0';
   int tam = strlen(alunos[qntd].nome);
   nome_valido = valida_nome(alunos[qntd].nome,tam);


    if(!nome_valido){
      printf("\n\n Nome inválido!\n\n");
    }
  }while(!nome_valido);

  //VERIFICA O CPF
  bool cpf_valido = false;
  do{
    
    printf(" Informe o CPF (SOMENTE NÚMEROS): ");
    fgets(alunos[qntd].cpf, sizeof(alunos[qntd].cpf), stdin);

    alunos[qntd].cpf[strcspn(alunos[qntd].cpf, "\n")] = '\0';

    if(strlen(alunos[qntd].cpf) == 0){
      continue;
    }

    bool cpf_repetido = false;

    
    if (qntd>=1)
    {
      for (int i=0; i<qntd && !cpf_repetido;++i){
        if (strcmp(alunos[i].cpf,alunos[qntd].cpf)==0){
         cpf_repetido = true;
         printf(" CPF já cadastrado!\n\n");
        }
      }
    }
    
    if (!cpf_repetido){
     cpf_valido = valida_cpf(alunos[qntd].cpf);
    }

    if (!cpf_valido){
      printf(" \nCPF inválido!\n\n");
    }
  }while(!cpf_valido);

  //VERIFICA A MATRÍCULA 
  bool matricula_valida = false;

  do{
    bool matricula_repetida = false;
   printf(" Informe o número da matrícula: ");
   scanf("%lld",&alunos[qntd].matricula);
   limpa_buffer();

   if (qntd>=1)
   {
     for (int i=0; i<qntd && !matricula_repetida ;++i){
       if (alunos[i].matricula == alunos[qntd].matricula){
         matricula_repetida = true;
         printf("\n\n Matrícula já cadastrada!\n\n");
       } 
     }
   }
     
    if (!matricula_repetida){ 
     matricula_valida = valida_matricula(alunos[qntd].matricula);
   }

   if(!matricula_valida){
     printf(" \n\n Matrícula inválida! \n\n");
   }
  }while(!matricula_valida);

  //VERIFICA O SEXO 
  bool sexo_valido = false;

  do{
    printf(" Informe o sexo (M/F): ");
    scanf(" %c",&alunos[qntd].sexo);
    limpa_buffer();

   sexo_valido = valida_sexo(alunos[qntd].sexo);

  }while (!sexo_valido);

  //VERIFICA A DATA DE NASCIMENTO
  bool nasc_valido = false;
  printf(" \n\nINFORME SUA DATA DE NASCIMENTO:\n\n");
  do{ 
    printf(" Informe o dia de nascimento: ");
    scanf("%d",&alunos[qntd].nascimento.dia);
    limpa_buffer();

    printf(" Informe o mês de nascimento: ");
    scanf("%d",&alunos[qntd].nascimento.mes);
    limpa_buffer();

    printf(" Informe o ano de nascimento: ");
    scanf("%d",&alunos[qntd].nascimento.ano);
    limpa_buffer();

   nasc_valido = valida_nascimento(alunos[qntd].nascimento.dia,alunos[qntd].nascimento.mes,alunos[qntd].nascimento.ano);
    if (!nasc_valido){
      printf("\n\n Data de nascimento inválida!\n\n");
    }
      
  }while (!nasc_valido);

  printf(" \n\nCadastro realizado com sucesso!\n\n");
  return ++qntd;
}