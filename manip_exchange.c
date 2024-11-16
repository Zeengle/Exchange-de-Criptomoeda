#include "manip_exchange.h"

// Função que mostra o saldo do usuário
void consultarsaldo(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  printf("|------------------------------------------------[Saldo]-------------"
         "----------------------------------|\n");
  printf("Nome: %s\n", pessoas[usuariologado].nome);
  printf("CPF: ");
  printarcpf(pessoas[usuariologado].CPF);
  printf("\nReais: %.2f", pessoas[usuariologado].reais);
  for(int i=0; i<quantidade; i++){
    printf("\n%s: %.2f", moedas[i].nome, moedas[i].carteiras[usuariologado]);
  }
  printf("\n");
  espera();
  limpaterminal();
}

// Função que mostra as transações realizadas pelo usuário com data, hora,
// valor, moeda e seu saldo resumido
void consultarextrato(pessoa pessoas[], int usuariologado) {
  printf("|------------------------------[Extrato]-----------------------------"
         "-\n");
  printf("%-18s\t%-6s\t%-10s\t%-6s\t%-6s\t%-12s",
         "DATA/HORA", "SINAL", "VALOR", "MOEDA", "TAXA", "QUANT MOEDA\n");
  for (int i = 0; i < 100; i++) {
    if (pessoas[usuariologado].ext[i][0] != '\0') {
      printf("%s\n", pessoas[usuariologado].ext[i]);
    }
  }
  espera();
  limpaterminal();
}

// Função que realiza o depósito de dinheiro na conta do usuário
void depositar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  float depositado = 0;
  printf("|------------------------------------------------[Depositar]---------"
         "---------------------------------------| \n");
  printf(
  "Você possui %.2f reais\n",
  pessoas[usuariologado].reais);
  printf("Quantos reais deseja depositar?\n");
  scanf("%f", &depositado);
  if (depositado < 0) {
    limpabuffer();
    printf("Valor Inválido\n");
    espera();
    menu(pessoas, moedas, usuariologado, quantidade);
  }
  verificacao(pessoas, usuariologado);
  pessoas[usuariologado].reais += depositado;
  consultarsaldo(pessoas, moedas, usuariologado, quantidade);
  criaextrato(pessoas, moedas, usuariologado, '+', depositado, "REAIS", 0, pessoas[usuariologado].reais);
}

// Função que realiza o saque de dinheiro da conta do usuário
void sacar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  float sacado = 0;
  printf("|------------------------------------------------[Sacar]-------------"
         "-----------------------------------| \n");
  printf(
      "Você possui %.2f reais para ser sacados \nQuantos reais deseja sacar?\n",
      pessoas[usuariologado].reais);
  scanf("%f", &sacado);
  if (sacado < 0) {
    limpabuffer();
    printf("Valor Inválido\n");
    espera();
    menu(pessoas, moedas, usuariologado, quantidade);
  }
  verificacao(pessoas, usuariologado);
  if (sacado <= pessoas[usuariologado].reais) {
    pessoas[usuariologado].reais -= sacado;
    consultarsaldo(pessoas, moedas, usuariologado, quantidade);
    criaextrato(pessoas, moedas, usuariologado, '-', sacado, "REAIS", 0, pessoas[usuariologado].reais);
  } else {
    printf("Impossível sacar este valor.\n");
    espera();
    menu(pessoas, moedas, usuariologado, quantidade);
  }
}

