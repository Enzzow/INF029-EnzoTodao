#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "valida_sexo.h"

bool valida_sexo(char sexo){
   
    sexo = toupper(sexo);

    if (sexo!='M' && sexo!='F'){
      return false;
    }else{
      return true;
    }

}