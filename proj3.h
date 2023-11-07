#ifndef PROJETO_PROJ3_H
#define PROJETO_PROJ3_H

typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
    int estado; // 0 para não iniciado, 1 para em andamento, 2 para completo
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

int cadastrarTarefa(ListaDeTarefas *lt);
int deletarTarefas(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas lt);
int alterarTarefa(ListaDeTarefas *lt);


void printMenu();
int salvarTarefas(ListaDeTarefas *lt, const char *arquivo);
int carregarTarefas(ListaDeTarefas *lt, const char *arquivo);

#endif // PROJETO_PROJ3_H