#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "dict.h"


List2D * createList2D(){
    List2D *list = (List2D*) malloc(sizeof(List2D));
    list->start = list->end = NULL;
    list->lenght = 0;
    return list;
}

int isEmptyList2D(List2D *list){
    return (list->lenght == 0);
}

void insertList2D(List2D *list, int *vector2D){
    List2DNode *new = (List2DNode*) malloc(sizeof(List2DNode));
    new->info = malloc(2*sizeof(int)); //TO PUTO
    new->info[0] = vector2D[0];
    new->info[1] = vector2D[1];
    new->next = NULL;
    if (isEmptyList2D(list))
        list->start = new;
    else
        list->end->next = new;
    list->end = new;
    list->lenght++;
}

List2DNode * searchList2D(List2D *list, int line){
    List2DNode* aux;
    for (aux = list->start; aux != NULL; aux = aux->next)
        if (aux->info[0] == line)
            return aux;
    return NULL;
}

void destroyList2D(List2D *list){
    List2DNode *aux, *ant;
    aux = list->start;
    while(aux != NULL){
        ant = aux;
        aux = aux->next;
        free(ant);
    }
    free(list);
}

void printList2D(List2D *list){
    List2DNode *p;
    for (p = list->start; p!=NULL;p=p->next)
        printf("(%d | %d) ", p->info[0], p->info[1]);
    printf("\n");
}