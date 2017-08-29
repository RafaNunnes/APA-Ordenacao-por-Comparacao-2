#include "ord.h"

void mergeSort(int *v, int inicio, int fim)
{
	int meio;
	system("clear"); //Limpa a tela
	printf("\t\tMERGE SORT\n");

	if(inicio < fim)
	{
		meio = (inicio+fim)/2;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

void merge(int *v, int inicio, int meio, int fim)
{
	int *aux, p1, p2, tam, i, j, k;
	int fim1 = 0, fim2 = 0;
	tam = fim-inicio+1;

	p1 = inicio;
	p2 = meio+1;

	aux = (int *) malloc(tam*sizeof(int));

	if(aux != NULL)
	{
		for(i=0; i<tam; i++)
		{
			if(!fim1 && !fim2)
			{
				if(v[p1]<v[p2])	//Ordena os elementos de p1 e p2
				{
					aux[i]=v[p1++];
				}
				else
				{
					aux[i]=v[p2++];
				}

				if(p1>meio) fim1=1;  //Fim do vetor p1
				if(p2>fim) fim2=1;	 //Fim do vetor p2
			}
			else
			{
				if(!fim1)
				{
					aux[i]=v[p1++];
				}
				else
				{
					aux[i]=v[p2++];
				}
			}
		}
		for(j=0, k=inicio; j<tam; j++, k++)	//Copia do vetor temporário para o vetor original
		{
			v[k]=aux[j];
		}
	}
	free(aux);
}

void quickSort(int *v, int inicio, int fim)
{
	int pivo;
	system("clear"); //Limpa a tela
	printf("\t\tQUICK SORT\n");

	if(fim > inicio)
	{
		pivo = particiona(v, inicio, fim);
		quickSort(v, inicio, pivo-1);
		quickSort(v, pivo+1, fim);
	}
}

int particiona(int *v, int inicio, int fim)
{
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = v[inicio];

	while(esq < dir)
	{
		while(v[esq] <= pivo)
			esq++;
		while(v[dir] > pivo)
			dir--;
		if(esq < dir)
		{
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}
	v[inicio] = v[dir];
	v[dir] = pivo;
	return dir;
}

void heapSort(int *v, int n)
{
	int i, aux;
	system("clear"); //Limpa a tela
	printf("\t\tHEAP SORT\n");

	for(i=(n-1)/2; i>=0; i--)	
	{
		constroiHeap(v, i, n-1);	//Constroi Heap
	}
	for(i = n-1; i>=1; i--)
	{
		aux = v[0];
		v[0] = v[i];
		v[i] = aux;
		constroiHeap(v, 0, i-1);	//Reconstroi Heap Ordenado
	}
}

void constroiHeap(int *v, int i, int f)
{
	int aux = v[i]; //Elemento pai
	int j = i*2+1;
	while(j <= f)
	{
		if(j < f)	//Possui mais de um filho
		{
			if(v[j] < v[j+1])	//Escolhe o filho maior
			{
				j = j+1;
			}
		}

		if(aux < v[j])
		{
			v[i] = v[j];
			i = j;
			j = 2*i+1;
		}
		else
		{
			j = f+1;
		}
	}
	v[i] = aux;
}