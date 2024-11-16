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
    char ext[100][100];
} pessoa;

typedef struct{ 
    char nome[4]; 
    float taxa_venda;
    float taxa_compra;
    float cotacao;
    float carteiras[10];
} moeda;


/*---------------------------------------PROTÓTIPOS MENUS---------------------------------------*/

void menu(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void menuinicial(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);

/*---------------------------------PROTÓTIPOS FUNÇÕES PRINCIPAIS---------------------------------*/

void login(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void cadastrar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void consultarsaldo(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void consultarextrato(pessoa pessoas[], int usuariologado);
void depositar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void sacar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void comprar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void vender(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade);
void atualizar(pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);

/*---------------------------------PROTÓTIPOS FUNÇÕES AUXILIARES---------------------------------*/

void limpaterminal();
void espera();
void limpabuffer();
int verificaCPF(char *cpf);
void printarcpf(char *cpf);
void criaextrato(pessoa pessoas[], moeda *moedas, int usuariologado, char sinal, float valor, char moeda[6], float taxa, float carteira);
void verificacao(pessoa pessoas[], int usuariologado);
void recibocompra(float compra, float taxa);
void recibovenda(float conversao, float taxa);
void ler(FILE *file, pessoa *pessoas, moeda **moedas, int *quantidade); 
void escrever(pessoa *pessoas, moeda *moedas, int *quantidade); 
int arquivoexiste(const char *filename);

#endif
