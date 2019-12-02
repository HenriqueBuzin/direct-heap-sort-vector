#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dados.h"
#include "heap.h"

int pai(int i) {
	return floor((i - 1) / 2);
}

int esquerda(int i) {
	return (2 * i + 1);
}

int direita(int i) {
	return (2 * i + 2);
}

void swap(dado_t ** dados, int a, int b) {
	dado_t *aux = dados[a];
	dados[a] = dados[b];
	dados[b] = aux;
}

void max_heapify(int i, int tam, dado_t ** dados) {
	int e = esquerda(i);
	int d = direita(i);

	int maior = 0;
	if (e < tam && (retornar_temperatura(dados[e]) > retornar_temperatura(dados[i]))) {
		maior = e;
	} else {
		maior = i;
	}

	if (d < tam && (retornar_temperatura(dados[d]) > retornar_temperatura(dados[maior]))) {

		maior = d;
	}

	if (maior != i) {
		swap(dados, i, maior);
		max_heapify(maior, tam, dados);
	}

}

void build_heap(dado_t **dados, int n_linhas) {

	for (int i = n_linhas / 2 - 1; i >= 0; i--) {
		max_heapify(i, n_linhas, dados);
	}

}

void heap_sort(dado_t **dados, int n_linhas) {

	build_heap(dados, n_linhas);

	int tam = n_linhas;

	for (int i = n_linhas - 1; i >= 1; i--) {

		swap(dados, 0, i);

		tam--;

		max_heapify(0, tam, dados);

	}

}