//Função que permite a compra de criptomoedas pelo usuário
void comprar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  int escolha;
  printf("|------------------------------------------------[Comprar Cripto]------------------------------------------------|\n");
    puts("Cotação das moedas: ");
    for(int i = 0; i < quantidade; i++){
        printf("%s: %.2f \n", moedas[i].nome, moedas[i].cotacao);
    }
    printf("\n");

    puts("Digite o numero da moeda que deseja comprar, começando por 1: ");
    scanf("%d", &escolha);
    escolha--;
    float qtd_compra;

    if(escolha >= 0 && escolha < quantidade){
        printf("Digite a quantidade de %s que deseja comprar com taxa: %.2f ? \n", moedas[escolha].nome, moedas[escolha].taxa_compra);
        scanf("%f", &qtd_compra);
        float compra = qtd_compra * moedas[escolha].cotacao;
        float taxa = compra * moedas[escolha].taxa_compra;
        if(qtd_compra <=0){
            limpabuffer();
            printf("Quantidade inválida, tente novamente");
            espera();
            menu(pessoas, moedas, usuariologado, quantidade);
        }else{
            verificacao(pessoas, usuariologado);
            if(roundf((pessoas[usuariologado].reais - (compra + taxa)) * 100.00) / 100.00 >= 0){
              moedas[escolha].carteiras[usuariologado] += qtd_compra; // adiciona os bitcoins comprados
              pessoas[usuariologado].reais -= (compra + taxa); // faz a taxação na cotação e adiciona nos reais
              criaextrato(pessoas, moedas, usuariologado, '+', compra, moedas[escolha].nome, moedas[escolha].taxa_compra, moedas[escolha].carteiras[usuariologado]);
              recibocompra(compra, taxa);
              consultarsaldo(pessoas, moedas, usuariologado, quantidade);
            }else{
              recibocompra(compra, taxa);
              printf("Você não possui reais necessarios para comprar essa quantia\n");
              espera();
            }
        }
    }else{
        limpabuffer();
        puts("Opção inválida, tente novamente");
        espera();
        menu(pessoas, moedas, usuariologado, quantidade);
      }
  limpaterminal();
}

// Função que permite a venda de criptomoedas pelo usuário
void vender(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  int escolha;

  printf("|------------------------------------------------[Vender Cripto]------------------------------------------------| \n");
  puts("Cotação das moedas: ");
    for(int i = 0; i<quantidade; i++){
      printf("%s: %.2f \n", moedas[i].nome, moedas[i].cotacao);
    }
    printf("\n");
  puts("Moedas que possui: ");
  for(int i=0; i<quantidade; i++){
    printf("\n%s: %.2f", moedas[i].nome, moedas[i].carteiras[usuariologado]);
  }

    puts("Digite o numero da moeda que deseja vender, começando por 1: ");
    scanf("%d", &escolha);
    escolha--;
    float qtd_venda;
    
    if(escolha >= 0 && escolha < quantidade){
        printf("Digite a quantidade de %s que deseja vender com taxa: %.2f ? \n", moedas[escolha].nome, moedas[escolha].taxa_compra);
        scanf("%f", &qtd_venda);
        float venda = qtd_venda * moedas[escolha].cotacao;
        float taxa = (qtd_venda * moedas[escolha].cotacao * moedas[escolha].taxa_venda);
        if(qtd_venda <=0){
            limpabuffer();
            printf("Quantidade inválida, tente novamente");
            espera();
            menu(pessoas, moedas, usuariologado, quantidade);
        }else{
            verificacao(pessoas, usuariologado);
            if(moedas[escolha].carteiras[usuariologado] - qtd_venda >=0){
              moedas[escolha].carteiras[usuariologado] -= qtd_venda;
              pessoas[usuariologado].reais += (venda - taxa); 
              criaextrato(pessoas, moedas, usuariologado, '-', venda, moedas[escolha].nome, moedas[escolha].taxa_venda, moedas[escolha].carteiras[usuariologado]);
              recibovenda(venda, taxa);
              consultarsaldo(pessoas, moedas, usuariologado, quantidade);
            }else{
              recibovenda(venda, taxa);
              printf("Você não possui a quantidade de moedas necessarias para vender essa quantia\n");
              espera();
            }
        }
    }else{
        limpabuffer();
        puts("Opção inválida, tente novamente");
        espera();
        menu(pessoas, moedas, usuariologado, quantidade);
      }
  limpaterminal();
}

