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
        cadastro_adm(admin, pessoas, moedas, usuariologado, quantidade);
        return;
    case '2':
        login_adm(admin, pessoas, moedas, usuariologado, quantidade);
        return;
    case '3':
      escrever(pessoas, moedas, quantidade);
      escrever_admin(admin);
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
          cadastrar_investidor_adm(admin, pessoas, moedas, usuariologado, quantidade);
          break;
      case 2:
          excluir_investidor_adm(admin, pessoas, moedas, usuariologado, quantidade);
          break;
      case 3:
          cadastrar_criptomoeda(admin, pessoas, moedas, usuariologado, quantidade);
          break;
      case 4:
          excluir_criptomoeda(admin, pessoas, moedas, usuariologado, quantidade);
          break;
      case 5:
          consultar_saldo_adm(admin, pessoas, moedas, usuariologado, quantidade);
          break;
      case 6:
          consultar_extrato_adm (admin, pessoas, moedas, usuariologado, quantidade);
          break;
      case 7:
          atualizar(admin, pessoas, moedas, usuariologado, quantidade);
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

//-------------------------------FUNÇÕES DO BINÁRIO---------------------------

//Função de escrever os administradores
void escrever_admin(admins admin[]) {
    FILE *file_admin = fopen("admin.bin", "wb");

    if (file_admin == NULL) {
        printf("Erro ao criar o arquivo admin.bin\n");
        return;
    }

    fwrite(admin, sizeof(admins), 10, file_admin);

    fclose(file_admin);
}

//Função de ler os administradores
void ler_admin(admins admin[] , FILE *file_admin) {
    file_admin = fopen("admin.bin", "rb");

    if (file_admin == NULL) {
        printf("Erro ao abrir o arquivo admin.bin\n");
        return;
    }

    fread(admin, sizeof(admins), 10, file_admin);

    fclose(file_admin);
    printf("Dados do administrador carregados com sucesso!\n");
}

// FUNCOES PRINCIPAIS


//Função de cadastrar novos administradores
void cadastro_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade){
  limpaterminal();
  char cpfcadastro[12];
  char senhacadastro[7];

  printf("|------------------------------[Cadastro Administrador]----------------------------"
         "|\n");

  printf("Digite seu CPF (Só pode possuir 11 dígitos): ");
  scanf("%s", cpfcadastro);
  if (strlen(cpfcadastro) != 11) {
    printf("CPF inválido\n");
    limpabuffer();
    espera();
    menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
    return;
  }
  limpabuffer();
  for (int i = 0; i < 10; i++) {
    if ((strcmp(cpfcadastro, admin[i].cpf) == 0)) {
      printf("CPF já cadastrado\n");
      espera();
      menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
      return;
    } else if ((strlen(cpfcadastro) != 11) ||
                (verificaCPF(cpfcadastro) == 0)) {
      printf("CPF inválido!\n");
      espera();
      menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
      return;
    } else if (admin[i].cpf[0] == '\0') {
      printf("Digite sua senha (numérica com 6 dígitos): ");
      scanf("%s", senhacadastro);
      limpabuffer();
      if (strlen(senhacadastro) == 6) {
        strcpy(admin[i].cpf, cpfcadastro);
        strcpy(admin[i].senha, senhacadastro);
        while(1){
          printf("Digite seu nome: ");
          fgets(pessoas[i].nome, 100, stdin);
          size_t len = strlen(admin[i].nome);
          if (len > 0 && admin[i].nome[len - 1] == '\n') {
            admin[i].nome[len - 1] = '\0';
          }
          
          if (strlen(pessoas[i].nome) < 5) {
            printf("Nome inválido (DEVE POSSUIR 5 LETRAS), tente novamente!\n");
          }else{
            break;
          }
        }
        
        printf("Cadastro realizado com sucesso!\n");
        espera();
        menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
        return;
      } else {
        printf("Senha inválida. Deve ter 6 dígitos.\n");
        espera();
        menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
        return;
      }
    }
  }
}

//Função de login dos administradores
void login_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade){
    limpaterminal();
    char cpflogin[12];
    char senhalogin[7];

    printf("|------------------------------[Login ADM]------------------------------|"
            "\n");
    printf("Digite o CPF: ");
    scanf("%s", cpflogin);

    if (strlen(cpflogin) != 11) {
        printf("CPF inválido!\n");
        limpabuffer();
        espera();
        limpaterminal();
        menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
    }
    limpabuffer();

    for (int i = 0; i < 10; i++) {
        if (strcmp(cpflogin, admin[i].cpf) == 0) {
          printf("Digite sua senha: ");
          scanf("%s", senhalogin);
          if (strlen(senhalogin) != 6) {
              printf("Senha inválida!\n");
              limpabuffer();
              espera();
              menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }
          limpabuffer();
          if (strcmp(senhalogin, admin[i].senha) == 0) {
              printf("Logado com sucesso\n");
              usuariologado = i;
              espera();
              menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
              return;
          } else {
              printf("Senha incorreta\n");
              espera();
              menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
              return;
          }
        }
    }
    printf("CPF não cadastrado!\n");
    espera();
    menu_inicial_adm(admin, pessoas, moedas, usuariologado, quantidade);
}

