#include <stdio.h>
#include <stdbool.h>
#include "valida_opcao_principal.h"

bool valida_opcao_principal(int opcao){
    switch (opcao){
        case 1:
         printf(" \n\nAcessando portal do aluno...\n\n");
         break;

        case 2:
         printf(" \n\nAcessando portal do professor...\n\n");
         break;

        case 3:
         printf(" \n\nAcessando portal da disciplina...\n\n");
         break;

        case 4:
         printf(" \n\nFim do programa!\n\n");
         return false;

        default:
         printf("\n\n Opção inválida! \n\n");
         break;
    }

    return true;
}