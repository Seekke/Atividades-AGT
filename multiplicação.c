#include <stdio.h>
int x;
int y;
int z;
int mult;
int main()
{
    printf("Digite dois fatores para uma multiplicação");
    scanf("%i%i", &x, &y);    

    if(x >= y){
        while(y > 0){
            mult += x;
            y -= 1;
        }
        printf("\nO resultado da multiplicação é: %i", mult);
    }else{
        while(x > 0){
            mult += y;
            x -= 1;
        }
        printf("\nO resultado da multiplicação é: %i", mult);
    }
    return 0;
}
 