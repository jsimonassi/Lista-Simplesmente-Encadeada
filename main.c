#include "TAD_Fila.h"

int insere_menu(int cod){
    Banda a;

    printf("\n\nDigite o nome: ");
    scanf("%s", a.nome);

    printf("Digite a funcao na banda: ");
    scanf("%s", a.funcao);
    a.cod = cod;

    if(insere(a))
        printf("\nInserido! Seu codigo e: %d", a.cod);

    return cod += 1;
}

void retira_menu(){
    int cod;
    printf("\n\nDigite o codigo: ");
    scanf("%d", &cod);
    retira(cod);
    return;
}

void busca_menu(){
    int cod;
    Banda aux;
    printf("\n\nDigite o codigo da busca: ");
    scanf("%d", &cod);
    if(busca(cod, &aux)){
        printf("\nNome: %s\n", aux.nome);
        printf("Funcao: %s", aux.funcao);
        return;
        }

    printf("\n\nNao achei!!");
    return;

}


int main()
{
    int opcao, cod = 0;

    while(TRUE){

        printf("\n------------------------------\nInsere ------ [1]\n");
        printf("Retira ------ [2]\n");
        printf("Imprime ----- [3]\n");
        printf("Busca ------- [4]\n");
        printf("Sair -------- [5]\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1)
            cod = insere_menu(cod);

        else if(opcao == 2)
            retira_menu();

        else if(opcao == 3)
            imprime();

        else if(opcao == 4)
            busca_menu();

        else if(opcao == 5){
            finish();
            exit(0);
            }

        else printf("Digitou errado\n\n");
     }

    return 0;
}
