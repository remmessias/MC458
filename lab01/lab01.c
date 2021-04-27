/**
 * Aluna: Rebecca Moreira Messias
 * RA 186416
 * Disciplina MC458 - Turma A
 * 
 * Esse programa frito na linguagem C tem como objetivo achar 
 * uma subsequência em um array de números que tenha o maior
 * produto.
 * 
 * Para isso o usuário precisa informa a quantidade de números 
 * do nosso array e os números pertencentes ao array.
 * 
 * O código devolve o resultado do produto da subsequência 
 * encontrada.
 */
#include <stdio.h>
 
/**
 * Função que encontra o menor valor entre dois números.
 */
double valorMinimo(double x, double y) {
    return (x < y) ? x : y;
}

/**
 * Função que encontra o maior valor entre dois números.
 */
double valorMaximo(double x, double y) {
    return (x > y) ? x : y;
}
 
/**
 * Função que encontrará a subsequência com o maior produto 
 * de seus valores e devolverá o resultado desse produto. * 
 */
double encontraProdutoMaximo(double vetor[], int qtdElementos) {
    // Variáveis que armazenaram o produto máximo e mínimo.
    double maiorProduto = 0, menorProduto = 0;
 
    // Variável que armazena o resultado do produto máximo encontrado até então.
    double maximoProdutoEncontrado = 0;

    // Variável auxiliar para iterar o array.
    int i;
 
    for (i = 0; i < qtdElementos; i++) {
        double aux = maiorProduto;

        // Atualiza o produto máximo encontrado até então.
        maiorProduto = valorMaximo(vetor[i], valorMaximo(vetor[i] * maiorProduto, vetor[i] * menorProduto));

        // Atualiza o produto mínimo encontrado até então.
        menorProduto = valorMinimo(vetor[i], valorMinimo(vetor[i] * aux, vetor[i] * menorProduto));
 
        // Atualiza o produto máximo. 
        maximoProdutoEncontrado = valorMaximo(maximoProdutoEncontrado, maiorProduto);
    }

    // Verificamos se temos apenas um elemento na subsequência para retornar 1.
    maximoProdutoEncontrado = maximoProdutoEncontrado == vetor[i-2] && maiorProduto == vetor[i-1] ? 1 : maximoProdutoEncontrado;

    // Retorna o máximo produto.
    return maximoProdutoEncontrado;
}

/**
 * Função principal 
 */
int main(void) {
    // Variáveis utilizadas.
    int qtdNumeros, i;
    double elementos[1000];

    // Leitura da quantidade de números que nosso vetor terá.
    scanf("%d", &qtdNumeros);

    // Lê os números do vetor.
    for (i = 0; i < qtdNumeros; i++) {
        scanf("%lf", &elementos[i]);
    }

    // Chamada da função que encontra o produto máximo de uma subsequência do nosso vetor.
    double valorProdutoMaximo = encontraProdutoMaximo(elementos, qtdNumeros); 
 
    // Escreve o resultado do produto encontrado.
    printf("%.6f\n", valorProdutoMaximo);
 
    return 0;
}