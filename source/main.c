#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

void upperLetter(char *c){
    if(*c > 96 && *c < 96 + 32){
        *c-=32;
    }
}
void upperWord(char *word){
    int i;
    for (i = 0; word[i] != '\0'; i++) upperLetter(&word[i]);
}

int getNextFirstLetterFile(FILE *file, char *word, char *end_symbol){
    fscanf(file, "%s", word);
    if(fscanf(file, "%c", end_symbol) != EOF){
        if(*end_symbol == '\n' || *end_symbol == ' ') return 1;
    }
    return 0;
}

int main(void){
    FILE *arquivo;
    arquivo = fopen("arq.txt","r");
    if(arquivo == NULL){
        printf("Erro ao ler arquivo");
        return 1;
    }

    Dict *dict = createDict();
    
    char word[120], last_end_symbol;
    int line = 0;
    while(getNextFirstLetterFile(arquivo, word, &last_end_symbol)){
        upperWord(word);
        insertDictList2DLine(dict, word, line);
        if(last_end_symbol == '\n') line++;
    }
    printDict(dict);
    destroyDict(dict);
    fclose(arquivo);
    return 0;
}