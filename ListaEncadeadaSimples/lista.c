/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"

struct lista  
{
	int info;
	struct lista *prox;
};

Lista *lst_cria(void)   /*Função para criar a lista que recebe nada como parâmetro e retorna nada.*/
{
	return NULL;
}

Lista *lst_insere(Lista *l, int v)  /*Função para inserir que tem como parâmetro um ponteiro do tipo Lista e uma varíavel inteiro*/
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));  /*Cria um ponteiro do tipo Lista dinamicamente*/
	if (novo == NULL) /*Checa se a variável não tem nada, caso verdadeiro ele printa a mensagem e encerra o programa*/
	{
		printf("[ERRO] memoria insuficiente!"); /*Mensagem de erro*/
		exit(1); /*Sai do programa*/
	} /*Caso essa condição é falsa ele executa os códigos abaixo*/

	novo->info = v; /*A variável novo que aponta para a variável info da struct recebe o parâmetro v é o numero inteiro*/
	novo->prox = l; /*A variável novo que aponta para um ponteiro do tipo struct lista (dentro da struct) e recebe o ponteiro do tipo lista (l). novo->prox recebe a ultima raiz*/
	return novo; /*Retorna a variável novo*/

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

int lst_vazia(Lista *l) /*Função que tem como parâmetro um ponteiro do tipo lista (l)*/
{
	return (l == NULL);  //retorna o ponterio sendo igual a nada (null) para usar na condição no main
}

void lst_imprime(Lista *l) //Função para imprimir na tela que tem como parâmetro um ponteiro do tipo lista
{
	Lista *p; //contador do tipo lista que é um ponteiro
	for (p = l; p != NULL; p = p->prox) //p que recebe o endereço de l; p que vai fazer o lopp até encontrar null(nada), p que recebe o endereço do ponteiro prox que p aponta
	{ //ele imprimi ao contrário, pois ele pega o último nó (a última lista) e vai precisar desse incremento para achar os outros nós até que ele ache null(nada) que no caso
	  //é o inicio da lista (momento que foi criado)
		printf("\tInfo = %d \n", p->info); //mostra os numeros armazenados na variável info
	}
}

Lista *lst_busca(int elemento, Lista *l) //Função para buscar na lista que tem como parâmetros uma variável do tipo inteiro e um ponteiro do tipo lista
{
	Lista *p;  //ponteiro do tipo lista para servir como contador
	for (p = l; p != NULL; p = p->prox) //contador (p) recebe a lista (l); vai fazer o loop até encontrar null (nada); e vai receber o incremento para o próximo nó
	{ //ele pega sempre o último nó feito, e vai precisar do incremento para achar o outro até achar null

		if (p->info == elemento) //a variável que p aponta (info) recebe a variável (parâmetro) elemento, caso essa condição seja verdadeira ele retorna p (contador)
								 //caso a condição seja falsa ele retorna null (nada)
			return p; 
	}

	return NULL;
}

Lista *lst_retira(Lista *l, int v) //Função para retirar elemento da lista que tem como parâmetros um ponteiro do tipo lista e uma variável do tipo inteiro
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */   // Ponteiro do tipo lista que recebe null (nada) que vai servir para o elemento anterior
	Lista *p = l;	   /* ponteiro para percorrer a lista*/    // Ponteiro do tipo lista que recebe o endereço do ponteiro l (parâmetro) que vai servir como contador
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)  // enquanto p que aponta para info (variável da struct) for diferent da variável do tipo inteiro (parâmentro) ele vai executar 
	{
		if (p == NULL)
			return l; /* n�o achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

void lst_libera(Lista *l)
{
	Lista *p = l;
	Lista *t;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

Lista *lst_insere_ordenada(Lista *l, int v)
{
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	while (p != NULL && p->info < v)
	{
		ant = p;
		p = p->prox;
	}
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = v;
	if (ant == NULL)
	{
		novo->prox = l;
		l = novo;
	}
	else
	{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)
	{
		l = lst_insere(l, valor);
	}
	fclose(arquivo);
	return l;
}
