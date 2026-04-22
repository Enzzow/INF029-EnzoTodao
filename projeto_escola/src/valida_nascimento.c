#include <stdio.h>
#include <stdbool.h>
#define ANO_ATUAL 2026
#include "aluno.h"
#include "valida_nascimento.h"

bool valida_nascimento(int dia, int mes, int ano){

  bool ano_bissexto = false;
  if ( ((ano%4)==0 && (ano%100)!=0) || (ano%400)==0 ){
    ano_bissexto = true;
  }

  if (ano<=0 || ano>ANO_ATUAL){
   return false; 
  }
  
  if (mes<=0 || mes>12){
   return false;
  }  
  

  if (dia<=0){
   return false;
  }else
  {
    if (mes==4||mes==6||mes==9||mes==11){
      if (dia<=30){
        return true;
      }
    }

    if (mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
      if (dia<=31){
        return true;
      }
    }

    if (mes==2 && ano_bissexto){
      if (dia<=29){
        return true;
      }else{
        return false;
      }
    }

    if (mes==2 && !ano_bissexto){
      if (dia<=28){
        return true;
      }else{
        return false;
      }
    }
  }
  return false;
}