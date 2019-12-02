#ifndef HEAP_INCLUDED

#include "dados.h"

typedef struct heaps heap_t;

int pai(int i);

int esquerda(int i);

int direita(int i);

void swap(dado_t ** dados, int a, int b);

void max_heapify(int i, int tam, dado_t ** dados);

void build_heap(dado_t **dados, int n_linhas);

void heap_sort(dado_t **dados, int n_linhas);


#endif
