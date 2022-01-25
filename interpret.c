#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"
#include "lista.h"


Stack *s = NULL;
Lista *l = NULL;

void iniciar(){
    s = new_stack(100);
    l = new_lista();
}

void interpret (const char *source) {
    char op[100];
    char arg[100];

    sscanf (source, "%s%s", op, arg);
    printf("operação: %s\n", op);
    printf("argumento: %s\n",  arg);

    if (strcmp(op, "push") == 0){
        int value;
        if(sscanf(arg,"%d",&value) == 0){
            value = lista_get(l,arg);
        }
        stack_push(s,value);
    }
    else if (strcmp(op, "add") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s,arg1+arg2);
    }
    else if (strcmp(op, "sub") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s,arg1-arg2);
    }
    else if (strcmp(op, "div") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s,(arg1/arg2));
    }
    else if (strcmp(op, "mul") == 0){
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s,arg1*arg2);
    }
    else if (strcmp(op, "print") == 0){
        int arg1 = stack_pop(s);
        printf("Elemento %d removido da pilha!\n", arg1);

    }
    else if (strcmp(op, "pop") == 0){
        int arg1 = stack_pop(s);
        if(lista_exist(l,arg)){
            lista_set(l,arg,arg1);
        }else{
            lista_append(l,arg,arg1);
        }
       
    }

    

    stack_print(s);
}

