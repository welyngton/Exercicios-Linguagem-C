#include <stdio.h>
#include <string.h>

#define TAM_MAX 250		//tamanho do buffer da string

int conta_vogal (char str[TAM_MAX]) {

	int i=0, contV=0;

	for (i = 0; str[i]; i++)	{

		switch(str[i]) {
		  case 'a':
		  case 'e':
		  case 'i':
		  case 'o':
		  case 'u':
		  case 'A':
		  case 'E':
		  case 'I':
		  case 'O':
		  case 'U':	contV++; //contador de vogais
		  break;
		  default:	//caso nao seja vogal nao conta
		  break;
		 }
	 }

  return(contV);
}

int main () {

	char s[TAM_MAX];

	printf ("Entre com uma string (max %d): ",TAM_MAX);

	fgets(s,TAM_MAX, stdin);	//string com buffer definido

	printf ("O numero de vogais da string eh: %d.\n\n", conta_vogal(s));

	return 0;
}
