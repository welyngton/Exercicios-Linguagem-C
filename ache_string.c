#include <stdio.h>
#include <string.h>
#define TAM_MAX 250
#define MAX_FRS 50

typedef struct lista_frases {
	char frase[TAM_MAX];
	int T;
}TP_frases;

//Le as frases e retorna o numero total de frases.
int LE_strings(TP_frases str[]) {

	int i,T;

	printf("Qual o numero de frases que deseja entrar: (max %d)\n",MAX_FRS);

	scanf("%d",&T);
	while(getchar()!='\n');
	for(i=0;i<T;++i){
		printf("Frase %d: ",i+1);
		gets(str[i].frase);
		str[i].T = strlen(str[i].frase);
	}
	return T;
}


void ACHA_string (TP_frases lsfra[], char str[], int NumFrs) {

	int i,j,n,T,igual,cont,ocor;
	T=strlen(str);
	for(n=0,ocor=0; n<NumFrs; ++n){
		for(i=0, cont=0 ; i<lsfra[n].T; ++i)
			if(lsfra[n].frase[i]==str[0]){
				for(j=1,igual=1; (j<T)&&(igual); ++j)
					if(lsfra[n].frase[i+j]!=str[j])
						igual=0;
				if(igual==1){
					ocor=1;
					cont++;
				}
			}
		if (cont)
			printf("%s ocorre %d vez(es) na frase %d.\n",str,cont,n+1);
	}
	if (!ocor)
			printf("%s nao ocorre nenhuma vez na(s) frase(s).\n",str);
}


int main() {

	TP_frases frase[MAX_FRS];
	char palavra[TAM_MAX];
	int NumFrs;

	NumFrs = LE_strings(frase);

	printf("Palavra: ");
	gets(palavra);
	while(getchar()!='\n'); 	//captura o \n do teclado
	while ((strcmp(palavra,"FIM"))!=0){
		ACHA_string(frase,palavra,NumFrs);
		printf("Palavra: ");
		gets(palavra);
	}
	return (0);
}
