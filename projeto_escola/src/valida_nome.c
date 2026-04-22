#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "valida_nome.h"

bool valida_nome(char nome[],int tam){
   bool nome_valido = false;

   int qntd_letras = 0;
   int qntd_espacos = 0;


   for (int i=0; i<tam ;++i){
       if (toupper(nome[i])>='A' && toupper(nome[i])<='Z'){
         ++qntd_letras;    
       }

       if (nome[i] == ' '){
         ++qntd_espacos;
       }
   }

   if (qntd_espacos==tam){
     return false;
   }

   if (qntd_espacos==qntd_letras || (qntd_letras-qntd_espacos)==1){
     return false;
   }

   if (qntd_espacos>qntd_letras){
     return false;
   }

  if (qntd_letras>qntd_espacos){
    return true;
  }

   
  return false;
}