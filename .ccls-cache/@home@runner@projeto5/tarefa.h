#ifndef TAREFA_H
#define TAREFA_H

#define MAX_CONTATOS 255
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_EMAIL 50
#define TAM_TELEFONE 20

struct ContatoPessoal {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
};

struct ContatoTrabalho {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
};

extern struct ContatoPessoal listaContatosPessoais[MAX_CONTATOS];
extern struct ContatoTrabalho listaContatosTrabalho[MAX_CONTATOS];
extern int numContatosPessoais;
extern int numContatosTrabalho;

void removerNovaLinha(char *str);
void limparBufferEntrada();
int validarEmail(const char *email);
int verificarTelefoneUnico(const char *telefone, struct ContatoPessoal lista[], int numContatos, int indiceContatoAtual);

void adicionarContatoPessoal();
void adicionarContatoTrabalho();
void listarContatosPessoais();
void listarContatosTrabalho();
void deletarContatoPessoal();
void deletarContatoTrabalho();
void alterarContatoPessoal();
void alterarContatoTrabalho();
void salvarContatosPessoais();
void salvarContatosTrabalho();
void carregarContatosPessoais();
void carregarContatosTrabalho();

#endif