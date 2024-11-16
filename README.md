
# 🪙 Exchange-de-Criptomoedas em C

Bem-Vindo ao projeto em C da criação de um Exchange de criptomoedas do Curso (Desenvolvimento de Algoritmo) na Faculdade (FEI).
## 📈 Como funciona o nosso projeto.
<img src="https://img.freepik.com/fotos-premium/bitcoin-em-um-teclado_355067-923.jpg?w=1380" alt="Texto Alternativo">

## 📊 Objetivo do Projeto
-    Com esse projeto, nosso objetivo é a partir do conhecimento adiquirido na linguagem C, conseguir realizar uma aplicação que envolve tudo o que nos foi ensinado. Na criação desse Exchange de Criptomoedas que foi feito em até 1 mês, nosso grupo aplicou e aprendeu coisas novas da linguagem na prática, além de ser nosso primeiro projeto utilizando o git e suas ferramentas. Nos inspiramos em bancos digitais que existem e utilizamos no nosso cotidiano.

## 🧾 Compilação e Execução
-    Como compilar e executar nosso projeto?
### 1. Terminal

#### 1.1 Exchange 
-  Ao baixar a pasta e entrar no diretório dos arquivos pelo terminal de sua máquina, cole a seguinte linha de código.
  
         gcc -o exchange main.c manip_exchange.c -lm
   
      -   E logo em seguida.

        ./exchange

#### 1.2 Admin 
-  Ao baixar a pasta e entrar no diretório dos arquivos pelo terminal de sua máquina, cole a seguinte linha de código.
  
         gcc -o admin admin.c manip_admin.c -lm
    
      -   E logo em seguida.


        ./admin 

      
## 🚀 Passo a Passo - USUÁRIOS.

### 1. Menu Inicial
-    Aqui é apresentado ao usuario 3 opções.
-    **Cadastro**:  Caso não tenha uma conta no Exchange, crie sua conta aqui com um CPF válido, senha e um nome de usuário.
-    **Login**:  Caso já tenha uma conta e deseja acessa-la.
-    **Sair**: Sair da aplicação.

### 2. Menu de opções
-    Menu principal do projeto, onde nos é apresentado todas as funcionalidades do projeto.
     #### 2.1 Consultar Saldo
     -    É mostrado ao usuário todo o saldo atual da conta, dados pessoais como nome e CPF e a quantidade de Reais e Criptomoedas investidas.
     #### 2.2 Consultar Extrato
     -    É apresentado o extrato total da conta com um limite de 100 históricos, salvando todas as transações feitas na plataforma. 
     #### 2.3 Depositar
     -    Local onde o usuário consegue depositar uma quantia em reais para sua conta.
     #### 2.4 Sacar
     -    Local onde o usuário consegue realizar o saque de uma quantia de reais da sua conta.
     #### 2.5 Comprar Moedas
     -    Aqui é mostrado ao usuário as três criptomoedas que trabalhamos(Bitcoin/Ethereum/Ripple) juntamente com sua cotação atual, onde o usuário poderá escolher uma entre as três e comprar a quantidade desejada.
     #### 2.6 Vender Moedas
     -    Aqui é mostrado ao usuário as três criptomoedas que trabalhamos(Bitcoin/Ethereum/Ripple) juntamente com sua cotação atual, onde o usuário poderá escolher uma entre as três e vender a quantidade desejada.
     #### 2.7 Atualizar Cotação
     -    Onde as cotações das criptomoedas podem ser atualizadas e seu valor consequentemente mudado com apenas um clique.
     #### 2.8 Voltar ao menu inicial
     -    Opção de sair e voltar ao menu inicial.
 
## 🚀 Passo a Passo - ADMINISTRADORES.

### 1. Menu Inicial
-    Aqui é apresentado ao usuario 3 opções.
-    **Cadastro**:  Caso não tenha um cadastro de administrador, pode fazer informando seu CPF, uma senha e seu nome.
-    **Login**:  Caso já tenha uma conta e deseja acessa-la.
-    **Sair**: Sair da aplicação.

