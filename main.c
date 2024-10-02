#include "manip_exchange.h"


/*---------------------------------------MAIN----------------------------------------*/

int main() {
    FILE *file;
    pessoa pessoas[10];
    float cotacaoBTC = 100;
    float cotacaoETH = 50;
    float cotacaoXRP = 25;
    int usuariologado = -1;

    int verificacao = arquivoexiste("dados.bin");

    if(verificacao == 0){ // O arquivo existe
        escrever(pessoas, 10, cotacaoBTC, cotacaoETH, cotacaoXRP);
    }else{
        ler(&file, pessoas, 10, &cotacaoBTC, &cotacaoETH, &cotacaoXRP);
    }
    menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
    return 0;
}
