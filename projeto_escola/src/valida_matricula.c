#include <stdio.h>
#include <stdbool.h>
#include "valida_matricula.h"

bool valida_matricula (long long matricula){
  
  if(matricula<=0){
    return false;
  }else{
    return true;
  }
}