### 2. Menu de opções
-    Menu principal do projeto, onde nos é apresentado todas as funcionalidades do projeto.
     #### 2.1 Cadastro de novos investidores
     -    Assim como um usuário comum, o administrador pode cadastrar novos usuários, com  as mesmas informações do cadastro de usuários comuns.
     #### 2.2 Excluir investidores
     -    Local onde o administrador pode excluir qualquer um dos usuário apenas digitando o CPF e fazendo uma confirmação. Recurso usado para deixar o nosso banco longe de 'Hackers'.
     #### 2.3 Cadastro de Criptomoedas
     -    Local onde o administrador pode cadastrar uma grande váriedade de novas criptomoedas para que o investidor possa investir com segurança e muita diversidade.
     #### 2.4 Excluir Criptomoedas
     -    Assim como o mesmo pode casdastrar mais Criptomoedas, o mesmo pode excluir qualquer uma apenas com o nome da criptomoeda, e após uma confirmação a moeda é excluida totalmente.
     #### 2.5 Consultar saldo dos investidores
     -    Aqui uma consulta de saldo pode ser feita pelo administrador em qualquer um dos usuários, apenas informando o CPF do usuário em questão e ver seu saldo atual.
     #### 2.6 Consultar extrato dos investidores
     -    Aqui onde o administrador pode fazer a consulta dos extrato de todos os usuários, apenas informando o CPF do usuário em questão e ver todo o extrato.
     #### 2.7 Atualizar Cotação das Criptomoedas
     -    Onde as cotações das criptomoedas podem ser atualizadas e seu valor consequentemente mudado com apenas um clique.
 
## 🚀 Instruções de uso do projeto

### USUÁRIOS

-   Logo que iniciar o programa, o usuário será redirecionado para um menu inicial onde o mesmo deverá fazer seu cadastro, após selecionar a opção de cadastro, o usuário deverá informar os dados necessários, sendo eles: CPF, senha e nome ( **CPF : 12345678909 , SENHA : 123456 , NOME : USUARIO**).
-   Após o cadastro ser efetuado, o login deverá ser feito para acessar o menu e conseguir utilizar 100% das funcionalidades da exchange, para isso o investidor deverá selecionar a opção de login e informar as mesmas informações utilizadas no cadastro.
-   Dentro do menu de operações, o mesmo poderá escolher qualquer uma das opções com o número correspondente a operação desejada.
-   Por fim, para sair basta apenas selecionar a opção de sair do menu (correspondente ao número 8) e por fim selecionar a opção de sair (correspondente ao número 3).

### ADMINISTRADORES

-   Logo que iniciar o programa, o administrador será redirecionado para um menu inicial onde o mesmo deverá fazer seu cadastro, após selecionar a opção de cadastro, o administrador deverá informar os dados necessários, sendo eles: CPF, senha e nome ( **CPF : 12345678909 , SENHA : 123456 , NOME : ADMIN**).
-   Após o cadastro ser efetuado, o login deverá ser feito para acessar o menu e conseguir utilizar as opções de administrador, desde criar usuarios a exclusão de criptomoedas, para isso o mesmo deverá selecionar a opção de login e informar as mesmas informações utilizadas no cadastro.
-   Dentro do menu de operações, o mesmo poderá escolher qualquer uma das opções com o número correspondente a operação desejada.
-   Por fim, para sair basta apenas selecionar a opção de sair do menu (correspondente ao número 0) e por fim selecionar a opção de sair (correspondente ao número 3).

## 🚀 Exemplo de uso do projeto

### USUÁRIO

#### 1.1 Menu inicial
-  Selecionar opção de cadastro.

