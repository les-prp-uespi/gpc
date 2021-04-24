#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct No
{
	int valor;
	struct No *esq;
	struct No *dir;
};

typedef struct No *ArvBin;

ArvBin *criaArvore();
int insereElemento(ArvBin *raiz, int valor);
void liberaNo(struct No *no);
void liberaArvore(ArvBin *raiz);
void preOrdem(ArvBin *raiz);
void emOrdem(ArvBin *raiz);
void posOrdem(ArvBin *raiz);


int main ()
{
	int teste;
	int tam;
	int numero;
	int cont = 1;
	while (scanf("%d", &teste) != EOF)
	{
		while (teste--)
		{
			scanf("%d", &tam);
			ArvBin *raiz = criaArvore();
			while (tam--)
			{
				scanf("%d", &numero);
				insereElemento(raiz, numero);
			}
			printf("Case %d:\n", cont);
			cont++;
			printf("Pre.:");
			preOrdem(raiz);
			printf("\n");
			printf("In..:");
			emOrdem(raiz);
			printf("\n");
			printf("Post:");
			posOrdem(raiz);
			printf("\n\n");
			liberaArvore(raiz);
		}

	}
	return(0);
}


ArvBin *criaArvore()
{
	ArvBin *raiz = malloc(sizeof(ArvBin));
	if(raiz)
		*raiz = NULL;
	return raiz;
}

void liberaNo(struct No *no)
{
	if(no == NULL)return;
	liberaNo(no->esq);
	liberaNo(no->dir);
	free(no);
	no = NULL;
}

void liberaArvore(ArvBin *raiz)
{
	if(raiz == NULL) return;
	liberaNo(*raiz);
	free(raiz);
	raiz = NULL;
}
int insereElemento(ArvBin *raiz, int valor)
{
	if(raiz == NULL)
		return 0;
	struct No *novo;
	novo = malloc(sizeof(struct No));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->valor = valor;
	if(*raiz == NULL)
	{
		*raiz = novo;
	}
	else
	{
		struct No *atual = *raiz;
		struct No *anterior = NULL;

		while(atual)
		{
			anterior = atual;
			if(atual->valor == valor)
			{
				free(novo);
				return 0;
			}
			if(atual->valor < valor)
				atual = atual->dir;
			else
				atual = atual->esq;
		}
		if(anterior->valor < valor)
			anterior->dir = novo;
		else
			anterior->esq = novo;
	}
	return 1;
}

// visita a raiz, o filho a esquerda e o filho da direita
void preOrdem(ArvBin *raiz)
{
	if (raiz == NULL)
		return;
	if(*raiz != NULL)
	{
		printf(" %d", (*raiz)->valor);
		preOrdem(&((*raiz)->esq));
		preOrdem(&((*raiz)->dir));
	}
}

// Visita o filho da esquerda, a raiz e filho da direita
void emOrdem(ArvBin *raiz)
{
	if (raiz == NULL)
		return;
	if(*raiz != NULL)
	{
		emOrdem(&((*raiz)->esq));
		printf(" %d", (*raiz)->valor);
		emOrdem(&((*raiz)->dir));
	}
}

// visita o filho da esquerda, o filho da direita e a raiz
void posOrdem(ArvBin *raiz)
{
	if (raiz == NULL)
		return;
	if(*raiz != NULL)
	{
		posOrdem(&((*raiz)->esq));
		posOrdem(&((*raiz)->dir));
		printf(" %d", (*raiz)->valor);
	}
}
