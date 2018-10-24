#include "TAD_Fila.h"

typedef struct node{ //Estrutura do Node
    Banda integrante;
    struct node *prox;
}Node;

Node *ini, *fim;

int init(){
    ini = fim = NULL;
    return TRUE;
}

int insere(Banda elemento){
    Node *novo = (Node *) malloc(sizeof(Node)); //Cria um novo nó
    novo->integrante = elemento; // Novo nó recebe as informações

    if(!ini){ //(ini == NULL) 1º elemento
        ini = novo;
        ini->prox = NULL;
        fim = novo;
        return TRUE;
    }
    //Caso já exista algum elemento, insere no fim da lista
    fim->prox = novo;
    fim = novo;
    fim->prox = NULL;
    return TRUE;
}

int retira(int cod){

    if(ini == NULL) // Lista vazia
        return FALSE;

    Node *aux = ini;//Cria um auxiliar pra não perder a refrÊncia da posição
    if(ini->integrante.cod == cod){ // Elemento na primeira posição da lista
        ini = ini->prox; // Atualizo inicio
        free(aux);// libero o primeiro no
        return TRUE;
    }

    Node *anterior = NULL;
    while(aux->integrante.cod != cod && (aux)){
        anterior=aux; //Deixa "anterior" no elemento anterior ao que vai ser excluido
        aux=aux->prox; // Aponta aux para quem vai ser excluido
    }

    if(aux){ // Aux é um endereço válido?
        anterior->prox = aux->prox; //Liga o elemento anterior ao seguinte do que vai ser excluido
        free(aux);
        return TRUE;
    }
    return FALSE; // Aux não era um endereço válido, elemento não encontrado
}


int busca(int cod, Banda *elemento){
    Node *aux = ini;

    while((aux) && (cod != aux->integrante.cod)){ // Aux é um endereço válido e o elemento é diferente do que eu procuro?
        aux = aux->prox; // Não achei o elemnto, ando para frente
    }
    if(aux){ // O elemento que eu achei é válido ou eu saí da repetição pq a lista acabou? aux != NULL
        *elemento = aux->integrante; //Coloca o valor do elemento lá na variável da main, através do ponteiro
        return TRUE;
        }
    return FALSE; // Era NULL, não achei :(
}


int imprime(){
    Node *aux = ini;

    while(aux){ // Enquanto tem lista, imprime geral
        printf("%s -> ", aux->integrante.nome);
        aux=aux->prox;
        }
    return TRUE;
}

int finish(){

    if(ini){ // Tem gente na lista??
        Node *aux = ini;
        while(ini){ // Enquanto tiver gente eu vou limpando a memória
            ini=ini->prox;
            free(aux);
            aux = ini;
        }
    }
    return TRUE;
}
