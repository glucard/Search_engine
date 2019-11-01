#ifndef _LIST_H_
#define _LIST_H_

typedef struct list2dnode {
    int *info;
    struct list2dnode *next;
} List2DNode;

typedef struct list2d{
    List2DNode *start;
    List2DNode *end;
    int lenght;
} List2D;

List2D * createList2D();
int isEmptyList2D(List2D *list);
void insertList2D(List2D *list, int vector2D[2]);
List2DNode * searchList2D(List2D *list, int line);
void destroyList2D(List2D *list);
void printList2D(List2D *list);

#endif