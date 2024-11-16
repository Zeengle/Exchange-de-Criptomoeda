#include "manip_admin.h"

int main (){
    FILE *file;
    FILE *file_admin;
    pessoa pessoas[10];
    admins admin[10];
    int quantidade = 3;
    moeda *moedas = NULL;
    int usuariologado = -1;

    int verificacao2 = arquivoexiste("dados.bin");

    if(verificacao2 == 0){ // O arquivo existe
        moedas = malloc(quantidade * sizeof(moeda));
        // valores
        moedas[0].cotacao = 100;
        moedas[1].cotacao = 50;
        moedas[2].cotacao = 25;

        // taxas
        moedas[0].taxa_compra = 0.02;
        moedas[1].taxa_compra = 0.01;
        moedas[2].taxa_compra = 0.01;

        moedas[0].taxa_venda = 0.03;
        moedas[1].taxa_venda = 0.02;
        moedas[2].taxa_venda = 0.01;

        //moedas
        strcpy(moedas[0].nome, "BTC");
        strcpy(moedas[1].nome, "ETH");
        strcpy(moedas[2].nome, "XRP"); 
        escrever(pessoas, moedas, quantidade);
    }else{
        ler(&file, pessoas, &moedas, &quantidade);
    }
    menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);

    free(moedas);
    
    return 0;
}