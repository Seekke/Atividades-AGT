int main (){

    int lista[30] = {};
    int x;
    int y;
    int odd;
    int cont;
    odd = 1;
    cont = 0;

    printf("Digite um número e descobriremos a sua raiz inteira.\n");
    scanf("%d", &y);

    x=y;
    while(odd <= x){
        x = x - odd;
        odd += 2;
        cont++;
    }
    
    printf("A raiz inteira de %d é %d\n",y,cont);
    
    return 0;
}