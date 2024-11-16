#include "manip_admin.h"

// Mostra as opções iniciais do programa
void menu_inicial_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  char opc;
  while (1) {
    printf(" |---------------[Menu Inicial]---------------| \n");
    printf(" | [1] Cadastro                               | \n");
    printf(" | [2] Login como ADMINISTRADOR               | \n");
    printf(" | [3] Sair                                   | \n");
    printf(" |--------------------------------------------| \n");
    printf(" Digite a opção: ");
    scanf(" %c", &opc);
    getchar();

    switch (opc) {
    case '1':
      return;
    case '2':
      return;
    case '3':
      escrever(pessoas, moedas, quantidade);
      exit(0);
      return;
    default:
      printf(" Opção inválida, tente novamente\n");
      break;
    }
  }
}

// Função do menu de escolhas do administrador
void menu_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  int esq = 0, selecao;
   puts(" |------------------[Menu ADM]------------------|");
   puts(" |  Olá Administrador!                          |");
   puts(" |  [0] Voltar                                  |");
   puts(" |  [1] Cadastrar investidor                    |");
   puts(" |  [2] Excluir investidor                      |");
   puts(" |  [3] Cadastro de criptomoeda                 |");
   puts(" |  [4] Excluir criptomoeda                     |");
   puts(" |  [5] Consultar saldo de um investidor        |");
   puts(" |  [6] Consultar extrato de um investidor      |");
   puts(" |  [7] Atualizar cotação de criptomoedas       |");
   puts(" |----------------------------------------------|");

  while(!esq){
    printf("Escolha uma opção: \n");
    scanf("%d", &selecao);

    switch(selecao){
      case 0:
          menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
          return;
      case 1:
          break;
      case 2:
          break;
      case 3:
          break;
      case 4:
          break;
      case 5:
          break;
      case 6:
          break;
      case 7:
          break;
      default:
          puts("Opção Inválida, tente novamente");
    }
  }
}

/*---------------------------------FUNÇÕES
 * AUXILIARES---------------------------------*/

// Função que limpa o termina independente do sistema operacional
void limpaterminal() { system("cls || clear")
  /*printf("teste")*/;
}

// Função que espera a ação do usuário para dar prosseguimento
void espera() {
  printf("Aperte ENTER para SAIR!\n");
  limpabuffer();
}

//Função de verificar o cpf
int verificaCPF(char *cpf) {
  int numeros_cpf[11];
  int soma = 0;
  int maxv1 = 10;
  int maxv2 = 11;
  int resto = 0;
  int veri = 0;
  int verificador1 = 0, verificador2 = 0;
  for (int i = 0; i < 11; i++) {
    numeros_cpf[i] = cpf[i] - 48;
  }
  for (int i = 0; i < 11; i++) {
    // implementação da verificação de cpfs com todos os digitos iguais
    if (numeros_cpf[i] == numeros_cpf[0]) {
      veri += 1;
    }
  }
  if (veri == 11) {
    return 0;
  } else {

    for (int i = 0; i < 9; i++) {
      soma += numeros_cpf[i] * maxv1;
      maxv1--;
    }

    resto = soma % 11;

    if (resto == 1 || resto == 0) {
      verificador1 = 0;
    } else {
      verificador1 = 11 - resto;
    }
    soma = 0;

    for (int i = 0; i < 10; i++) {
      soma += numeros_cpf[i] * maxv2;
      maxv2--;
    }

    resto = soma % 11;
    if (resto == 1 || resto == 0) {
      verificador2 = 0;
    } else {
      verificador2 = 11 - resto;
    }

    if (verificador1 == numeros_cpf[9] && verificador2 == numeros_cpf[10]) {
      return 1;
    } else {
      return 0;
    }
  }
}

// Limpa o buffer do teclado
void limpabuffer() {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  return;
}

// Função que imprime o cpf do usuário
void printarcpf(char *cpf) {
  for (int i = 1; i < 12; i++) {
    if (i % 3 == 0 && i != 1 && i != 9) {
      printf("%c.", cpf[i - 1]);
    } else if (i == 9) {
      printf("%c-", cpf[i - 1]);
    } else {
      printf("%c", cpf[i - 1]);
    }
  }
  printf("\n");
}

// Responsável por adicionar uma transação no extrato do usuário
void criaextrato(pessoa pessoas[], int usuariologado, char sinal, float valor,
                 char moeda[6], float taxa) {
  char extrato[100];
  time_t t = time(NULL);         // Pega o horário atual
  struct tm tm = *localtime(&t); // Serve pra pegar cada informação das datas

  snprintf(extrato, sizeof(extrato),
           "[%02d/%02d/%04d "
           "%02d:%02d]\t%-6c\t%-10.2f\t%-6s\t%-6.2f\t%-12.2f\t%-12.2f\t%-12."
           "2f\t%-12.2f\n",
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min,
           sinal, valor, moeda, taxa, pessoas[usuariologado].reais,
           pessoas[usuariologado].reais, pessoas[usuariologado].reais,
           pessoas[usuariologado].reais);

  // Procura uma linha vazia no extrato
  for (int i = 0; i < 100; i++) {
    if (pessoas[usuariologado].ext[i][0] == '\0') {
      strcpy(pessoas[usuariologado].ext[i], extrato);
      break;
    }
  }
}

// Mostra o total de uma compra de cripto realizada pelo usuário 
void recibocompra(float compra, float taxa) {
  printf("|-----------------------[Recibo Compra]-----------------------| \n");
  printf("Total da compra: \n");
  printf("COMPRA + TAXA = TOTAL \n");
  printf("%.2f + %.2f = %.2f \n", compra, taxa, compra + taxa);
}

// Mostra o total de uma venda de cripto realizada pelo usuário 
void recibovenda(float conversao, float taxa) {
  printf("|-----------------------[Recibo Venda]-----------------------| \n");
  printf("Total da venda: \n");
  printf("VENDA - TAXA = TOTAL \n");
  printf("%.2f - %.2f = %.2f \n", conversao, taxa, conversao - taxa);
}

// Responsável por pedir a senha do usuario ao realizar transações
void verificacao(pessoa pessoas[], int usuariologado) {
  while (1) {
    char senha[100];
    printf("Digite sua senha: ");
    scanf("%s", senha);
    if (strcmp(pessoas[usuariologado].senha, senha) == 0) {
      break;
    } else {
      printf("Senha inválida. Tente novamente\n");
    }
  }
  limpabuffer();
  return;
}

// Escreve o arquivo binário
void escrever(pessoa *pessoas, moeda *moedas, int *quantidade) {
  FILE *file = fopen("dados.bin", "wb");

  fwrite(&quantidade, sizeof(int), 1, file);
  fwrite(pessoas, sizeof(pessoa), 10, file);
  fwrite(moedas, sizeof(moeda), quantidade, file);

  fclose(file);
}

// Lê as informações e as atribui a variáveis
void ler(FILE *file, pessoa *pessoas, moeda **moedas, int *quantidade) {
  file = fopen("dados.bin", "rb");

  fread(quantidade, sizeof(int), 1, file); 
  fread(pessoas, sizeof(pessoa), 10, file);

  *moedas = malloc(*quantidade * sizeof(moeda));

  fread(*moedas, sizeof(moeda), *quantidade, file);

  fclose(file);
}

// Verifica se o arquivo deve ser escrito ou lido
int arquivoexiste(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    fclose(file);
    return 1;
  }
  return 0;
}