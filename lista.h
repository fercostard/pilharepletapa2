#ifndef lista_h
#define lista_h


typedef struct  lista Lista;

Lista* new_lista();
void lista_append(Lista* s, char* key, int value);
int lista_get(Lista* s, char* key);
void lista_set(Lista* s, char* key, int value);
int lista_exist(Lista* s, char* key);
int lista_print(Lista* s);




#endif
