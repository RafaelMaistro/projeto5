#include "tarefa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicialização das variáveis
struct ContatoPessoal listaContatosPessoais[MAX_CONTATOS];
struct ContatoTrabalho listaContatosTrabalho[MAX_CONTATOS];
int numContatosPessoais = 0;
int numContatosTrabalho = 0;

void removerNovaLinha(char *str) {
  int len = strlen(str);
  if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
}

void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int validarEmail(const char *email) {
  int tam = strlen(email);
  int temArroba = 0;
  int temPonto = 0;
  int posArroba = 0;

  for (int i = 0; i < tam; i++) {
    if (email[i] == '@') {
      temArroba = 1;
      posArroba = i;
    }
    if (email[i] == '.' && i > posArroba) {
      temPonto = 1;
    }
  }
  return temArroba && temPonto;
}

int verificarTelefoneUnico(const char *telefone, struct ContatoPessoal lista[],
                           int numContatos, int indiceContatoAtual) {
  for (int i = 0; i < numContatos; i++) {
    if (i != indiceContatoAtual && strcmp(lista[i].telefone, telefone) == 0) {
      return 0;
    }
  }
  return 1;
}

void adicionarContatoPessoal() {
  if (numContatosPessoais < MAX_CONTATOS) {
    printf("Digite o seu nome: ");
    fgets(listaContatosPessoais[numContatosPessoais].nome, TAM_NOME, stdin);
    removerNovaLinha(listaContatosPessoais[numContatosPessoais].nome);

    // Verifica se a entrada excedeu o tamanho do buffer
    if (strlen(listaContatosPessoais[numContatosPessoais].nome) ==
            TAM_NOME - 1 &&
        listaContatosPessoais[numContatosPessoais].nome[TAM_NOME - 2] != '\n') {
      // Limpa o restante da entrada do usuário para evitar buffer overflow
      limparBufferEntrada();
    }

    printf("Digite o seu sobrenome: ");
    fgets(listaContatosPessoais[numContatosPessoais].sobrenome, TAM_SOBRENOME,
          stdin);
    removerNovaLinha(listaContatosPessoais[numContatosPessoais].sobrenome);

    if (strlen(listaContatosPessoais[numContatosPessoais].sobrenome) ==
            TAM_SOBRENOME - 1 &&
        listaContatosPessoais[numContatosPessoais]
                .sobrenome[TAM_SOBRENOME - 2] != '\n') {

      limparBufferEntrada();
    }

    printf("Digite o seu email: ");
    fgets(listaContatosPessoais[numContatosPessoais].email, TAM_EMAIL, stdin);
    removerNovaLinha(listaContatosPessoais[numContatosPessoais].email);

    if (strlen(listaContatosPessoais[numContatosPessoais].email) ==
            TAM_EMAIL - 1 &&
        listaContatosPessoais[numContatosPessoais].email[TAM_EMAIL - 2] !=
            '\n') {

      limparBufferEntrada();
    }

    while (!validarEmail(listaContatosPessoais[numContatosPessoais].email)) {
      printf("Email inválido! Digite novamente: ");
      fgets(listaContatosPessoais[numContatosPessoais].email, TAM_EMAIL, stdin);
      removerNovaLinha(listaContatosPessoais[numContatosPessoais].email);
    }

    printf("Digite o seu telefone: ");
    fgets(listaContatosPessoais[numContatosPessoais].telefone, TAM_TELEFONE,
          stdin);
    removerNovaLinha(listaContatosPessoais[numContatosPessoais].telefone);

    if (strlen(listaContatosPessoais[numContatosPessoais].telefone) ==
            TAM_TELEFONE - 1 &&
        listaContatosPessoais[numContatosPessoais].telefone[TAM_TELEFONE - 2] !=
            '\n') {

      limparBufferEntrada();
    }

    while (!verificarTelefoneUnico(
        listaContatosPessoais[numContatosPessoais].telefone,
        listaContatosPessoais, numContatosPessoais, numContatosPessoais)) {
      printf("Telefone já existente! Digite novamente: ");
      fgets(listaContatosPessoais[numContatosPessoais].telefone, TAM_TELEFONE,
            stdin);
      removerNovaLinha(listaContatosPessoais[numContatosPessoais].telefone);
    }

    numContatosPessoais++;
  } else {
    printf("Lista de contatos pessoais cheia!\n");
  }
}

