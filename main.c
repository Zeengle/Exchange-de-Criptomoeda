#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>//para usar o toupper nas escolhas
#include "manip_exchange.h"
#include <math.h>

int main() {
    pessoa pessoas[10];
    float cotacaoBTC = 100;
    float cotacaoETH = 50;
    float cotacaoXRP = 25;
    int usuariologado = -1;
    menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
    return 0;
}
