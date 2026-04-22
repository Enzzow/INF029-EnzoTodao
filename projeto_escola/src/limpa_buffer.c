#include <stdio.h>
#include "limpa_buffer.h"

void limpa_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