// Função que permite o cadastro de um novo usuário
void cadastrar_investidor_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  char cpfcadastro[12];
  char senhacadastro[7];
  int cadastrados = 0;

  printf("|------------------------------[Cadastro Investidor]----------------------------"
         "|\n");
  if (cadastrados == 9) {
    printf("Limite de cadastro atingido!\n");
    espera();
    menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
    return;
  } else {
    printf("Digite seu CPF (Só pode possuir 11 dígitos): ");
    scanf("%s", cpfcadastro);
    if (strlen(cpfcadastro) != 11) {
      printf("CPF inválido\n");
      limpabuffer();
      espera();
      menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
      return;
    }
    limpabuffer();
    for (int i = 0; i < 10; i++) {
      if ((strcmp(cpfcadastro, pessoas[i].CPF) == 0)) {
        printf("CPF já cadastrado\n");
        espera();
        menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
        return;
      } else if ((strlen(cpfcadastro) != 11) ||
                 (verificaCPF(cpfcadastro) == 0)) {
        printf("CPF inválido!\n");
        espera();
        menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
        return;
      } else if (pessoas[i].CPF[0] == '\0') {
        printf("Digite sua senha (numérica com 6 dígitos): ");
        scanf("%s", senhacadastro);
        if (strlen(senhacadastro) != 6) {
          limpabuffer();
          printf("Senha inválida\n");
          espera();
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
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
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          return;
        } else {
          printf("Senha inválida. Deve ter 6 dígitos.\n");
          espera();
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          return;
        }
      }
    }
  }
}

// Função que permite o cadastro de um novo usuário
void excluir_investidor_adm(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade) {
  limpaterminal();
  puts("Digite o CPF do investidor que deseja excluir: ");
  char cpf_excluir[12];
  char senha_adm[7];
  scanf("%s", cpf_excluir);

  if(strlen(cpf_excluir) != 11){
    puts("CPF inválido, tente novamente");
    limpabuffer();
    espera();
    menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
  }else{
    for (int i = 0; i < 10; i++) {
      if (strcmp(cpf_excluir, pessoas[i].CPF) == 0){
        puts("Digite sua senha de ADM para prosguir: ");
        scanf("%s", senha_adm);
        if(strlen(senha_adm) != 6){
          puts("Senha inválida, tente novamente");
          limpabuffer();
          espera();
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
        }else{
          if(strcmp(senha_adm, pessoas[usuariologado].senha)!=0){
            puts("Senha inválida, tente novamente");
            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }else{
            // excluindo
            memmove(&pessoas[i], &pessoas[i + 1], (9 - i - 1) * sizeof(pessoa));
            puts("Usuário removido com sucesso");
            limpabuffer();
            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }
        }
      }
    }
  }
  puts("Usuário não encontrado, tente novamente");
  limpabuffer();
  espera();
  menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
}

//Função de cadastrar novas criptomoedas
void cadastrar_criptomoeda(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade){
  char nome[100];
  
  puts("Digite o nome, sigla da criptomoeda que deseja cadastrar: ");
  scanf("%s", nome);

  if(strlen(nome) > 3){
    puts("Nome inválido, pode ter no max 3 letras");
    limpabuffer();
    espera();
    menu_adm(admin, pessoas, moedas, usuariologado, quantidade);    
  }

  for(int i=0; i<quantidade; i++){
    if(strcmp(moedas[i].nome, nome)==0){
      puts("Nome inválido, já existe");
      limpabuffer();
      espera();
      menu_adm(admin, pessoas, moedas, usuariologado, quantidade);    
    }
  }

  quantidade = quantidade+1;
  moeda *temp = realloc(moedas, quantidade * sizeof(moeda));
  moedas = temp;

  float cotacao, taxa_compra, taxa_venda;
  
  for(int i=0; i<10; i++){
    moedas[quantidade-1].carteiras[i] = 0.00;
  }
  
  strcpy(moedas[quantidade-1].nome, nome);
  puts("Digite a cotação inicial da moeda: ");
  scanf("%f", &cotacao);
  moedas[quantidade-1].cotacao = cotacao;
  puts("Digite um número inteiro da taxa de compra (OBS: o número será dividio por 100): ");  
  scanf("%f", &taxa_compra);
  moedas[quantidade-1].taxa_compra = taxa_compra/100.00;
  puts("Digite um número inteiro da taxa de venda (OBS: o número será dividio por 100): ");  
  scanf("%f", &taxa_venda);
  moedas[quantidade-1].taxa_venda = taxa_venda/100.00;

  puts("Moeda adicionanda com sucesso");
  limpabuffer();
  espera();
  menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
}

