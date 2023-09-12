/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"

struct lista  
{
	int nome[50];
	struct lista *prox;
};

Lista *lst_cria(void)   /*Função para criar a lista que recebe nada como parâmetro e retorna nada.*/
{
	return NULL;
}

Lista *lst_insere(Lista *l, char v[50])  /*Função para inserir que tem como parâmetro um ponteiro do tipo Lista e uma varíavel inteiro*/
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));  /*Cria um ponteiro do tipo Lista dinamicamente*/
	if (novo == NULL) /*Checa se a variável não tem nada, caso verdadeiro ele printa a mensagem e encerra o programa*/
	{
		printf("[ERRO] memoria insuficiente!"); /*Mensagem de erro*/
		exit(1); /*Sai do programa*/
	} /*Caso essa condição é falsa ele executa os códigos abaixo*/

	strcpy(novo->nome, v); /*A variável novo que aponta para a variável info da struct recebe o parâmetro v é o numero inteiro*/
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
		printf("\tInfo = %d \n", p->nome); //mostra os numeros armazenados na variável info
	}
}

Lista *lst_busca(char elemento[50], Lista *l) //Função para buscar na lista que tem como parâmetros uma variável do tipo inteiro e um ponteiro do tipo lista
{
	Lista *p;  //ponteiro do tipo lista para servir como contador
	for (p = l; p != NULL; p = p->prox) //contador (p) recebe a lista (l); vai fazer o loop até encontrar null (nada); e vai receber o incremento para o próximo nó
	{ //ele pega sempre o último nó feito, e vai precisar do incremento para achar o outro até achar null

		if (p->nome == elemento) //a variável que p aponta (info) recebe a variável (parâmetro) elemento, caso essa condição seja verdadeira ele retorna p (contador)
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
	while (p->nome != v)  // enquanto p que aponta para info (variável da struct) for diferent da variável do tipo inteiro (parâmentro) ele vai executar 
	{
		if (p == NULL) //caso p seja igual a null (nada) e seja verdadeiro ele retorna l, caso não ele continua o código
			return l; /* n�o achou: retorna lista original */
		ant = p; //ponteiro ant que recebe o endereço de p, recebe o dado inteiro atual
		p = p->prox; //p que recebe o endereço de prox
		/* verifica se achou elemento */
	} // OBS.: LEMBRE que ele começa a pegar do último nó (aqui usa a mesma LÓGICA do incremento)
	/* retira elemento */
	if (ant == NULL) // Se ant for igual a null (nada) e for verdadeiro ele executa:
		/* retira elemento do inicio */
		l = p->prox; //ponteiro l recebe o endereço de prox (que vai ser o nó)
	else //caso não seja verdadeiro executa: 
		/* retira elemento do meio da lista */
		ant->prox = p->prox;  //ant que aponta pra prox recebe o endereço de prox
	free(p); //libera a memória
	return l; // retorna a lista
}

void lst_libera(Lista *l) // Função para liberar a memória que tem como parâmetro um ponteiro do tipo lista
{
	Lista *p = l; // Ponteiro do tipo lista que recebe o endereço de l e vai servir como contador
	Lista *t; // Ponteiro para servir de auxiliar
	while (p != NULL) // Enquanto p(contador) for diferente de null (nada) executa:
	{
		t = p->prox; // Ponteiro que recebe o endereço de prox
		free(p); // Libera a memória de p
		p = t; // E p recebe o último endereço que t estava guardando
	}
}

Lista *lst_insere_ordenada(Lista *l, char v[50]) // Função para ordenar a lista
{
	Lista *novo; // Ponteiro do tipo lista
	Lista *ant = NULL; // Ponteiro do tipo lista que é inicializada com null (nada)
	Lista *p = l; // Ponteiro do tipo lista que recebe o endereço de lista para ser o contador
	while (p != NULL && p->nome < v) // Enquanto p for diferente de null (nada) e o dado de info seja menor do numero inteiro v do parâmetro executa: 
	{
		ant = p; // ant recebe o endereço de p (contador) (nó anteiror)
		p = p->prox; // p recebe o endereço de prox (próximo nó)
	}
	novo = (Lista *)malloc(sizeof(Lista)); // Cria um vetor dinâmico
	strcpy(novo->nome, v); // novo que aponta para info recebe o valor inteiro v (do parâmetro)
	if (ant == NULL) // Se ant for igual a null (nada) executa:
	{
		novo->prox = l; // prox armazena o endereço de l 
		l = novo; // E l recebe o endereço da variável novo
	}
	else // caso não seja verdadeiro ele executa: 
	{
		novo->prox = ant->prox; // prox recebe o endereço de ant prox
		ant->prox = novo; // E ant prox recebe o endereço da variável novo
	}
	return l; // Retorna a lista
}

Lista *lst_ler_arquivo(char *nome_arquivo) // Função para ler a lista que tem como parâmetro um vetor de string
{
	FILE *arquivo; // Cria o ponteiro do tipo arquivo
	int valor; // Cria a variável do tipo inteiro
	Lista *l = lst_cria(); // Ponteiro do tipo lista recebe a função para criar a lista
	arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo no modo de leitura
	if (arquivo == NULL) // Se o arquivo for igual a null (nada) executa:
	{
		printf("Erro ao abrir o arquivo!\n"); // Mensagem de erro 
		exit(1); // Encerra o programa
	}
	while (fscanf(arquivo, "%s", &valor) != EOF) // Enquanto a leitura no arquivo para inteiro e armazenar na váriavel valor for diferente do final do arquivo executa:
	{
		l = lst_insere(l, valor); // l recebe a função para inserir com os parâmetro do ponteiro l (lista) e o valor (int)
	}
	fclose(arquivo); // Fecha o arquivo
	return l; // Retorna a lista
}
