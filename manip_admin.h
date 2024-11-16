#ifndef manip_admin
#define manip_admin

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

typedef struct{ 
    char cpf[12];
    char senha[7];
    char nome [6];
} admins;

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
void ler(FILE *file, pessoa *pessoas, moeda **moedas, int *quantidade); 
void escrever(pessoa *pessoas, moeda *moedas, int *quantidade); 
int arquivoexiste(const char *filename);

// /*---------------------------------------PROTÓTIPOS MENUS---------------------------------------*/

void menu_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void menu_inicial_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);

// /*---------------------------------------PROTÓTIPOS DOS BINÁRIOS---------------------------------------*/

void escrever_admin(admins admin[]);
void ler_admin(admins admin[] , FILE *file_admin);

/*---------------------------------PROTÓTIPOS FUNÇÕES PRINCIPAIS---------------------------------*/

void cadastro_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void login_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void cadastrar_investidor_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void excluir_investidor_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void cadastrar_criptomoeda(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void excluir_criptomoeda(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void consultar_saldo_adm (admins admin[],pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void consultar_extrato_adm (admins admin[],pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);
void consultarextrato(pessoa pessoas[], int usuariologado);
void atualizar(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade);

#endif
