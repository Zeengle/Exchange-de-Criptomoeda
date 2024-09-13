
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "manip_exchange.h"

typedef struct { // Struct com as informações das pessoas
    char CPF[12]; 
    char senha[7];  
    char nome[100];
    float reais;
    float btc;
    float eth;
    float xrp;
    char ext[100][100];
} pessoa;

typedef struct { // Struct com as cotações das moedas
    float cotacaoBTC;
    float cotacaoETH;
    float cotacaoXRP;
} Moedas;

pessoa pessoas[10];
Moedas moedas = {100.0, 50.0, 25.0};


int main() {
    menuinicial();
    return 0;
}
