#include <stdio.h>
#include "proj3.h"
#include <stdlib.h>

int main() {
    int cod;
    char arquivo[100] = "tarefas";
    ListaDeTarefas lt;

    cod = carregarTarefas(&lt, arquivo);
    lt.qtd = 0;

    int opcao;
    do {
        printMenu();
        scanf("%d", &opcao);

        if (opcao == 0) {
            break; // Terminar o programa
        } else if (opcao == 1) {
            cadastrarTarefa(&lt);
        } else if (opcao == 2) {
            deletarTarefas(&lt);
        } else if (opcao == 3) {
            listarTarefas(lt);
        } else if (opcao == 4) {
            alterarTarefa(&lt);
        }else if (opcao == 5) {
            int prioridade;
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            filtrarTarefasPorPrioridade(lt, prioridade);
        } else if (opcao == 6) {
            int estado;
            printf("Digite o estado para filtrar (0, 1 ou 2): ");
            scanf("%d", &estado);
            filtrarTarefasPorEstado(lt, estado);
        }else if (opcao == 7) {
            char categoria[100];
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarTarefasPorCategoria(lt, categoria);
        } else if (opcao == 8) {
            int prioridade;
            char categoria[100];
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarTarefasPorPrioridadeECategoria(lt, prioridade, categoria);
        }else if (opcao == 9) {
            int prioridade;
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            exportarTarefasPorPrioridade(lt, prioridade, "tarefas_prioridade.txt");
        } else if (opcao == 10) {
            char categoria[100];
            printf("Digite a categoria para exportar: ");
            scanf("%s", categoria);
            exportarTarefasPorCategoria(lt, categoria, "tarefas_categoria.txt");
        } else if (opcao == 11) {
            int prioridade;
            char categoria[100];
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para exportar: ");
            scanf("%s", categoria);
            exportarTarefasPorPrioridadeECategoria(lt, prioridade, categoria, "tarefas_prioridade_categoria.txt");
        } else {
            printf("Opção inválida\n");
        }

    } while (opcao != 0);

    cod = salvarTarefas(&lt, arquivo);
    if (cod != 0) {
        printf("Problema ao salvar arquivo\n");
    }

    printf("Fim\n");
    return 0;
}