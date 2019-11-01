#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

Dict * createDict(){
    Dict* dict = (Dict*) malloc(sizeof(Dict));
    dict->start = dict->end = NULL;
    dict->lenght = 0;
    return dict;
}

int isEmptyDict(Dict *dict){
    return (dict->lenght == 0);
}

dictNode * insertDict(Dict *dict, char *index){
    dictNode *dnode;
    dnode = search(dict, index);
    if(dnode == NULL){
        dnode = (dictNode*) malloc(sizeof(dictNode));
        List2D* list2D = createList2D();
        strcpy(dnode->index, index);
        dnode->item = list2D;
        dnode->next = NULL;

        if(isEmptyDict(dict)){
            dict->start = dnode;
        }else{
            dict->end->next = dnode;
        }
        dict->end = dnode;
        dict->lenght++;
    }
    return dnode;
}

dictNode * search(Dict *dict, char *index){
    dictNode* aux_dnode;
    for (aux_dnode = dict->start; aux_dnode != NULL; aux_dnode = aux_dnode->next)
        if (!strcmp(aux_dnode->index, index))
            return aux_dnode;
    return NULL;
}

void destroyDict(Dict *dict){
    dictNode *aux_dnode, *ant;
    aux_dnode = dict->start;
    while(aux_dnode != NULL){
        ant = aux_dnode;
        aux_dnode = aux_dnode->next;
        free(ant);
    }
    free(dict);
}

void insertDictList2DLine(Dict *dict, char *index, int line){
    dictNode *aux_dnode = insertDict(dict, index);
    List2DNode *aux_l2dnode = searchList2D(aux_dnode->item, line);
    if(aux_l2dnode == NULL){
        int vector2D[2] = {line, 1};
        insertList2D(aux_dnode->item, vector2D);
    }else{
        aux_l2dnode->info[1] += 1;
    }
}

void printDict(Dict *dict){
    dictNode *p;
    for(p = dict->start; p!=NULL;p=p->next){
        printf("%s -> ", p->index);
        printList2D(p->item);
    }
    printf("\n");
}