//função de excluir criptomoedas
void excluir_criptomoeda(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade){
  limpaterminal();
  puts("Digite o nome da moeda que deseja excluir: ");
  char nome[4];
  char senha_adm[7];
  scanf("%s", nome);

  if(strlen(nome) != 3){
    puts("CPF inválido, tente novamente");
    limpabuffer();
    espera();
    menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
  }else{
    for (int i = 0; i < quantidade; i++) {
      if (strcmp(nome, moedas[i].nome) == 0){
        puts("Digite sua senha de ADM para prosguir: ");
        scanf("%s", senha_adm);
        if(strlen(senha_adm) != 6){
          puts("Senha inválida, tente novamente");
          limpabuffer();
          espera();
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
        }else{
          if(strcmp(senha_adm, pessoas[usuariologado].senha)!=0){
            puts("Senha inválida, tente novamente");

            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }else{
            //excluindo
            memmove(&moedas[i], &moedas[i + 1], (quantidade - i - 1) * sizeof(moeda));
            quantidade--;

            puts("Moeda removido com sucesso");
            limpabuffer();
            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }
        }
      }
    }
  }
  puts("Moeda não encontrado, tente novamente");
  limpabuffer();
  espera();
  menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
}

//Função do administrador de consultar o saldo dos invstidores
void consultar_saldo_adm (admins admin[],pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade){
  limpaterminal();
  puts("Digite o CPF do investidor que deseja ver o saldo: ");
  char cpf[12];
  char senha_adm[7];
  scanf("%s", cpf);

  if(strlen(cpf) != 11){
    puts("CPF inválido, tente novamente");
    limpabuffer();
    espera();
    menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
  }else{
    for (int i = 0; i < 10; i++) {
      if (strcmp(cpf, pessoas[i].CPF) == 0){
        puts("Digite sua senha de ADM para proseguir: ");
        scanf("%s", senha_adm);
        if(strlen(senha_adm) != 6){
          puts("Senha inválida, tente novamente");
          limpabuffer();
          espera();
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
        }else{
          if(strcmp(senha_adm, pessoas[usuariologado].senha)!=0){
            puts("Senha inválida, tente novamente");
            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }else{
            limpaterminal();
            printf("Nome: %s\n", pessoas[i].nome);
            printf("CPF: ");
            printarcpf(pessoas[i].CPF);
            printf("\nReais: %.2f", pessoas[i].reais);
            for(int j=0; j<quantidade; j++){
              printf("\n%s: %.2f", moedas[j].nome, moedas[j].carteiras[i]);
            }
            printf("\n");
            limpabuffer();
            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }
        }
      }
    }
  }
  puts("Usuário não encontrado, tente novamente");
  limpabuffer();
  espera();
  menu_adm(admin, pessoas, moedas, usuariologado, quantidade);  
}

//Função de consultar o extrato do investidor que o admin selecionar
void consultar_extrato_adm (admins admin[],pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade){
  limpaterminal();
  puts("Digite o CPF do investidor que deseja ver o saldo: ");
  char cpf[12];
  char senha_adm[7];
  scanf("%s", cpf);

  if(strlen(cpf) != 11){
    puts("CPF inválido, tente novamente");
    limpabuffer();
    espera();
    menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
  }else{
    for (int i = 0; i < 10; i++) {
      if (strcmp(cpf, pessoas[i].CPF) == 0){
        puts("Digite sua senha de ADM para proseguir: ");
        scanf("%s", senha_adm);
        if(strlen(senha_adm) != 6){
          puts("Senha inválida, tente novamente");
          limpabuffer();
          espera();
          menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
        }else{
          if(strcmp(senha_adm, pessoas[usuariologado].senha)!=0){
            puts("Senha inválida, tente novamente");
            espera();
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }else{
            limpabuffer();
            consultarextrato(pessoas, i);
            menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
          }
        }
      }
    }
  }
  puts("Usuário não encontrado, tente novamente");
  limpabuffer();
  espera();
  menu_adm(admin, pessoas, moedas, usuariologado, quantidade);  
}

//Função de consultar extrato do investidor
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

// Função que atualizar cotações
void atualizar(admins admin[], pessoa pessoas[], moeda *moedas, int usuariologado, int quantidade) {
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
  limpabuffer();
  espera();
  menu_adm(admin, pessoas, moedas, usuariologado, quantidade);
}

