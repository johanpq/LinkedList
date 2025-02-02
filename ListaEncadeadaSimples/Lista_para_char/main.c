#include "lista.c"

int main() {
    Lista *lista = lst_cria();  // Cria uma lista encadeada vazia

    // Insere elementos na lista
    lista = lst_insere(lista, "Pedro"); //novo->prox linka pro null, por conta da lista criada
    lista = lst_insere(lista, "Alex"); //novo->prox linka pra lista acima
    lista = lst_insere(lista, "Gabriel"); //novo->prox linka pra lista acima
    lista = lst_insere(lista, "Erick"); //novo->prox linka pra lista acima

    printf("Lista apos insercao de elementos:\n");
    lst_imprime(lista);
	printf("\n");

    // Verifica se a lista está vazia
    if (lst_vazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("A lista nao esta vazia.\n");
    }
	printf("\n");

    // Busca um elemento na lista
    Lista *resultadoBusca = lst_busca("Jose", lista);
    if (resultadoBusca != NULL) {
        printf("Elemento %s encontrado na lista.\n", resultadoBusca->nome);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
	printf("\n");

    // Remove um elemento da lista
    lista = lst_retira(lista, "Johan");
    printf("Lista apos a remocao do elemento %s:\n", 17);
    lst_imprime(lista);
	printf("\n");

    // Insere um elemento de forma ordenada na lista
    char elementoOrdenado[50] = "Pedro";
    lista = lst_insere_ordenada(lista, elementoOrdenado);
    printf("Lista apos a insercao ordenada do elemento %s:\n", elementoOrdenado);
    lst_imprime(lista);
	printf("\n");

    // Libera a memória da lista
    lst_libera(lista);

    // Lê valores de um arquivo e insere na lista
    lista = lst_ler_arquivo("entrada.txt");
    printf("Lista apos a leitura do arquivo:\n");
    lst_imprime(lista);

    // Libera a memória da lista novamente
    lst_libera(lista);

    return 0;
}
