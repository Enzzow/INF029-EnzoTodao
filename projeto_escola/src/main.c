#include <stdio.h>
#include <stdbool.h>
#include "limpa_buffer.h"
#include "aluno.h"
#include "menu_principal.h"
#include "valida_opcao_principal.h"

int main(){

  Aluno alunos[100];
  int qntd_alunos = 0;

  bool executando = true;

  do{

    int opcao_inicial = 0;

    int opcao_aluno = 0;

    menu_principal();
    scanf("%d", &opcao_inicial);

    limpa_buffer();

    executando = valida_opcao_principal(opcao_inicial);

    if (executando){
      switch (opcao_inicial){
        case 1:
         menu_aluno();
         scanf("%d", &opcao_aluno);
         limpa_buffer();
         break;

        case 2:
         printf("\n\n Em desenvolvimento...\n\n");
         break;

        case 3:
         printf("\n\n Em desenvolvimento...\n\n");
         break;
      }

      if (opcao_inicial == 1){
        switch (opcao_aluno){
          case 1:
           qntd_alunos = Cadastrar_aluno(alunos, qntd_alunos);
           break;
          
          case 2:
           Listar_alunos(alunos,qntd_alunos);
           break;
          
          case 3:
           Atualizar_aluno(alunos, qntd_alunos);
           break;
          
          case 4:
          
           qntd_alunos = Remover_aluno(alunos,qntd_alunos);
           break;
          
          case 5:
           printf("\n\n Voltando para o menu principal...\n\n");
           break;
          
          default:
           printf(" \n\nOpção inválida!\n\n");
           break;
        }
      }
    }

  } while (executando);

  return 0;
}