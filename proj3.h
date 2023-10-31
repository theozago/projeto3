//
// Created by uniftzimmermann on 18/09/2023.
//

#ifndef PROJETO_PROJ3_H
#define PROJETO_PROJ3_H


//para criar um nome para cada funcao que usaremos na proj.c
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

//funcoes de cadastrar, deletar e listar tarefas
int cadastrarTarefa(ListaDeTarefas *lt);
int deletarTarefas(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas lt);

//funcao para mostrar o menu para o usuario
void printMenu();
//para salvar as tarefas no arquivo
int salvarTarefas(ListaDeTarefas *lt, char *arquivo);
//para carregar as tarefas no arquivos
int carregarTarefas(ListaDeTarefas *lt, char *arquivo);
#endif //PROJETO_PROJ_H
