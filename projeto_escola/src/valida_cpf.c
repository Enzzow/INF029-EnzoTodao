#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "valida_cpf.h"

bool valida_cpf(char cpf[])
{
  // 1 - tamanho do CPF
  if (strlen(cpf) != 11){
    return false;
  }

  // 2 - verifica se todos os dígitos são iguais
  bool digitos_iguais = true;

  for (int i = 1; i < 11 && digitos_iguais; i++){
    if (cpf[i] != cpf[0]){
      digitos_iguais = false;
    }
  }

  if (digitos_iguais){
    return false;
  }

  // 3 - cálculo do 1º dígito
  int soma = 0;
  int peso = 10;

  for (int i = 0; i < 9; i++){
    soma += (cpf[i] - '0') * peso;
    peso--;
  }

  int resto = soma % 11;
  int digito1 = (resto < 2) ? 0 : (11 - resto);

  // 4 - cálculo do 2º dígito 
  soma = 0;
  peso = 11;

  for (int i = 0; i < 9; i++){
    soma += (cpf[i] - '0') * peso;
    peso--;
  }

  soma += digito1 * 2;

  int resto2 = soma % 11;
  int digito2 = (resto2 < 2) ? 0 : (11 - resto2);

  // 5 - comparação final
  int d1_original = cpf[9] - '0';
  int d2_original = cpf[10] - '0';

  if (d1_original == digito1 && d2_original == digito2){
    return true;
  }
  else{
    return false;
  }
}