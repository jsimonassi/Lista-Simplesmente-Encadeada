#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

typedef struct banda{

    char nome [30];
    char funcao[20];
    int cod;

}Banda;


int init();
int finish();
int insere(Banda elemento);
int retira(int cod);
int busca(int cod, Banda *elemento);
int imprime();


#endif // LISTAENCADEADA_H_INCLUDED
