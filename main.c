#include <stdio.h>
#include "proj3.h"
#include <stdlib.h>

// Gabriel Lovato Camilo de Campos - 22.123.004-8
// Theo Zago Zimmermann - 22.123.035-2



//a main funciona para fazer rodar o programa no terminal e mostrar os resultados
//fizemos todas as funcoes no proj.c, na main apenas estamos chamando as funcoes para rodar perfeitamente no terminal no arquivo
int main() {
    int cod;
    char arquivo[100] = "tarefas";
    ListaDeTarefas lt;

    cod = carregarTarefas(&lt, arquivo);
    lt.qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d", &opcao);

        if (opcao==0){

        }else if(opcao==1){
            cadastrarTarefa(&lt);
        }else if(opcao==2){
            deletarTarefas(&lt);
        }else if(opcao==3){
            listarTarefas(lt);
        }else if (opcao == 4) {
            alterarTarefa(&lt);
        }else{
            printf("opcao invalida\n");
        }
        printf("%d\n", opcao);
    } while (opcao != 0);

    cod = salvarTarefas(&lt, arquivo);
    if (cod != 0){
        printf("problema ao salvar arquivo\n");
    }

    printf("fim\n");
    return 0;
}
