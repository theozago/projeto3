#include <stdio.h>
#include "proj3.h"
#include <stdlib.h>

int main() {
    int cod;
    char arquivo[100] = "tarefas";
    ListaDeTarefas lt;

    // Carrega tarefas do arquivo "tarefas" para a estrutura de dados ListaDeTarefas
    cod = carregarTarefas(&lt, arquivo);
    lt.qtd = 0; // Inicializa a quantidade de tarefas como zero

    int opcao;
    do {
        // Exibe um menu de opções para o usuário
        printMenu();
        scanf("%d", &opcao);

        if (opcao == 0) {
            break; // Terminar o programa se o usuário escolher a opção 0
        } else if (opcao == 1) {
            cadastrarTarefa(&lt); // Permite ao usuário cadastrar uma nova tarefa
        } else if (opcao == 2) {
            deletarTarefas(&lt); // Permite ao usuário deletar tarefas existentes
        } else if (opcao == 3) {
            listarTarefas(lt); // Lista todas as tarefas existentes
        } else if (opcao == 4) {
            alterarTarefa(&lt); // Permite ao usuário alterar uma tarefa existente
        } else if (opcao == 5) {
            int prioridade;
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            filtrarTarefasPorPrioridade(lt, prioridade); // Filtra tarefas por prioridade
        } else if (opcao == 6) {
            int estado;
            printf("Digite o estado para filtrar (0, 1 ou 2): ");
            scanf("%d", &estado);
            filtrarTarefasPorEstado(lt, estado); // Filtra tarefas por estado
        } else if (opcao == 7) {
            char categoria[100];
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarTarefasPorCategoria(lt, categoria); // Filtra tarefas por categoria
        } else if (opcao == 8) {
            int prioridade;
            char categoria[100];
            printf("Digite a prioridade para filtrar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para filtrar: ");
            scanf("%s", categoria);
            filtrarTarefasPorPrioridadeECategoria(lt, prioridade, categoria); // Filtra tarefas por prioridade e categoria
        } else if (opcao == 9) {
            int prioridade;
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            exportarTarefasPorPrioridade(lt, prioridade, "tarefas_prioridade.txt"); // Exporta tarefas por prioridade
        } else if (opcao == 10) {
            char categoria[100];
            printf("Digite a categoria para exportar: ");
            scanf("%s", categoria);
            exportarTarefasPorCategoria(lt, categoria, "tarefas_categoria.txt"); // Exporta tarefas por categoria
        } else if (opcao == 11) {
            int prioridade;
            char categoria[100];
            printf("Digite a prioridade para exportar: ");
            scanf("%d", &prioridade);
            printf("Digite a categoria para exportar: ");
            scanf("%s", categoria);
            exportarTarefasPorPrioridadeECategoria(lt, prioridade, categoria, "tarefas_prioridade_categoria.txt"); // Exporta tarefas por prioridade e categoria
        } else {
            printf("Opção inválida\n");
        }

    } while (opcao != 0); // O loop continua até que o usuário escolha a opção 0 para sair

    // Salva as tarefas de volta no arquivo "tarefas"
    cod = salvarTarefas(&lt, arquivo);
    if (cod != 0) {
        printf("Problema ao salvar arquivo\n");
    }

    printf("Fim\n"); // Exibe "Fim" no final do programa
    return 0;
}
