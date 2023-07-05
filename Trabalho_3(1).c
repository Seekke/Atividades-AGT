#include <stdio.h>

#define LIM_CONJUNTO 10

int escolher_conjunto()
{
    int id_conjunto;

    printf("Escolha o conjunto o desejado:\n");

    printf("1 - A\n");
    printf("2 - B\n");
    printf("3 - Voltar\n");

    do
    {
        scanf("%d", &id_conjunto);

        if (id_conjunto > 3 || id_conjunto < 1)
            printf("Voce inseriu um conjunto invalido.");
    }
    while (id_conjunto > 3 || id_conjunto < 1);

    return id_conjunto - 1;
}

void inserir(int lista_conjuntos[2][LIM_CONJUNTO])
{
    int id_conjunto = escolher_conjunto();

    if (id_conjunto == 2) return;

    int *conjunto = lista_conjuntos[id_conjunto];

    printf("Insira os valores para o conjunto selecionado (insira 0 para parar):\n");

    for (int i = 0; i < LIM_CONJUNTO; i++)
    {
        int valor;

        scanf("%d", &valor);
        
        if (valor == 0)
            break;

        for (int j = 0; j < LIM_CONJUNTO; j++)
        {
            if (conjunto[j] == 0)
            {
                conjunto[i] = valor;
                break;
            }

            if (conjunto[j] == valor)
            {
                printf("Voce ja inseriu este valor. Insira outro:\n");
                break;
            }
        }
    }
}

void remover(int lista_conjuntos[2][LIM_CONJUNTO])
{
    int id_conjunto = escolher_conjunto();

    if (id_conjunto == 2) return;

    int *conjunto = lista_conjuntos[id_conjunto];

    for (int i = 0; i < LIM_CONJUNTO; i++)
        conjunto[i] = 0;
}

void exibir(int lista_conjuntos[2][LIM_CONJUNTO])
{
    int id_conjunto = escolher_conjunto();

    if (id_conjunto == 2) return;

    int *conjunto = lista_conjuntos[id_conjunto];

    printf("Numeros do conjunto:\n{");

    for (int i = 0; i < LIM_CONJUNTO; i++)
    {
        if (conjunto[i] == 0)
        {
            // Se o primeiro valor do conjunto for 0, o conjunto é vazio
            if (i == 0) printf(" Conjunto vazio ");

            break;
        }

        printf(" %d ", conjunto[i]);
    }

    printf("}");
}

void equacoes_conjuntos(int lista_conjuntos[2][LIM_CONJUNTO], int type)
{
    int *conj_a = lista_conjuntos[0];
    int *conj_b = lista_conjuntos[1];

    // União (com valores repetidos)
    int uniao[2 * LIM_CONJUNTO];
    int total = 0;

    for (int i = 0; i < LIM_CONJUNTO; i++)
    {
        if (conj_a[i] == 0) break;
        uniao[total] = conj_a[i];
        total++;
    }

    for (int i = 0; i < LIM_CONJUNTO; i++)
    {
        if (conj_b[i] == 0) break;
        uniao[total] = conj_b[i];
        total++;
    }

    int repetidos[LIM_CONJUNTO];
    int cont_repetidos = 0;

    for (int i = 0; i < LIM_CONJUNTO; i++)
        repetidos[i] = 0;

    // Verificar os numeros repetidos
    for (int i = 0; i < total; i++)
    {
        int num = uniao[i];

        for (int j = 0; j < total; j++)
        {
            if (num == uniao[j] && i != j)
            {
                int repetido_encontrado = 0;

                // Verifica se o número repetido já foi adicionado
                for (int k = 0; k < cont_repetidos; k++)
                {
                    if (repetidos[k] == 0) break;
                    if (repetidos[k] == num) repetido_encontrado = 1;
                }
                
                if (repetido_encontrado == 0)
                {
                    repetidos[cont_repetidos] = num;
                    cont_repetidos++;
                }
            }
        }
    }
    
    switch (type)
    {
        case 1:
            // União
            printf("Uniao:\n{");

            for (int i = 0; i < total; i++)
            {
                int num = uniao[i];
                int repete = 0;

                for (int j = i - 1; j < cont_repetidos; j++)
                    if (num == repetidos[j]) repete = 1;

                if (repete == 0)
                    printf(" %d ", num);
            }

            printf("}");
            break;
        case 2:
            // Intersecção
            printf("Interseccao:\n{");

            for (int i = 0; i < cont_repetidos; i++)
                printf(" %d ", repetidos[i]);

            printf("}");
            break;
        case 3:
            // Diferença
            printf("Diferenca:\n{");

            for (int i = 0; i < LIM_CONJUNTO; i++)
            {
                int num = conj_a[i];
                int repete = 0;

                if (num == 0) break;

                for (int j = 0; j < cont_repetidos; j++)
                    if (num == repetidos[j]) repete = 1;

                if (repete == 0) printf(" %d ", num);
            }

            printf("}");
            break;
        default:
            break;
    }
}

int main()
{
    int opcao;

    int conjunto_a[LIM_CONJUNTO], conjunto_b[LIM_CONJUNTO];

    int conjuntos[2][LIM_CONJUNTO] = {conjunto_a, conjunto_b};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < LIM_CONJUNTO; j++)
            // Zerar todos os elementos dos conjuntos
            conjuntos[i][j] = 0;

    for (int i = 0; i < 50; i++)
        printf("-");

    printf("\nCALCULADORA DE CONJUNTOS\n");

    for (int i = 0; i < 50; i++)
        printf("-");

    while (opcao != 7)
    {
        printf("\n1 - Inserir valores em um conjunto\n");
        printf("2 - Remover todos os valores de um conjunto\n");
        printf("3 - Exibir os valores dos conjuntos\n");
        printf("4 - Uniao\n");
        printf("5 - Interseccao\n");
        printf("6 - Diferenca\n");
        printf("7 - Sair do programa\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                inserir(conjuntos);
                break;
            case 2:
                remover(conjuntos);
                break;
            case 3:
                exibir(conjuntos);
                break;
            case 4:
                equacoes_conjuntos(conjuntos, 1);
                break;
            case 5:
                equacoes_conjuntos(conjuntos, 2);
                break;
            case 6:
                equacoes_conjuntos(conjuntos, 3);
                break;
            case 7:
                break;
            default:
                printf("Voce inseriu um numero invalido.");
                break;
        }
    }

    return 0;
}