// Função que atualizar cotações
void atualizar(pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  srand(time(NULL));

    for(int i=0; i<quantidade; i++){
      float variacao = moedas[i].cotacao * (((rand() % 10) - 5.00) / 100.00); // Cria o valor que vai ser aumentado ou não (+/-5%)
      variacao = roundf(variacao * 100.00) / 100.00; // Arredondanda a variação pra 2 dígitos
      moedas[i].cotacao = roundf((moedas[i].cotacao + variacao) * 100.00) / 100.00; // Soma na nova cotação
    }

  printf("|------------------------------[Atualizando as cotações]------------------------------| \n");
  for(int i=0; i<quantidade; i++){
    printf("%s: %.2f \n", moedas[i].nome, moedas[i].cotacao);
  }
  printf("|-------------------------------------------------------------------------------------| \n");
  espera();
  menu(pessoas, moedas, usuariologado, quantidade);
}

// Função que permite o acesso do usuario a sua conta
void login(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  char cpflogin[12];
  char senhalogin[7];

  printf("|------------------------------[Login]------------------------------|"
         "\n");
  printf("Digite o CPF: ");
  scanf("%s", cpflogin);

  if (strlen(cpflogin) != 11) {
    printf("CPF inválido!\n");
    limpabuffer();
    espera();
    limpaterminal();
    menuinicial(pessoas, moedas, usuariologado, quantidade);
  }
  limpabuffer();

  for (int i = 0; i < 10; i++) {
    if (strcmp(cpflogin, pessoas[i].CPF) == 0) {
      printf("Digite sua senha: ");
      scanf("%s", senhalogin);
      if (strlen(senhalogin) != 6) {
        printf("Senha inválida!\n");
        limpabuffer();
        espera();
        menuinicial(pessoas, moedas, usuariologado, quantidade);
      }
      limpabuffer();
      if (strcmp(senhalogin, pessoas[i].senha) == 0) {
        printf("Logado com sucesso\n");
        usuariologado = i;
        espera();
        menu(pessoas, moedas, usuariologado, quantidade);
        return;
      } else {
        printf("Senha incorreta\n");
        espera();
        menuinicial(pessoas, moedas, usuariologado, quantidade);
        return;
      }
    }
  }
  printf("CPF não cadastrado!\n");
  espera();
  menuinicial(pessoas, moedas, usuariologado, quantidade);
}

// Função que permite o cadastro de um novo usuário
void cadastrar(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  char cpfcadastro[12];
  char senhacadastro[7];
  int cadastrados = 0;

  printf("|------------------------------[Cadastro]----------------------------"
         "|\n");
  if (cadastrados == 9) {
    printf("Limite de cadastro atingido!\n");
    espera();
    menuinicial(pessoas, moedas, usuariologado, quantidade);
    return;
  } else {
    printf("Digite seu CPF (Só pode possuir 11 dígitos): ");
    scanf("%s", cpfcadastro);
    if (strlen(cpfcadastro) != 11) {
      printf("CPF inválido\n");
      limpabuffer();
      espera();
      menuinicial(pessoas, moedas, usuariologado, quantidade);
      return;
    }
    limpabuffer();
    for (int i = 0; i < 10; i++) {
      if ((strcmp(cpfcadastro, pessoas[i].CPF) == 0)) {
        printf("CPF já cadastrado\n");
        espera();
        menuinicial(pessoas, moedas, usuariologado, quantidade);
        return;
      } else if ((strlen(cpfcadastro) != 11) ||
                 (verificaCPF(cpfcadastro) == 0)) {
        printf("CPF inválido!\n");
        espera();
        menuinicial(pessoas, moedas, usuariologado, quantidade);
        return;
      } else if (pessoas[i].CPF[0] == '\0') {
        printf("Digite sua senha (numérica com 6 dígitos): ");
        scanf("%s", senhacadastro);
        if (strlen(senhacadastro) != 6) {
          limpabuffer();
          printf("Senha inválida\n");
          espera();
          menuinicial(pessoas, moedas, usuariologado, quantidade);
          return;
        }
        limpabuffer();
        if (strlen(senhacadastro) == 6) {
          strcpy(pessoas[i].CPF, cpfcadastro);
          strcpy(pessoas[i].senha, senhacadastro);
          while(1){
            printf("Digite seu nome: ");
            fgets(pessoas[i].nome, 100, stdin);
            size_t len = strlen(pessoas[i].nome);
            if (len > 0 && pessoas[i].nome[len - 1] == '\n') {
              pessoas[i].nome[len - 1] = '\0';
            }
            
            if (strlen(pessoas[i].nome) < 5) {
              printf("Nome inválido (DEVE POSSUIR 5 LETRAS), tente novamente!\n");
            }else{
              break;
            }
          }
          pessoas[i].reais = 0.00;
          for(int j = 0; j< quantidade; j++){
            moedas[j].carteiras[i] = 0.00;
          }
          cadastrados += 1;
          printf("Cadastro realizado com sucesso!\n");
          espera();
          menuinicial(pessoas, moedas, usuariologado, quantidade);
          return;
        } else {
          printf("Senha inválida. Deve ter 6 dígitos.\n");
          espera();
          menuinicial(pessoas, moedas, usuariologado, quantidade);
          return;
        }
      }
    }
  }
}