void adicionarContatoTrabalho() {
  if (numContatosTrabalho < MAX_CONTATOS) {
    printf("Digite o nome do contato: ");
    fgets(listaContatosTrabalho[numContatosTrabalho].nome, TAM_NOME, stdin);
    removerNovaLinha(listaContatosTrabalho[numContatosTrabalho].nome);

    printf("Digite o sobrenome do contato: ");
    fgets(listaContatosTrabalho[numContatosTrabalho].sobrenome, TAM_SOBRENOME,
          stdin);
    removerNovaLinha(listaContatosTrabalho[numContatosTrabalho].sobrenome);

    printf("Digite o email do contato: ");
    fgets(listaContatosTrabalho[numContatosTrabalho].email, TAM_EMAIL, stdin);
    removerNovaLinha(listaContatosTrabalho[numContatosTrabalho].email);

    printf("Digite o telefone do contato: ");
    fgets(listaContatosTrabalho[numContatosTrabalho].telefone, TAM_TELEFONE,
          stdin);
    removerNovaLinha(listaContatosTrabalho[numContatosTrabalho].telefone);

    numContatosTrabalho++;
  } else {
    printf("Lista de contatos de trabalho cheia!\n");
  }
}

void listarContatosPessoais() {
  if (numContatosPessoais == 0) {
    printf("Nenhum contato pessoal cadastrado.\n");
    return;
  }

  printf("Lista dos Contatos Pessoais:\n");
  for (int i = 0; i < numContatosPessoais; i++) {
    printf("NOME: %s %s\n", listaContatosPessoais[i].nome,
           listaContatosPessoais[i].sobrenome);
    printf("EMAIL: %s\n", listaContatosPessoais[i].email);
    printf("TELEFONE: %s\n", listaContatosPessoais[i].telefone);
    printf("\n");
  }
}

void listarContatosTrabalho() {
  if (numContatosTrabalho == 0) {
    printf("Nenhum contato de trabalho cadastrado.\n");
    return;
  }

  printf("Lista dos Contatos de Trabalho:\n");
  for (int i = 0; i < numContatosTrabalho; i++) {
    printf("NOME: %s %s\n", listaContatosTrabalho[i].nome,
           listaContatosTrabalho[i].sobrenome);
    printf("EMAIL: %s\n", listaContatosTrabalho[i].email);
    printf("TELEFONE: %s\n", listaContatosTrabalho[i].telefone);
    printf("\n");
  }
}

void deletarContatoPessoal() {
  if (numContatosPessoais == 0) {
    printf("Não há contatos pessoais para deletar!\n");
    return;
  }

  char telefone[TAM_TELEFONE];
  printf("Digite o telefone do contato pessoal a ser deletado: ");
  fgets(telefone, TAM_TELEFONE, stdin);
  removerNovaLinha(telefone);

  int encontrado = 0;
  for (int i = 0; i < numContatosPessoais; i++) {
    if (strcmp(listaContatosPessoais[i].telefone, telefone) == 0) {
      encontrado = 1;
      numContatosPessoais--;
      listaContatosPessoais[i] = listaContatosPessoais[numContatosPessoais];
      printf("O contato pessoal foi deletado !\n");
      break;
    }
  }

  if (!encontrado) {
    printf("O contato pessoal não foi encontrado!\n");
  }
}

void deletarContatoTrabalho() {
  if (numContatosTrabalho == 0) {
    printf("Não há contatos de trabalho para deletar!\n");
    return;
  }

  char email[TAM_EMAIL];
  printf("Digite o email do contato de trabalho a ser deletado: ");
  fgets(email, TAM_EMAIL, stdin);
  removerNovaLinha(email);

  int encontrado = 0;
  for (int i = 0; i < numContatosTrabalho; i++) {
    if (strcmp(listaContatosTrabalho[i].email, email) == 0) {
      encontrado = 1;
      numContatosTrabalho--;
      listaContatosTrabalho[i] = listaContatosTrabalho[numContatosTrabalho];
      printf("O contato de trabalho foi deletado!\n");
      break;
    }
  }

  if (!encontrado) {
    printf("O contato de trabalho não foi encontrado!\n");
  }
}

