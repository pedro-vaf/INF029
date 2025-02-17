/* Crie um programa em C, que contenha uma fun��o recursiva que receba dois 
inteiros positivos k e n e calcule k^n. Utilize apenas multiplica��es. O programa principal 
deve solicitar ao usu�rio os valores de k e n e imprimir o resultado da chamada da 
fun��o.  */

#include <stdio.h>
#include <stdlib.h>


int pontencia(int k, int n){

    int temp = 1;

    if (n > 0){
        return temp *= k; 
    }

    pontencia(k, n - 1);
}

int main(){

    int elemento1, elemento2;

    printf("*** Digite um elemento K e um elemento N e tenha o resultado de K^N ***\n");
    printf("Insira o elemento K (inteiro positivo) -> \n");
    scanf("%d", &elemento1);

    printf("Insira o elemento N (inteiro positivo) -> \n");
    scanf("%d", &elemento2);

    if (elemento1 >= 0 && elemento2 >= 0){
        printf("A soma acumulativa � : %d", pontencia(elemento1, elemento2));
    }

    return 0;
}