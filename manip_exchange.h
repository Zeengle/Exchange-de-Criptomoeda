#ifndef manip_exchange
#define manip_exchange

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>//para usar o toupper nas escolhas
#include <math.h>

typedef struct {
    char CPF[12];
    char senha[7];  
    char nome[100];
    float reais;
    float btc;
    float eth;
    float xrp;
    char ext[100][100];
} pessoa;

/*---------------------------------------PROTÓTIPOS MENUS---------------------------------------*/

void menu(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void menuinicial(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);

/*---------------------------------PROTÓTIPOS FUNÇÕES PRINCIPAIS---------------------------------*/

void login(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void cadastrar(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void consultarsaldo(pessoa pessoas[], int usuariologado);
void consultarextrato(pessoa pessoas[], int usuariologado);
void depositar(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void sacar(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void comprar(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void vender(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);
void atualizar(pessoa pessoas[],float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado);

/*---------------------------------PROTÓTIPOS FUNÇÕES AUXILIARES---------------------------------*/

void limpaterminal();
void espera();
void limpabuffer();
int verificaCPF(char *cpf);
void printarcpf(char *cpf);
void criaextrato(pessoa pessoas[], int usuariologado, char sinal, float valor, char moeda[6], float taxa);
void verificacao(pessoa pessoas[], int usuariologado);
void recibocompra(float compra, float taxa);
void recibovenda(float conversao, float taxa);
void ler(FILE *file, pessoa pessoas[], int quantidade, float *cotacaoBTC, float *cotacaoETH, float *cotacaoXRP);
void escrever(pessoa pessoas[], int quantidade, float cotacaoBTC, float cotacaoETH, float cotacaoXRP);
int arquivoexiste(const char *filename);

#endif
