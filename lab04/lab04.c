#include <stdio.h>
 
void merge(int arr[], int pos[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
    int M[n1], S[n2];
 
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        M[i] = pos[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        S[j] = pos[m + 1 + j];
    }
        
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            pos[k] = M[i];
            i++;
        }
        else {
            arr[k] = R[j];
            pos[k] = S[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        pos[k] = M[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        pos[k] = S[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int pos[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, pos, l, m);
        mergeSort(arr, pos, m + 1, r);
 
        merge(arr, pos, l, m, r);
    }
}

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

int main() {
    int qtdNumeros, i, soma = 0, acumulado = 0;

    scanf("%d", &qtdNumeros);

    int elementos[qtdNumeros];
    int posicoes[qtdNumeros];

    for (i = 0; i < qtdNumeros; i++) {
        scanf("%d", &elementos[i]);
        posicoes[i] = i + 1;
    }

    mergeSort(elementos, posicoes, 0, qtdNumeros - 1);

    for (i = 0; i < qtdNumeros; i++) {
        if (i == 0) {
            acumulado = elementos[i];
        }
        else {
            acumulado = acumulado + elementos[i];
        }
        soma += acumulado;
    }
 
    printf("%d\n", soma);

    escreveArray(posicoes, qtdNumeros);

    return 0;
}