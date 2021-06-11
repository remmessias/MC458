/**
 * Aluna: Rebecca Moreira Messias
 * RA 186416
 * Disciplina MC458 - Turma A
 * 
 * Esse programa feito na linguagem C tem como objetivo calcular
 * o tempo mínimo de conclusão de processamento de n tarefas.
 * 
 * Para isso o usuário precisa informa a quantidade (chamaremos 
 * essa quantidade de n) de tarefas que serão executadas e n
 * números que representam o tempo que cada tarefa leva para ser
 * executada.
 * 
 * O código devolve para o usuário o tempo minimizado de conclusão
 * e a ordem de execução de cada tarefa para que chegue a esse tempo. 
 */
#include <stdio.h>

/**
 * Função que realiza o merge customizada para poder trocar as 
 * posicoes do vetor de indices
 */
void merge(int array[], int posicoes[], int esquerda, int media, int direita) {
    int i, j, k;
    int n1 = media - esquerda + 1;
    int n2 = direita - media;
 
    int esquerdaArray[n1], direitaArray[n2];
    int esquerdaPosicoes[n1], direitaPosicoes[n2];
 
    for (i = 0; i < n1; i++) {
        esquerdaArray[i] = array[esquerda + i];
        esquerdaPosicoes[i] = posicoes[esquerda + i];
    }

    for (j = 0; j < n2; j++) {
        direitaArray[j] = array[media + 1 + j];
        direitaPosicoes[j] = posicoes[media + 1 + j];
    }
        
    i = 0;
    j = 0;
    k = esquerda;
    
    while (i < n1 && j < n2) {
        if (esquerdaArray[i] <= direitaArray[j]) {
            array[k] = esquerdaArray[i];
            posicoes[k] = esquerdaPosicoes[i];
            i++;
        }
        else {
            array[k] = direitaArray[j];
            posicoes[k] = direitaPosicoes[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = esquerdaArray[i];
        posicoes[k] = esquerdaPosicoes[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = direitaArray[j];
        posicoes[k] = direitaPosicoes[j];
        j++;
        k++;
    }
}

/**
 * Função que começa a executar o MergeSort
 */
void mergeSort(int array[], int posicoes[], int esquerda, int direita) {
    if (esquerda < direita) {
        int media = esquerda + (direita - esquerda) / 2;
 
        mergeSort(array, posicoes, esquerda, media);
        mergeSort(array, posicoes, media + 1, direita);
 
        merge(array, posicoes, esquerda, media, direita);
    }
}

/**
 * Função que calcula o tempo minimizado de conclusão de tarefas
 * dado o vetor com o tempo de execução para cada uma
 */
int calculaTempoMinimizado(int elementos[], int qtdNumeros) {
    int i, tempoMinimizado = 0, somaAcumulada = 0;
    
    for (i = 0; i < qtdNumeros; i++) {
        if (i == 0) {
            somaAcumulada = elementos[i];
        }
        else {
            somaAcumulada = somaAcumulada + elementos[i];
        }

        tempoMinimizado += somaAcumulada;
    }

    return tempoMinimizado;
}

/**
 * Função auxiliar para escrever vetores na tela
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
 * Função principal 
 */
int main() {
    int qtdNumeros, i, tempo = 0;

    scanf("%d", &qtdNumeros);

    int elementos[qtdNumeros];
    int posicoes[qtdNumeros];

    for (i = 0; i < qtdNumeros; i++) {
        scanf("%d", &elementos[i]);
        posicoes[i] = i + 1;
    }

    mergeSort(elementos, posicoes, 0, qtdNumeros - 1);

    tempo = calculaTempoMinimizado(elementos, qtdNumeros);
 
    printf("%d\n", tempo);

    escreveArray(posicoes, qtdNumeros);

    return 0;
}