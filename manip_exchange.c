void consultarsaldo() {

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

void login() {

}

void cadastro(int usuariologado) {

  }

void menuinicial(int usuariologado) {
    char opc;
    while (1) {
        printf("╔══════════[Menu Inicial]══════════╗\n");
        printf("║ [1] Cadastro                     ║\n");
        printf("║ [2] Login                        ║\n");
        printf("║ [3] Sair                         ║\n");
        printf("╚══════════════════════════════════╝\n");
        printf("Digite a opção: ");
        scanf(" %c", &opc);
        getchar(); 

        switch (opc) {
        case '1':
            cadastro(usuariologado);
            return;
        case '2':
            login();
            return;
        case '3':
            exit(0);
            return;
        default:
            printf("Opção inválida, tente novamente\n");
            break;
        }
    }
}

void menu(int usuariologado) {
    char opc;
    while (1) {
        printf(" ╠════════════════════════════════════════════════╣\n");
        printf("   Bem-vindo, %s\n", pessoas[usuariologado].nome);
        printf(" ╠════════════════[Menu de opções]════════════════╣\n");
        printf(" ║ Aperte [1] para consultar saldo                ║\n");
        printf(" ║ Aperte [2] para consultar extrato              ║\n");
        printf(" ║ Aperte [3] para depositar                      ║\n");
        printf(" ║ Aperte [4] para sacar                          ║\n");
        printf(" ║ Aperte [5] para comprar moedas                 ║\n");
        printf(" ║ Aperte [6] para vender moedas                  ║\n");
        printf(" ║ Aperte [7] para atualizar cotação              ║\n");
        printf(" ║ Aperte [8] para voltar ao menu principal       ║\n");
        printf(" ╚════════════════════════════════════════════════╝\n");
        printf("Digite a opção: ");
        scanf(" %c", &opc);
        getchar(); 
        switch (opc) {
        case '1':
            consultarsaldo(usuariologado);
            return;
        case '2':
            consultarextrato(usuariologado);
            return;
        case '3':
            depositar(usuariologado);
            return;
        case '4':
            sacar(usuariologado);
            return;
        case '5':
            comprar(usuariologado);
            return;
        case '6':
            vender(usuariologado);
            return;
        case '7':
            atualizar();
            return;
        case '8':
            menuinicial(usuariologado);
            return;
        default:
            printf("Opção inválida, tente novamente\n");
            return;
        }
    }
}
