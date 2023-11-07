#ifndef PROJETO_PROJ3_H
#define PROJETO_PROJ3_H

// Definição da estrutura Tarefa
typedef struct {
    int prioridade;         
    char categoria[100];    
    char descricao[300];    
    int estado;             
} Tarefa;

// Definição da estrutura ListaDeTarefas
typedef struct {
    Tarefa tarefas[100];    
    int qtd;      
} ListaDeTarefas;



int cadastrarTarefa(ListaDeTarefas *lt);// Função para cadastrar uma nova tarefa
int deletarTarefas(ListaDeTarefas *lt);// Função para deletar tarefas da lista
int listarTarefas(ListaDeTarefas lt);// Função para listar tarefas
int alterarTarefa(ListaDeTarefas *lt);// Função para alterar uma tarefa existente
int filtrarTarefasPorPrioridade(ListaDeTarefas lt, int prioridade);// Função para filtrar tarefas por prioridade
int filtrarTarefasPorEstado(ListaDeTarefas lt, int estado);// Função para filtrar tarefas por estado
int filtrarTarefasPorCategoria(ListaDeTarefas lt, const char categoria[]);// Função para filtrar tarefas por categoria
int filtrarTarefasPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char categoria[]);// Função para filtrar por prioridade e categoria
int exportarTarefasPorPrioridade(ListaDeTarefas lt, int prioridade, const char arquivo[]);// Função para exportar tarefas por prioridade
int exportarTarefasPorCategoria(ListaDeTarefas lt, const char categoria[], const char arquivo[]);// Função para exportar tarefas por categoria
int exportarTarefasPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char categoria[], const char arquivo[]);// Função para exportar por prioridade e categoria

void printMenu(); // Função para imprimir o menu
int salvarTarefas(ListaDeTarefas *lt, const char *arquivo); // Função para salvar tarefas em um arquivo
int carregarTarefas(ListaDeTarefas *lt, const char *arquivo); // Função para carregar tarefas de um arquivo

#endif // PROJETO_PROJ3_H
