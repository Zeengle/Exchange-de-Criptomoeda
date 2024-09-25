void consultarsaldo(pessoa pessoas[], int usuariologado) {
    printf("|------------------------------------------------[Saldo]-----------------------------------------------|\n");
    printf("Nome: %s\n",pessoas[usuariologado].nome);
    printf("CPF: ");
    printarcpf(pessoas[usuariologado].CPF);
    printf("\nReais: %.2f\nBitcoin: %.2f\nEthereum: %.2f\nRipple: %.2f\n",pessoas[usuariologado].reais, 
           pessoas[usuariologado].btc, pessoas[usuariologado].eth, pessoas[usuariologado].xrp);
    espera();
    limpaterminal();
}

void consultarextrato() {

}

void depositar() {

}

void sacar() {

}

void comprar() {

}

void vender() {

}

void atualizar() {

}

void login(pessoa pessoas[], float cotacaoBTC, float cotacaoETH,float cotacaoXRP, int usuariologado) {
limpaterminal();
  char cpflogin[12];
  char senhalogin[7];

  printf("|------------------------------[Login]------------------------------|"
         "\n");
  printf("Digite o CPF: ");
  scanf("%s", cpflogin);

  if (strlen(cpflogin) != 11) {
    printf("CPF inválido!");
    menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
  }
  limpabuffer();

  for (int i = 0; i < 10; i++) {
    if (strcmp(cpflogin, pessoas[i].CPF) == 0) {
      printf("Digite sua senha: ");
      scanf("%s", senhalogin);
      if (strlen(senhalogin) != 6) {
        printf("Senha inválida!");
        menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      }
      limpabuffer();
      if (strcmp(senhalogin, pessoas[i].senha) == 0) {
        printf("Logado com sucesso\n");
        usuariologado = i;
        espera();
        menu(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
        return;
      } else {
        printf("Senha incorreta\n");
        espera();
        menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
        return;
      }
    }
  }
  printf("CPF não cadastrado!\n");
  espera();
  menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
}

void cadastrar(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado) {
  limpaterminal();
  char cpfcadastro[12];
  char senhacadastro[7];
  int cadastrados = 0;
    
  printf("|------------------------------[Cadastro]----------------------------|\n");
  if (cadastrados == 9) {
    printf("Limite de cadastro atingido!\n");
    espera();
    menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
    return;
  } else {
    printf("Digite seu CPF (Só pode possuir 11 dígitos): ");
    scanf("%s", cpfcadastro);
    if (strlen(cpfcadastro) != 11) {
      printf("CPF inválido");
      menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
    }
    limpabuffer();
    for (int i = 0; i < 10; i++) {
      if ((strcmp(cpfcadastro, pessoas[i].CPF) == 0)) {
        printf("CPF já cadastrado\n");
        espera();
        menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
        return;
      } else if ((strlen(cpfcadastro) != 11) || (verificaCPF(cpfcadastro) == 0)) {
        printf("CPF inválido!\n");
        espera();
        menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
        return;
      } else if (pessoas[i].CPF[0] == '\0') {
        printf("Digite sua senha (numérica com 6 dígitos): ");
        scanf("%s", senhacadastro);
        if (strlen(senhacadastro) != 6) {
          printf("Senha inválida");
          menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
        }
        limpabuffer();
        if (strlen(senhacadastro) == 6) {
          strcpy(pessoas[i].CPF, cpfcadastro);
          strcpy(pessoas[i].senha, senhacadastro);
          printf("Digite seu nome: ");
          fgets(pessoas[i].nome, 100, stdin);
          size_t len = strlen(pessoas[i].nome);
          if (len > 0 && pessoas[i].nome[len - 1] == '\n') {
            pessoas[i].nome[len - 1] = '\0';
          } else if (len < 3) {
            printf("Nome inválido, tente novamente!");
            espera();
            menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
          }
          pessoas[i].btc = 0.00;
          pessoas[i].eth = 0.00;
          pessoas[i].xrp = 0.00;
          pessoas[i].reais = 0.00;
          cadastrados += 1;
          printf("Cadastro realizado com sucesso!\n");
          espera();
          menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
          return;
        } else {
          printf("Senha inválida. Deve ter 6 dígitos.\n");
          espera();
          menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
          return;
        }
      }
    }
  }
}

/*---------------------------------------MENUS----------------------------------------*/
// Funções da "interface do programa"

// Mostra as opções iniciais do programa
void menuinicial(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado) {
  limpaterminal();
  char opc;
  while (1) {
    printf(" |---------------[Menu Inicial]---------------| \n");
    printf(" | [1] Cadastro                               | \n");
    printf(" | [2] Login                                  | \n");
    printf(" | [3] Sair                                   | \n");
    printf(" |--------------------------------------------| \n");
    printf(" Digite a opção: ");
    scanf(" %c", &opc);
    getchar();

    switch (opc) {
    case '1':
      cadastrar(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      return;
    case '2':
      login(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      return;
    case '3':
      escrever(pessoas, 10, cotacaoBTC, cotacaoETH, cotacaoXRP);
      exit(0);
      return;
    default:
      printf(" Opção inválida, tente novamente\n");
      break;
    }
  }
}

// Mostra as opções que usuário pode executar quando logado
void menu(pessoa pessoas[], float cotacaoBTC, float cotacaoETH, float cotacaoXRP, int usuariologado) {
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
      consultarsaldo(pessoas, usuariologado);
      break;
    case '2':
      consultarextrato(pessoas, usuariologado);
      break;
    case '3':
      depositar(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      break;
    case '4':
      sacar(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      break;
    case '5':
      comprar(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      break;
    case '6':
      vender(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      break;
    case '7':
      atualizar(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      break;
    case '8':
      menuinicial(pessoas, cotacaoBTC, cotacaoETH, cotacaoXRP, usuariologado);
      break;
    default:
      printf(" Opção inválida, tente novamente\n");
      break;
    }
  }
}

/*---------------------------------FUNÇÕES AUXILIARES---------------------------------*/

// Função que limpa o termina independente do sistema operacional
void limpaterminal() { system("cls || clear"); }

// Função que espera a ação do usuário para dar prosseguimento
void espera() {
  fflush(stdin);
  printf("Aperte ENTER para SAIR!");
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
    printf("CPF Inválido");
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

//Limpa o buffer do teclado
void limpabuffer() {
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  return;
}