/*---------------------------------------MENUS----------------------------------------*/
// Funções da "interface do programa"

// Mostra as opções iniciais do programa
void menuinicial(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  char opc;
  while (1) {
    printf(" |---------------[Menu Inicial]---------------| \n");
    printf(" | [1] Cadastro                               | \n");
    printf(" | [2] Login como USUARIO                     | \n");
    printf(" | [3] Sair                                   | \n");
    printf(" |--------------------------------------------| \n");
    printf(" Digite a opção: ");
    scanf(" %c", &opc);
    getchar();

    switch (opc) {
    case '1':
      cadastrar(pessoas, moedas, usuariologado, quantidade);
      return;
    case '2':
      login(pessoas, moedas, usuariologado, quantidade);
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

// Mostra as opções que usuário pode executar quando logado
void menu(pessoa pessoas[],  moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  char opc;
  while (1) {
    printf(" |------------------------------------------------| \n");
    printf("   Bem-vindo, %s\n", pessoas[usuariologado].nome);
    printf(" |----------------[Menu de opções]----------------|\n");
    printf(" | Aperte [1] para consultar saldo                |\n");
    printf(" | Aperte [2] para consultar extrato              |\n");
    printf(" | Aperte [3] para depositar                      |\n");
    printf(" | Aperte [4] para sacar                          |\n");
    printf(" | Aperte [5] para comprar moedas                 |\n");
    printf(" | Aperte [6] para vender moedas                  |\n");
    printf(" | Aperte [7] para atualizar cotação              |\n");
    printf(" | Aperte [8] para voltar ao menu principal       |\n");
    printf(" |------------------------------------------------|\n");
    printf(" Digite a opção: ");
    scanf(" %c", &opc);
    getchar();
    switch (opc) {
    case '1':
      consultarsaldo(pessoas, moedas, usuariologado, quantidade);
      break;
    case '2':
      consultarextrato(pessoas, usuariologado);
      break;
    case '3':
      depositar(pessoas, moedas, usuariologado, quantidade);
      break;
    case '4':
      sacar(pessoas, moedas, usuariologado, quantidade);
      break;
    case '5':
      comprar(pessoas, moedas, usuariologado, quantidade);
      break;
    case '6':
      vender(pessoas, moedas, usuariologado, quantidade);
      break;
    case '7':
      atualizar(pessoas, moedas, usuariologado, quantidade);
      break;
    case '8':
      menuinicial(pessoas, moedas, usuariologado, quantidade);
      break;
    default:
      printf(" Opção inválida, tente novamente\n");
      break;
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

// ARRUMAR-=-----------------------------------
// Responsável por adicionar uma transação no extrato do usuário
void criaextrato(pessoa pessoas[], moeda *moedas, int usuariologado, char sinal, float valor,
                 char moeda[6], float taxa, float carteira) {
  char extrato[100];
  time_t t = time(NULL);         // Pega o horário atual
  struct tm tm = *localtime(&t); // Serve pra pegar cada informação das datas

  snprintf(extrato, sizeof(extrato),
           "[%02d/%02d/%04d "
           "%02d:%02d]\t%-6c\t%-10.2f\t%-6s\t%-6.2f\t%-12.2f",
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min,
           sinal, valor, moeda, taxa, carteira);

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