![Captura de tela de 2024-11-15 23-27-18](https://github.com/user-attachments/assets/947779b9-98c0-4ee4-a815-084ff71967ba)

#### 1.2 Cadastro
-  **CPF : 12345678909 , SENHA : 123456 , NOME : USUARIO**.

![Captura de tela de 2024-11-15 23-27-45](https://github.com/user-attachments/assets/90085cdd-b9ae-4b48-a693-ec00ade54d49)

#### 1.3 Login
-  Após voltar para o menu, selecione 2 e vá para o login.

![Captura de tela de 2024-11-15 23-28-18](https://github.com/user-attachments/assets/29f1703d-6865-446b-8dd0-923a75ebc586)

#### 1.4 Menu de operações
-  Selecionando a opção de depositar.

![Captura de tela de 2024-11-15 23-28-39](https://github.com/user-attachments/assets/ba36ce10-e1a0-4772-a884-a4004315006a)

#### 1.5 Depósito
-  Informando quanto deseja depositar e logo após, informando a senha do usuario.

![Captura de tela de 2024-11-15 23-29-02](https://github.com/user-attachments/assets/b3adb8a4-6f96-44b6-b5f8-ccd38dadbcf1)

#### 1.6 Consultar extrato
-  Selecionando a opção de consultar extrato

![Captura de tela de 2024-11-15 23-29-31](https://github.com/user-attachments/assets/d527d13b-91d5-4e1c-8d53-bbc0db1281e6)

#### 1.7 Extrato
![Captura de tela de 2024-11-15 23-29-42](https://github.com/user-attachments/assets/5c65e2a5-c894-4ba3-aa1c-36be54a3cc80)

#### 1.8 Voltando para o Menu inicial
![Captura de tela de 2024-11-15 23-29-55](https://github.com/user-attachments/assets/1d48ede2-3218-4633-8f37-75a669b03ade)

#### 1.9 Saindo do programa
![Captura de tela de 2024-11-15 23-30-07](https://github.com/user-attachments/assets/63ada8b6-0fe5-4bd2-bb35-a97f7f83bf7a)


### ADMINISTRADOR

#### 2.1 Menu Inicial
-  Selecionando a opção de cadastro.

![Captura de tela de 2024-11-15 23-40-54](https://github.com/user-attachments/assets/f2d00431-4680-4d19-88b6-aee2b111cb94)

#### 2.2 Cadastro
- **CPF : 12345678909 , SENHA : 123456 , NOME : USUARIO**.

![Captura de tela de 2024-11-15 23-41-18](https://github.com/user-attachments/assets/8207151e-491c-44b2-adc8-b6c278b36ab8)

#### 2.3 Login
-  Após retornar do cadastro, selecionar o 2 e informar os dados do cadastro.

![Captura de tela de 2024-11-15 23-41-44](https://github.com/user-attachments/assets/9068aff4-a072-4c1d-aa9c-9ff727e6d742)

#### 2.4 Menu de operações
-  Selecionando o consultar extrato.

![Captura de tela de 2024-11-15 23-42-20](https://github.com/user-attachments/assets/05dc916e-ec88-4733-a7ac-de98e0dcd20a)

#### 2.5 Consultar extrato
-  Informando o CPF do usuário e a senha do administrador.

![Captura de tela de 2024-11-15 23-43-03](https://github.com/user-attachments/assets/0035e648-516d-47a4-84db-c50f009d9b74)

#### 2.6 Voltando para o Menu inicial
![Captura de tela de 2024-11-15 23-43-51](https://github.com/user-attachments/assets/4169cd4a-4481-4332-9ad4-7a396a278e27)

#### 2.7 Saindo do programa
![Captura de tela de 2024-11-15 23-44-03](https://github.com/user-attachments/assets/5caad860-90c5-46bc-b0d9-2be64c9a0f58)


## 🏷️ Membros da Equipe
-    Arthur Barbosa Zanvetor  **R.A.**: 24.124.063-9
-    Fernando Bordin Lopes  **R.A.**: 24.124.003-5
-    Gabriel de Figueiredo Pereira Engle  **R.A.**: 24.124.024-1
