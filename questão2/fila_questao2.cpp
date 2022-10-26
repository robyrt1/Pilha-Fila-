#include <stdio.h>
#define TAMANHOFILA 5

struct Fila{
	int valor[TAMANHOFILA];
	int inicio;
	int fim;
};

int tamanhoFila(Fila* fila){
	return fila->fim + 1;
}

void iniciarFila(Fila* fila){
	fila->inicio = 0;
	fila->fim = -1;
}

bool filaCheia(Fila* fila){
	
	if(tamanhoFila(fila) == TAMANHOFILA){
		return true;
	}else{
		return false;
	}
}

bool filaVazia(Fila* fila){
	
	if(tamanhoFila(fila) == 0){
		return true;
	}else{
		return false;
	}
}

void exibirFila(Fila* fila){
	for(int x = 0; x <= fila->fim; x++){
		printf("%i, ", fila->valor[x]);
	}
	printf("\n");
}

void enfileira(Fila* fila, int valor){
	if(filaCheia(fila)){
		printf("A fila esta cheia.\n");
	}else{
		fila->fim++;
		fila->valor[fila->fim] = valor;
	}
}

int desenfileira(Fila* fila){
	int valor;
	if(filaVazia(fila)){
		printf("A fila esta Vazia.\n");
	}else{
		valor = fila->valor[fila->inicio];
		for(int x = 0; x <= fila->fim; x++){
			fila->valor[x] = fila->valor[x+1];
		}
		fila->fim--;
	}
	return valor;
}


void comparacao(Fila* fila, Fila* fila1)
{
	int tamFila1 = tamanhoFila(fila);
	int tampFila2 = tamanhoFila(fila1);

	printf("\n\n----Comparacao----");
	if (tamFila1 == tampFila2)
	{
		printf("\n Sao iguais");
	}
	else if (tamFila1 > tampFila2)
	{
		printf("\n\n Fila 1 e a maior\n\n");
	}
	else
	{
		printf("\n\n Fila 2 e a maior\n\n");
	}
}

int maiorElemFila(Fila* fila)
{
	int maior = 0;

	if (filaVazia(fila))
	{
		printf("\n\n fila esta Vazia");
	}
	else
	{
		for (int x = fila->inicio; x <= fila->fim; x++)
		{
			if (fila->valor[x] > maior)
			{
				maior = fila->valor[x];
			}
		}

		return maior;
	}
}

int menorElemFila(Fila* fila)
{
	int menor = maiorElemFila(fila);

	if (filaVazia(fila))
	{
		printf("\n\n fila esta Vazia");
	}
	else
	{
		for (int x = fila->inicio; x <= fila->fim; x++)
		{
			if (fila->valor[x] < menor && fila->valor[x] > 0)
			{
				menor = fila->valor[x];
			}
		}

		return menor;
	}
}

float aritiFila(Fila* fila){
	float media;
	float soma =0;
	int tam= fila->fim + 1;

	for(int x = 0; x <= fila->fim; x++)
    {
		soma += fila->valor[x];
	}
	// printf("\n SOMA: %F")
	media = soma/tam;
	return media;
}

void maiorMenorMedia(Fila* fila){
	printf("\n\n----Maior Elemento da Fila----\n");
	printf("\n Valor: %d", maiorElemFila(fila));
	printf("\n\n----Menor Elemento da Fila----\n");
	printf("\n Valor: %d", menorElemFila(fila));;
	printf("\n\n----Media dos Elementos da Fila----\n");
	printf("\n Media: %.2f", aritiFila(fila));
}


void ElemParFila(Fila* fila)
{
	int count = 0;
	if (filaVazia(fila))
	{
		printf("\n\n Fila esta Vazia");
	}
	else
	{
		for (int x = 0; x <= fila->fim ; x++)
		{
			if (fila->valor[x] % 2 == 0)
			{
				printf("\n\n element par : %d", fila->valor[x]);
				count++;
			}
		}
		printf("\n\n Posuir %d pares", count);
	}
}

void ElemImparFila(Fila* fila)
{
	int count = 0;
	if (filaVazia(fila))
	{
		printf("\n\n Fila esta Vazia");
	}
	else
	{
		for (int x = 0; x <= fila->fim ; x++)
		{
			if (fila->valor[x] % 2 != 0)
			{
				printf("\n\n element impar: %d", fila->valor[x]);
				count++;
			}
		}
		printf("\n\n Posuir %d Impares", count);
	}
}

void exibirParImpar(Fila *fila)
{
	printf("\n\n---- Elementos Pares ---- \n");
	ElemParFila(fila);
	printf("\n\n---- Elementos impares ---- \n");
	ElemImparFila(fila);
}


void transferir(Fila *fila, Fila* fila1)
{
	printf("\n\n---- Transferindo Fila ----");
	for (int x = 0; x <= fila->fim ; x++){
		// printf("\n indice : %d", x);
		enfileira(fila1, fila->valor[x]);
	}

	printf("\n\nFila 1:\n");
	exibirFila(fila);
	printf("\nFila 2:\n");
	exibirFila(fila1);
}