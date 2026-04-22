#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "limpa_buffer.h"
#include "menu_atualizar.h"
#include "valida_nome.h"
#include "valida_sexo.h"
#include "valida_nascimento.h"
#include "aluno.h"

void Atualizar_aluno(Aluno alunos[], int qntd)
{

  long long matricula;
  bool mat_encontrada = false;
  int ii = -1;
  int opcao;

  if (qntd == 0){
    printf("\n\nNão existem alunos cadastrados.\n\n");
    return;
  }

  // BUSCA PELA MATRÍCULA
  do{
    printf(" Informe a matrícula: ");
    scanf("%lld", &matricula);
    limpa_buffer();

    for (int i = 0; i < qntd; i++){
      if (alunos[i].matricula == matricula){
        mat_encontrada = true;
        ii = i;
        break;
      }
    }

    if (!mat_encontrada){
      printf(" Matrícula não encontrada!\n\n");
    }

  } while (!mat_encontrada);

  // MENU DE ATUALIZAÇÃO
  menu_atualizar();
  scanf("%d", &opcao);
  limpa_buffer();

  switch (opcao)
  {

  // ================= NOME =================
  case 1:
  {
    bool nome_valido = false;

    do
    {
      printf(" Informe o novo nome: ");
      fgets(alunos[ii].nome, sizeof(alunos[ii].nome), stdin);
      alunos[ii].nome[strcspn(alunos[ii].nome, "\n")] = '\0';

      int tam = strlen(alunos[ii].nome);
      nome_valido = valida_nome(alunos[ii].nome, tam);

      if (!nome_valido){
        printf(" Nome inválido!\n\n");
      }

    } while (!nome_valido);

    printf(" Nome atualizado com sucesso!\n\n");
    break;
  }

  // ================= SEXO =================
  case 2:
  {
    bool sexo_valido = false;

    do
    {
      printf(" Informe o novo sexo (M/F): ");
      scanf(" %c", &alunos[ii].sexo);
      limpa_buffer();

      sexo_valido = valida_sexo(alunos[ii].sexo);

      if (!sexo_valido){
        printf(" Sexo inválido!\n\n");
      }

    } while (!sexo_valido);

    printf(" Sexo atualizado com sucesso!\n\n");
    break;
  }

  // ================= NASCIMENTO =================
  case 3:
  {
    bool nasc_valido = false;

    printf(" Atualizar data de nascimento:\n\n");

    do
    {
      printf(" Dia: ");
      scanf("%d", &alunos[ii].nascimento.dia);
      limpa_buffer();

      printf(" Mês: ");
      scanf("%d", &alunos[ii].nascimento.mes);
      limpa_buffer();

      printf(" Ano: ");
      scanf("%d", &alunos[ii].nascimento.ano);
      limpa_buffer();

      nasc_valido = valida_nascimento(alunos[ii].nascimento.dia,alunos[ii].nascimento.mes,alunos[ii].nascimento.ano);

      if (!nasc_valido){
        printf(" Data inválida!\n\n");
      }

    } while (!nasc_valido);

    printf(" Data atualizada com sucesso!\n\n");
    break;
  }

  default:
    printf(" Opção inválida!\n\n");
  }
}