void alterarContatoPessoal() {
  if (numContatosPessoais == 0) {
    printf("Não há contatos pessoais para alterar!\n");
    return;
  }

  char telefone[TAM_TELEFONE];
  printf("Digite o telefone do contato pessoal a ser alterado: ");
  fgets(telefone, TAM_TELEFONE, stdin);
  removerNovaLinha(telefone);

  int encontrado = 0;
  for (int i = 0; i < numContatosPessoais; i++) {
    if (strcmp(listaContatosPessoais[i].telefone, telefone) == 0) {
      encontrado = 1;

      printf("Novo email: ");
      fgets(listaContatosPessoais[i].email, TAM_EMAIL, stdin);
      removerNovaLinha(listaContatosPessoais[i].email);

      while (!validarEmail(listaContatosPessoais[i].email)) {
        printf("Email inválido! Digite novamente: ");
        fgets(listaContatosPessoais[i].email, TAM_EMAIL, stdin);
        removerNovaLinha(listaContatosPessoais[i].email);
      }

      printf("Novo telefone: ");
      fgets(listaContatosPessoais[i].telefone, TAM_TELEFONE, stdin);
      removerNovaLinha(listaContatosPessoais[i].telefone);

      while (!verificarTelefoneUnico(listaContatosPessoais[i].telefone,
                                     listaContatosPessoais, numContatosPessoais,
                                     i)) {
        printf("Telefone já existente! Digite novamente: ");
        fgets(listaContatosPessoais[i].telefone, TAM_TELEFONE, stdin);
        removerNovaLinha(listaContatosPessoais[i].telefone);
      }

      printf("Contato pessoal alterado!\n");
      break;
    }
  }

  if (!encontrado) {
    printf("O contato pessoal não foi encontrado!\n");
  }
}

void alterarContatoTrabalho() {
  if (numContatosTrabalho == 0) {
    printf("Não há contatos de trabalho para alterar!\n");
    return;
  }

  char email[TAM_EMAIL];
  printf("Digite o email do contato de trabalho a ser alterado: ");
  fgets(email, TAM_EMAIL, stdin);
  removerNovaLinha(email);

  int encontrado = 0;
  for (int i = 0; i < numContatosTrabalho; i++) {
    if (strcmp(listaContatosTrabalho[i].email, email) == 0) {
      encontrado = 1;

      printf("Novo email: ");
      fgets(listaContatosTrabalho[i].email, TAM_EMAIL, stdin);
      removerNovaLinha(listaContatosTrabalho[i].email);

      while (!validarEmail(listaContatosTrabalho[i].email)) {
        printf("Email inválido! Digite novamente: ");
        fgets(listaContatosTrabalho[i].email, TAM_EMAIL, stdin);
        removerNovaLinha(listaContatosTrabalho[i].email);
      }

      printf("Novo telefone: ");
      fgets(listaContatosTrabalho[i].telefone, TAM_TELEFONE, stdin);
      removerNovaLinha(listaContatosTrabalho[i].telefone);

      printf("Contato de trabalho alterado!\n");
      break;
    }
  }

  if (!encontrado) {
    printf("O contato de trabalho não foi encontrado!\n");
  }
}

void salvarContatosPessoais() {
  FILE *arquivo = fopen("contatos_pessoais.bin", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para salvar!\n");
    return;
  }

  fwrite(&numContatosPessoais, sizeof(int), 1, arquivo);
  fwrite(listaContatosPessoais, sizeof(struct ContatoPessoal),
         numContatosPessoais, arquivo);

  fclose(arquivo);
  printf("Contatos pessoais salvos com sucesso!\n");
}

void salvarContatosTrabalho() {
  FILE *arquivo = fopen("contatos_trabalho.bin", "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para salvar!\n");
    return;
  }

  fwrite(&numContatosTrabalho, sizeof(int), 1, arquivo);
  fwrite(listaContatosTrabalho, sizeof(struct ContatoTrabalho),
         numContatosTrabalho, arquivo);

  fclose(arquivo);
  printf("Contatos de trabalho salvos com sucesso!\n");
}

void carregarContatosPessoais() {
  FILE *arquivo = fopen("contatos_pessoais.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para carregar!\n");
    return;
  }

  fread(&numContatosPessoais, sizeof(int), 1, arquivo);
  fread(listaContatosPessoais, sizeof(struct ContatoPessoal),
        numContatosPessoais, arquivo);

  fclose(arquivo);
  printf("Contatos pessoais carregados com sucesso!\n");
}

void carregarContatosTrabalho() {
  FILE *arquivo = fopen("contatos_trabalho.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para carregar!\n");
    return;
  }

  fread(&numContatosTrabalho, sizeof(int), 1, arquivo);
  fread(listaContatosTrabalho, sizeof(struct ContatoTrabalho),
        numContatosTrabalho, arquivo);

  fclose(arquivo);
  printf("Contatos de trabalho carregados com sucesso!\n");
}
