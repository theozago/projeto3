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