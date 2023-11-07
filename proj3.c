#include <stdio.h>
#include "proj3.h"
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("\nMenu:\n");
    printf("1 Cadastrar Tarefa\n");
    printf("2 Deletar Tarefa\n");
    printf("3 Listar Tarefas\n");
    printf("4 Alterar Tarefa\n");
    printf("5 Filtrar Tarefas por Prioridade\n");
    printf("6 Filtrar Tarefas por Estado\n");
    printf("7 Filtrar Tarefas por Categoria\n");
    printf("8 Filtrar Tarefas por Prioridade e Categoria\n");
    printf("9 Exportar Tarefas por Prioridade\n");
    printf("10 Exportar Tarefas por Categoria\n");
    printf("11 Exportar Tarefas por Prioridade e Categoria\n");
    printf("0 Sair\n");
    printf("Escolha uma opcao: ");
}

int cadastrarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd < 100) {
        Tarefa novaTarefa;

        printf("Digite a prioridade da tarefa entre 0 e 10: ");
        scanf("%d", &novaTarefa.prioridade);

        if (novaTarefa.prioridade < 0 || novaTarefa.prioridade > 10) {
            printf("Prioridade invalida. A prioridade deve estar entre 0 e 10.\n");
            return 0;
        }

        printf("Digite a categoria da tarefa: ");
        scanf("%s", novaTarefa.categoria);

        printf("Digite a descricao da tarefa: ");
        scanf("%s", novaTarefa.descricao);

        printf("Escolha o estado da tarefa (0 - Nao iniciado, 1 - Em andamento, 2 - completo): ");
        scanf("%d", &novaTarefa.estado);

        if (novaTarefa.estado < 0 || novaTarefa.estado > 2) {
            printf("Estado invalido. Use 0 para Nao iniciado, 1 para Em andamento, ou 2 para completo.\n");
            return 0;
        }

        lt->tarefas[lt->qtd] = novaTarefa;
        lt->qtd++;

        printf("Tarefa cadastrada com sucesso\n");

    } else {
        printf("A lista de tarefas esta cheia.\n");
    }
}

int alterarTarefa(ListaDeTarefas *lt) {
    int num;
    printf("Digite o numero da tarefa que deseja alterar: ");
    scanf("%d", &num);

    if (num >= 1 && num <= lt->qtd) {
        Tarefa *tarefa = &lt->tarefas[num - 1];

        printf("Escolha o campo que deseja alterar:\n");
        printf("1 - Prioridade\n");
        printf("2 - Categoria\n");
        printf("3 - Descricao\n");
        printf("4 - Estado\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nova prioridade: ");
                scanf("%d", &tarefa->prioridade);
                break;
            case 2:
                printf("Nova categoria: ");
                scanf("%s", tarefa->categoria);
                break;
            case 3:
                printf("Nova descricao: ");
                scanf("%s", tarefa->descricao);
                break;
            case 4:
                printf("Novo estado (0 - Nao iniciado, 1 - Em andamento, 2 - completo): ");
                scanf("%d", &tarefa->estado);
                if (tarefa->estado < 0 || tarefa->estado > 2) {
                    printf("Estado invalido. Use 0 para Nao iniciado, 1 para Em andamento, ou 2 para completo.\n");
                    return 0;
                }
                break;
            default:
                printf("Opcao invalida.\n");
                return 0;
        }

        printf("Tarefa alterada com sucesso!\n");
        return 1;
    } else {
        printf("Nao existe essa tarefa.\n");
        return 0;
    }
}



int deletarTarefas(ListaDeTarefas *lt) {
    int num;
    printf("Digite o número da tarefa que deseja deletar: ");
    scanf("%d", &num);

    if (num >= 1 && num <= lt->qtd) {
        for (int i = num - 1; i < lt->qtd - 1; i++) {
            lt->tarefas[i] = lt->tarefas[i + 1];
        }
        lt->qtd--;

        printf("Tarefa com o numero %d foi deletada com sucesso\n", num);
        return 1;
    } else {
        printf("Nao existe essa tarefa.\n");
        return 0;
    }
}

int listarTarefas(ListaDeTarefas lt) {
    if (lt.qtd == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return 0;
    }

    printf("Lista de Tarefas:\n");
    for (int i = 0; i < lt.qtd; i++) {
        printf("Tarefa: %d\n", i + 1);
        printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
        printf("Categoria: %s\n", lt.tarefas[i].categoria);
        printf("Descricao: %s\n", lt.tarefas[i].descricao);
        printf("Estado: %d\n", lt.tarefas[i].estado);
    }

    return 1;
}
int filtrarTarefasPorPrioridade(ListaDeTarefas lt, int prioridade) {
    int encontrou = 0;
    printf("Tarefas com prioridade %d:\n", prioridade);

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com prioridade %d.\n", prioridade);
    }
}

