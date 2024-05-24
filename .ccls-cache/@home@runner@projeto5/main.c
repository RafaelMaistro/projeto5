#include "tarefa.h"
#include <stdio.h>

int main() {
  int opcao;

  do {
    printf("\nMenu Principal:\n");
    printf("1. Adicionar Contato Pessoal\n");
    printf("2. Adicionar Contato de Trabalho\n");
    printf("3. Listar Contatos Pessoais\n");
    printf("4. Listar Contatos de Trabalho\n");
    printf("5. Deletar Contato Pessoal\n");
    printf("6. Deletar Contato de Trabalho\n");
    printf("7. Alterar Contato Pessoal\n");
    printf("8. Alterar Contato de Trabalho\n");
    printf("9. Salvar Contatos Pessoais\n");
    printf("10. Salvar Contatos de Trabalho\n");
    printf("11. Carregar Contatos Pessoais\n");
    printf("12. Carregar Contatos de Trabalho\n");
    printf("13. Sair do programa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    limparBufferEntrada(); 

    switch (opcao) {
    case 1:
      adicionarContatoPessoal();
      break;
    case 2:
      adicionarContatoTrabalho();
      break;
    case 3:
      listarContatosPessoais();
      break;
    case 4:
      listarContatosTrabalho();
      break;
    case 5:
      deletarContatoPessoal();
      break;
    case 6:
      deletarContatoTrabalho();
      break;
    case 7:
      alterarContatoPessoal();
      break;
    case 8:
      alterarContatoTrabalho();
      break;
    case 9:
      salvarContatosPessoais();
      break;
    case 10:
      salvarContatosTrabalho();
      break;
    case 11:
      carregarContatosPessoais();
      break;
    case 12:
      carregarContatosTrabalho();
      break;
    case 13:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
      break;
    }
  } while (opcao != 13);

  return 0;
}
