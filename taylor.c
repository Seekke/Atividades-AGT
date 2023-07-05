#include <stdio.h>
#include <math.h>
int main(){

    float x;
    int n, i, j;
    printf("Digite x e a quantidade de termos n: ");
    scanf("%f%d", &x, &n);
    float e_x = 0; // inicializa somatório com zero

    for( i = 0 ; i <= n ; i++ ){ // laço de repetição N vezes
        float termo = 1; // variavel q guarda o valor a ser calculado
        for( j = 1 ; j <= i ; j++ ){// ao invés de usar núm. enormes destrinxamos os valores
            termo = termo * x / j; //  em seus componentes (x^2 = x*x) e          
        } //                           operamos os seus produtos, sendo x sempre igual
        e_x = e_x + termo; //           e J sempre incrementa em 1 por ser um fatorial.
    }

    printf("e elevado a %.3f = %.8f\n", x, e_x);

    return 0;
}