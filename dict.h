#ifndef _DICT_H_
#define _DICT_H_

#include "list.h"

typedef struct dictnode {
    char index[120];
    List2D* item;
    struct dictnode* next;
} dictNode;

typedef struct dict {
    dictNode* start;
    dictNode* end;
    int lenght;
} Dict;

Dict * createDict();
int isEmptyDict(Dict *dict);
dictNode * insertDict(Dict *dict, char *index);
dictNode * search(Dict *dict, char *index);
void destroyDict(Dict *dict);
void insertDictList2DLine(Dict *dict, char *index, int line);
void printDict(Dict *dict);

#endif