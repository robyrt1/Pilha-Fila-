#include <stdio.h>
#define TAMANHOPILHA 5

struct Pilha
{
	int valor[TAMANHOPILHA];
	int fim;
};

int tamanhoPilha(Pilha *p)
{
	return p->fim + 1;
}

void iniciarPilha(Pilha *p)
{
	p->fim = -1;
}

bool pilhaCheia(Pilha *p)
{

	if (tamanhoPilha(p) == TAMANHOPILHA)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool pilhaVazia(Pilha *p)
{

	if (tamanhoPilha(p) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void exibirPilha(Pilha *p)
{
	for (int x = p->fim; x >= 0; x--)
	{
		printf("valor: %i\n", p->valor[x]);
	}
	printf("\n");
}

void empilhar(Pilha *p, int valor)
{
	if (pilhaCheia(p))
	{
		printf("A Pilha esta cheia.\n");
	}
	else
	{
		p->fim++;
		p->valor[p->fim] = valor;
	}
}

int desempilhar(Pilha *p)
{
	int valor;
	if (pilhaVazia(p))
	{
		printf("A Pilha esta Vazia.\n");
	}
	else
	{
		valor = p->valor[p->fim];
		p->fim--;
	}
	return valor;
}

void comparacao(Pilha *p, Pilha *p1)
{
	int tamPilha1 = tamanhoPilha(p);
	int tampPilha2 = tamanhoPilha(p1);
	if (tamPilha1 == tampPilha2)
	{
		printf("\n Sao iguais");
	}
	else if (tamPilha1 > tampPilha2)
	{
		printf("\n\n Pilha 1 e a maior\n\n");
	}
	else
	{
		printf("\n\n Pilha2 e a maior\n\n");
	}
}

/**    INICIO DAS FUNCOES MAIOR MENOR E MEDIA */
int maiorElemPilha(Pilha *p)
{
	int maior = 0;

	if (pilhaVazia(p))
	{
		printf("\n\n Pilha esta Vazia");
	}
	else
	{
		for (int x = p->fim; x >= 0; x--)
		{
			if (p->valor[x] > maior)
			{
				maior = p->valor[x];
			}
		}

		return maior;
	}
}

int menorElemPilha(Pilha *p)
{
	int menor = maiorElemPilha(p);

	if (pilhaVazia(p))
	{
		printf("\n\n Pilha esta Vazia");
	}
	else
	{
		for (int x = p->fim; x >= 0; x--)
		{
			// printf("\nindex : %d", x);
			if (p->valor[x] < menor && p->valor[x] > 0)
			{
				menor = p->valor[x];
			}
		}

		return menor;
	}
}

float aritPilha(Pilha *p)
{
	float media;
	float soma = 0;
	int tam = p->fim + 1;

	for (int x = p->fim; x >= 0; x--)
	{
		soma += p->valor[x];
	}

	media = soma / tam;

	return media;
}

void maiorMenorMedia(Pilha *p)
{
	printf("\n\n'%d' -  maior elemento da Pilha ", maiorElemPilha(p));
	printf("\n\n'%d' -  menor elemento da Pilha ", menorElemPilha(p));
	printf("\n\n'%.2f' -  media aritimetica da Pilha", aritPilha(p));
}

/**  FIM DAS FUNCOES MAIOR MENOR E MEDIA */

/** INICIO DAS FUNCOES PAR / IMPAR */
void ElemParPilha(Pilha *p)
{
	int count = 0;
	if (pilhaVazia(p))
	{
		printf("\n\n Pilha esta Vazia");
	}
	else
	{
		for (int x = p->fim; x >= 0; x--)
		{
			if (p->valor[x] % 2 == 0)
			{
				printf("\n\n element par : %d", p->valor[x]);
				count++;
			}
		}
		printf("\n\n Posuir %d pares", count);
	}
}

void ElemImparPilha(Pilha *p)
{
	int count = 0;
	if (pilhaVazia(p))
	{
		printf("\n\n Pilha esta Vazia");
	}
	else
	{
		for (int x = p->fim; x >= 0; x--)
		{
			if (p->valor[x] % 2 != 0)
			{
				printf("\n\n element impar: %d", p->valor[x]);
				count++;
			}
		}
		printf("\n\n Posuir %d Impare", count);
	}
}

void exibirParImpar(Pilha *p)
{
	printf("\n\n---- Elementos Pares ---- \n");
	ElemParPilha(p);
	printf("\n\n---- Elementos impares ---- \n");
	ElemImparPilha(p);
}

/** FIM DAS FUNCOES PAR / IMPAR */

void transferir(Pilha *p, Pilha* p1)
{
	printf("\n\n---- Transferindo pilha ----");
	for (int x = p->fim; x >= 0; x--){
		// printf("\n indice : %d", x);
		empilhar(p1, p->valor[x]);
	}

	printf("\n\nPilha 1:\n");
	exibirPilha(p);
	printf("\nPilha 2:\n");
	exibirPilha(p1);
}
