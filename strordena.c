#include <stdio.h>
#include <limits.h>

/*___________________________________
 * Pos	| Char	|	Ascii	|	Ordem |
 * 0		|	A		|	65		|	0		|
 * 1		|	a		|	97		|			|
 * 2		|	B		|	66		|	1		|
 * ...		..			...		...
*/

#define TAM_MAX 250
#define NUM ('Z' - 'A' + 1 + 'z' - 'a' + 1)

int ascii_to_index (int c) {

	if (c >= 'A' && c <= 'Z')
		return (c - 'A') * 2;
	else if (c >= 'a' && c <= 'z')
		return (c - 'a') * 2 + 1;

	return -1;
}

int index_to_ascii (int a) {
	
  if (a % 2 != 0)
		return 'a' + a / 2;
	else
		return 'A' + a / 2;
}

int print_string (int caract[NUM]) {

  char c;
  int i, j;

  printf("String Ordenada: ");
	for (i = 0; i < NUM; i++) {

		c = index_to_ascii (i);

		for (j = 0; j < caract[i]; j++)
			printf ("%c", c);
	}
	printf ("\n\n");
  return(0);
}

int le_string(int caract[NUM]) {

	char c;
	int i=0, a;
	int tam = TAM_MAX;

	printf ("Entre com uma string (max %d): ",tam);

	do {
		scanf ("%c", &c);
		a = ascii_to_index (c);

		if (a >= 0)
			caract[a]++;
	} while (c != '\n' && ++i < tam);
  
  print_string(caract);

  return(0);
}

int main () {

	int caract[NUM] = { 0 };
	
	le_string(caract);

	return 0;
}
