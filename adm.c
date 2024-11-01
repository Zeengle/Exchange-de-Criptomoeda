#include "manip_exchange.h"

void adm_menu(){
  int esq = 0, selecao;
  puts("Ola Administrador!");
  puts("[0] Voltar");
  puts("[1] Excluir investidor");
  puts("[2] Cadastro de criptomoeda");
  puts("[3] Excluir criptomoeda");
  puts("[4] Consultar saldo de um investidor");
  puts("[5] Consultar extrado de um investidor");
  puts("[6] Atualizar cotação de criptomoedas");

  while(!esq){
    printf("/n Escolha uma opção");
    scanf("%d", &selecao);

    switch(selecao){
      case 0:
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
      default:
          puts("[] Opção errada");
    }
  }
}