int filtrarTarefasPorEstado(ListaDeTarefas lt, int estado) {
    int encontrou = 0;
    printf("Tarefas com estado %d:\n", estado);

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].estado == estado) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com estado %d.\n", estado);
    }
}
int filtrarTarefasPorCategoria(ListaDeTarefas lt, const char categoria[]) {
    int encontrou = 0;
    printf("Tarefas com categoria %s:\n", categoria);

    for (int i = 0; i < lt.qtd; i++) {
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com categoria %s.\n", categoria);
    }
}

int filtrarTarefasPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char categoria[]) {
    int encontrou = 0;
    printf("Tarefas com prioridade %d e categoria %s:\n", prioridade, categoria);

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            printf("Tarefa: %d\n", i + 1);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %d\n", lt.tarefas[i].estado);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma tarefa encontrada com prioridade %d e categoria %s.\n", prioridade, categoria);
    }
}
int exportarTarefasPorPrioridade(ListaDeTarefas lt, int prioridade, const char arquivo[]) {
    FILE *arq;
    arq = fopen(arquivo, "w");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        return 0;
    }

    fprintf(arq, "Tarefas com prioridade %d:\n", prioridade);

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade) {
            fprintf(arq, "Tarefa: %d\n", i + 1);
            fprintf(arq, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(arq, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(arq, "Descricao: %s\n", lt.tarefas[i].descricao);
            fprintf(arq, "Estado: %d\n", lt.tarefas[i].estado);
        }
    }

    fclose(arq);
    printf("Tarefas com prioridade %d exportadas para o arquivo %s.\n", prioridade, arquivo);
    return 1;
}

int exportarTarefasPorCategoria(ListaDeTarefas lt, const char categoria[], const char arquivo[]) {
    FILE *arq;
    arq = fopen(arquivo, "w");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        return 0;
    }

    fprintf(arq, "Tarefas com categoria %s:\n", categoria);

    for (int i = 0; i < lt.qtd; i++) {
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            fprintf(arq, "Tarefa: %d\n", i + 1);
            fprintf(arq, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(arq, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(arq, "Descricao: %s\n", lt.tarefas[i].descricao);
            fprintf(arq, "Estado: %d\n", lt.tarefas[i].estado);
        }
    }

    fclose(arq);
    printf("Tarefas com categoria %s exportadas para o arquivo %s.\n", categoria, arquivo);
    return 1;
}

int exportarTarefasPorPrioridadeECategoria(ListaDeTarefas lt, int prioridade, const char categoria[], const char arquivo[]) {
    FILE *arq;
    arq = fopen(arquivo, "w");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        return 0;
    }

    fprintf(arq, "Tarefas com prioridade %d e categoria %s:\n", prioridade, categoria);

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) {
            fprintf(arq, "Tarefa: %d\n", i + 1);
            fprintf(arq, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(arq, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(arq, "Descricao: %s\n", lt.tarefas[i].descricao);
            fprintf(arq, "Estado: %d\n", lt.tarefas[i].estado);
        }
    }

    fclose(arq);
    printf("Tarefas com prioridade %d e categoria %s exportadas para o arquivo %s.\n", prioridade, categoria, arquivo);
    return 1;
}



int salvarTarefas(ListaDeTarefas *lt, const char *arquivo) {
    FILE *arq;
    arq = fopen(arquivo, "wb");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", arquivo);
        return 0;
    }

    fwrite(lt, sizeof(ListaDeTarefas), 1, arq);

    fclose(arq);
    printf("Tarefas salvas com sucesso no arquivo %s.\n", arquivo);
    return 1;
}

int carregarTarefas(ListaDeTarefas *lt, const char *arquivo) {
    FILE *arq;
    arq = fopen(arquivo, "rb");

    if (arq == NULL) {
        printf("Arquivo %s nao encontrado. Iniciando com lista vazia.\n", arquivo);
        return 0;
    }

    fread(lt, sizeof(ListaDeTarefas), 1, arq);

    fclose(arq);
    printf("Tarefas carregadas com sucesso do arquivo %s.\n", arquivo);
    return 1;
}