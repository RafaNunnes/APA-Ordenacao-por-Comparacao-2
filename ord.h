#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *v, int inicio, int fim);

void merge(int *v, int inicio, int meio, int fim);

void quickSort(int *v, int inicio, int fim);

int particiona(int *v, int inicio, int fim);

void heapSort(int *v, int n);

void constroiHeap(int *v, int i, int f);