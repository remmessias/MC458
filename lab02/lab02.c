/**
 * Aluna: Rebecca Moreira Messias
 * RA 186416
 * Disciplina MC458 - Turma A
 * 
 * Esse programa feito na linguagem C tem como objetivo ordenar
 * um array de número inteiros em O(n).
 * 
 * Para isso o usuário precisa informa a quantidade de números 
 * do nosso array e os números pertencentes ao array.
 * 
 * O código devolve o array ordenado.
 */
#include <stdio.h>

/**
 *  Função que faz a ordenação por contagem no array de acordo com o
 *  dígito representado em expoente
 */
void ordenacaoPorContagem(int array[], int tamanho, int expoente) {
 
    int arraySaida[tamanho];
    int i, contador[tamanho] ;

    // Inicializamos o array contador com 0.
    for (int i = 0; i < tamanho; i++) {
       contador[i] = 0;
    }
 
    // Contamos quantas ocorrências tem de um número no vetor
    for (i = 0; i < tamanho; i++) {
        contador[(array[i] / expoente) % tamanho]++;
    }
 
    // Alterando o contador[i] para que contador[i] contenha a
    // podição atual do dígito no arraySaida.
    for (i = 1; i < tamanho; i++) {
        contador[i] += contador[i - 1];
    }
 
    // Construção do arraySaida
    for (i = tamanho - 1; i >= 0; i--) {
        arraySaida[contador[(array[i] / expoente) % tamanho] - 1] = array[i];
        contador[(array[i] / expoente) % tamanho]--;
    }

    // Copia o arraySaida para nosso array para que dessa forma ele
    // contenha apenas números ordenados de acordo com o dígito atual.
    for (i = 0; i < tamanho; i++) {
        array[i] = arraySaida[i];
    }
}
 
/**
 *  Principal função que ordena nosso vetor array de tamanho n.
 */
void ordenador(int array[], int tamanho) {
    // Ordenação por contagem no primeiro digito na base n (n^0 = 1).
    ordenacaoPorContagem(array, tamanho, 1);
 
    // Ordenação por contagem no segundo dígito na base n (n^1 = n).
    ordenacaoPorContagem(array, tamanho, tamanho);
}
 
/**
 *  Função que escreve todos os elementos de um array.
 */
void escreveArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (i == tamanho - 1) {
            printf("%d\n", array[i]);
        }
        else {
            printf("%d ", array[i]);
        }
    }
}
 
/**
 *  Função principal.
 */
int main() {
    // Variáveis utilizadas.
    int qtdNumeros, i;

    // Leitura da quantidade de números que nosso vetor terá.
    scanf("%d", &qtdNumeros);

    // Vetor de números a serem ordenados.
    int elementos[qtdNumeros];

    // Lê os números do vetor.
    for (i = 0; i < qtdNumeros; i++) {
        scanf("%d", &elementos[i]);
    }
 
    // Chamada da função que ordena o vetor.
    ordenador(elementos, qtdNumeros);
 
    // Escreve na tela o vetor.
    escreveArray(elementos, qtdNumeros);

    return 0;
}