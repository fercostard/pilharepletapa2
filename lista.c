#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

struct node{
      char key[15];
      int value;
      struct node* prox;
      
};

struct lista{
      struct node* inicio;
      
};

static struct node* lista_find(Lista* l, char* key){
      struct  node* prox = l->inicio;
      while (prox){
            if(strcmp(prox->key,key)==0){
                  return prox;
            }
            prox = prox->prox;
      }
      return NULL;
};


Lista* new_lista(){
      Lista* l = calloc(1,sizeof(Lista));
      l->inicio = NULL;
      return l;
}

void lista_append(Lista* l, char* key, int value){
      struct node* node = calloc(1,sizeof(struct node));
      strcpy(node->key, key);
      node->value = value;
      node->prox = l->inicio;
      l->inicio = node;   
}

int lista_get(Lista* l, char* key){
      struct node* n;
      if((n = lista_find(l, key)) != NULL){
            return n->value;
      }
      return  -1;
}


void lista_set(Lista* l, char* key, int value){
      struct node* n;
      if((n = lista_find(l, key)) != NULL){
            n->value = value;
      }  
}


int lista_exist(Lista* l, char* key){
      return lista_find(l, key) != NULL;
}


int lista_print(Lista* l){
      struct node* prox = l->inicio;
      printf("---LISTA---");
      while(prox){
            printf("%s -> %d\n",prox->key, prox->value);
            prox = prox->prox;
      }
      printf("-----------");

};




