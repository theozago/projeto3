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
int filtrarTarefasPorPrioridade(ListaDeTarefas lt, int prioridade);
int filtrarTarefasPorEstado(ListaDeTarefas lt, int estado);
int filtrarTarefasPorCategoria(ListaDeTarefas lt, const char categoria[]);
int filtrarTarefasPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char categoria[]);
int exportarTarefasPorPrioridade(ListaDeTarefas lt, int prioridade, const char arquivo[]);
int exportarTarefasPorCategoria(ListaDeTarefas lt, const char categoria[], const char arquivo[]);
int exportarTarefasPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char categoria[], const char arquivo[]);


void printMenu();
int salvarTarefas(ListaDeTarefas *lt, const char *arquivo);
int carregarTarefas(ListaDeTarefas *lt, const char *arquivo);

#endif // PROJETO_PROJ3_H