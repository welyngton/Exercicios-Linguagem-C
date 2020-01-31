#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void print_matriz (int **m, int dim) {

  int i, j;

  puts("");

	for (i = 0; i < dim; i++)	{
		for (j = 0; j < dim; j++)	
			printf ("%3d ", m[i][j]);	//imprime cada elemento da linha

		printf ("\n");	//termina uma linha da matriz
	}
}

int le_matriz (int **m) {

   int i, j, dim, max, maxj, swap;
	printf ("Entre com a dimensao da matriz quadrada: ");
	scanf ("%d", &dim);
	 
	m = (int **) malloc (dim * sizeof (int*)); //aloca dinamicamente uma matriz de inteiros
	for (i = 0; i<= dim; i++)
		m[i] = (int *) malloc (dim * sizeof (int));

	printf ("Entre com os elementos da matriz separados por espaco:\n");

	for (i = 0; i < dim; i++)	{
		printf ("Linha [%2d]: ", i);
		max = INT_MIN;						//menor valor possivel de um inteiro

		for (j = 0; j < dim; j++)	{
			scanf ("%d", &m[i][j]);

			 if (m[i][j] > max) {	//calcula maior valor da linha
				max = m[i][j];			//armazena o maior valor da linha em max
				maxj = j;			//armazena posicao do maior valor da linha em maxj
			}
		}
		//troca o maior elemento da linha com o elemento da diagonal
		swap = m[i][i];
		m[i][i] = m[i][maxj];
		m[i][maxj] = swap;
	}
   //system("clear");		//chama o sistema e limpa a tela do terminal
	print_matriz(m,dim);
  return(0);		//retorna o ponteiro para a matriz de inteiros (nao funciona)
}

int main () {

	int i, j, dim, max, maxj, swap;
	int **m = NULL;	//cria e inicializa uma matriz vazia
	
	le_matriz(m);
	 
	return 0;
}
