#include <stdio.h>
#include <stdlib.h>

#include "interpret.h"

static void repl()
{
  char line[1024];
  for (;;)
  {
    printf("> ");

    if (!fgets(line, sizeof(line), stdin))
    {
      printf("\n");
      break;
    }

    interpret(line);
  }
}

int ler_arquivo(char* path){
  FILE *arquivo = fopen(path, "r");
  char line[100];
  
  if(arquivo == NULL){
    printf("Erro ao abrir o arquivo!!\n");
    getchar();
    exit(0);
  }

  while (fgets(line,100,arquivo) != NULL) {
    interpret(line);
  }

  fclose(arquivo);
  
}


int main (int argc, char** argv) {

    iniciar();
    if(argc == 1){
    repl();
    }
    else{
      char* path = argv[1];
      ler_arquivo(path);

    }
    return 0;
}

