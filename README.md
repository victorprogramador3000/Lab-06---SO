# README - Código do Lab 06 de Sistemas Operacionais

**Aluno:** Victor Hugo Fiuza Garcia **RA:** 10331903 **Turma:** 04N
---

## Descrição

Este projeto contém uma implementação simples de uma lista encadeada em C, que faz parte do **Lab 06 de Sistemas Operacionais (SO)**. O código tem como objetivo criar e manipular uma estrutura de dados do tipo `celula` com três instâncias e realizar algumas operações sobre essa lista.

### Funcionalidades:

1. **Criação de Células:** A função `cria_celula` cria novas células da lista com valores específicos.
2. **Impressão dos Valores da Lista:** A função `imprime_lista` percorre a lista encadeada e exibe os valores armazenados.
3. **Cálculo de Memória Ocupada:** A função `calcula_memoria_celula` calcula e exibe a quantidade de memória ocupada por cada célula da lista.
4. **Remoção e Liberação de Memória:** A função `remove_lista` remove todos os elementos da lista encadeada e libera a memória alocada para cada célula.
5. **Conectar as Células:** O código principal conecta as três células criadas para formar a lista encadeada.

## Objetivos do Lab:

O código responde às seguintes questões do laboratório, com explicação de onde no código cada questão é respondida:

1. **Criação de três instâncias do objeto célula:**
   - No código, a criação de três instâncias ocorre na função `main`, nas seguintes linhas:
     ```c
     celula *c1 = cria_celula(10);
     celula *c2 = cria_celula(20);
     celula *c3 = cria_celula(30);
     ```

2. **Impressão dos valores da lista:**
   - A impressão dos valores é realizada pela função `imprime_lista`. Esta função é chamada dentro do `main` na linha:
     ```c
     imprime_lista(c1);
     ```
   - A definição da função `imprime_lista` ocorre nas linhas:
     ```c
     void imprime_lista(celula *inicio) {
         celula *p = inicio;
         while (p != NULL) {
             printf("%d -> ", p->conteudo);
             p = p->prox;
         }
         printf("NULL\n");
     }
     ```

3. **Cálculo da memória ocupada por cada célula:**
   - A função que calcula a memória ocupada por cada célula é `calcula_memoria_celula`, chamada na linha:
     ```c
     calcula_memoria_celula();
     ```
   - A definição da função ocorre nas linhas:
     ```c
     void calcula_memoria_celula() {
         printf("Cada célula ocupa %lu bytes.\n", sizeof(celula));
     }
     ```

4. **Remoção dos elementos da lista:**
   - A remoção dos elementos da lista é realizada pela função `remove_lista`, chamada na linha:
     ```c
     remove_lista(c1);
     ```
   - A definição da função ocorre nas linhas:
     ```c
     void remove_lista(celula *inicio) {
         celula *p = inicio;
         while (p != NULL) {
             celula *temp = p;
             p = p->prox;
             free(temp);
         }
         printf("Todos os elementos foram removidos e a memória foi liberada.\n");
     }
     ```

5. **Liberação de memória:** 
   - A função `remove_lista` é incrementada para garantir a liberação adequada da memória, conforme descrito no item anterior. Ela percorre a lista, liberando a memória de cada célula individualmente com a função `free`.

6. **Cálculo do máximo de elementos na fila (não implementado diretamente):**
   - O cálculo do número máximo de elementos possíveis na fila, baseado na memória disponível, pode ser avaliado com a ajuda da função `calcula_memoria_celula`, que informa o tamanho de cada célula. Essa informação pode ser usada para calcular quantos elementos cabem na memória disponível do computador.

## Estrutura do Projeto

- **struct reg:** Define a estrutura da célula, que contém um valor inteiro e um ponteiro para a próxima célula.
- **Funções principais:**
  - `cria_celula(int valor)` - Cria e retorna uma nova célula com o valor passado.
  - `imprime_lista(celula *inicio)` - Percorre a lista e imprime todos os valores armazenados.
  - `calcula_memoria_celula()` - Calcula o tamanho de memória de cada célula.
  - `remove_lista(celula *inicio)` - Remove todos os elementos da lista e libera a memória.

## Observações

Este código pode ser facilmente expandido para listas maiores e mais complexas. Atualmente, ele lida com uma lista de três elementos, mas o conceito pode ser aplicado para listas com um número maior de nós.
