#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

// Função para criar uma nova célula com um valor específico
celula *cria_celula(int valor) {
    celula *nova = (celula*) malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    nova->conteudo = valor;
    nova->prox = NULL;
    return nova;
}

// Função para imprimir todos os valores da lista encadeada
void imprime_lista(celula *inicio) {
    celula *p = inicio;
    while (p != NULL) {
        printf("%d -> ", p->conteudo);
        p = p->prox;
    }
    printf("NULL\n");
}

// Função para remover a lista encadeada e liberar a memória
void remove_lista(celula *inicio) {
    celula *p = inicio;
    while (p != NULL) {
        celula *temp = p;
        p = p->prox;
        free(temp);
    }
    printf("Todos os elementos foram removidos e a memória foi liberada.\n");
}

// Função para calcular a quantidade de memória ocupada por cada célula
void calcula_memoria_celula() {
    printf("Cada célula ocupa %lu bytes.\n", sizeof(celula));
}

// Função principal
int main() {
    // Criando três instâncias de célula
    celula *c1 = cria_celula(10);
    celula *c2 = cria_celula(20);
    celula *c3 = cria_celula(30);

    // Conectando as células para formar a lista encadeada
    c1->prox = c2;
    c2->prox = c3;

    // Imprimindo os valores da lista
    printf("Valores da lista:\n");
    imprime_lista(c1);

    // Calculando e exibindo a quantidade de memória ocupada por cada célula
    calcula_memoria_celula();

    // Removendo os elementos da lista e liberando a memória
    remove_lista(c1);

    return 0;
}
