int divisor = 2;
int mmc = 1;
int mdc = 1;
int n1 = 1;
int n2 = 1;
int ent1 = 1;
int ent2 = 1;
#include <stdio.h>

int main()
{
	do
	{
		printf("Digite dois números maiores que 1 e calcularei o MMC e o MDC deles para você.");
		printf("\nLembrando que para parar o algoritmo basta digitar 0 ;)\n");
		scanf("%d %d", &ent1, &ent2);
		n1 = ent1;
		n2 = ent2;

		if (ent1 == 0 || ent2 == 0)
		{
			printf("\ntchau tchau (●'◡'●)\n");
		}

		if (ent1 < 0 || ent2 < 0)
		{ // checa valores negativos, avisa o usuário e reseta os valores de N para reiniciar o loop de verificação
			printf("\nOs valores aceitos são todos os números positivos maiores que 1.\n");
			printf("\nLembrando que 0 é o valor que terminará a execução ddo algoritmo!\n");
			ent1 = 1;
			ent2 = 1;
		}

		while (n1 > 1 || n2 > 1)
		{ // loop enquanto n1 ou n2 não tiverem chego em 1 ainda, dentro do loop é calculado o mmc e mdc
			if (n1 % divisor != 0 && n2 % divisor != 0)
			{ // checa se algum dos N é divisivel pelo divisor, se n for, incrementa o divisor
				divisor += 1;
				printf("\n %d %d %d", n1, n2, divisor);
			}
			else
			{ // 		este bloco descobre por qual N o divisor é divisivel
				if (n1 % divisor == 0 && n2 % divisor == 0)
				{ // se o divisor for divisivel de ambos os Ns, calculasse o mdc
					mdc *= divisor;
					printf("\ncalculando mdc");
				}
				mmc *= divisor;
				printf("\ncalculando mmc"); // calcula o mmc independentemente de qual N o divisor divide
				if (n1 % divisor == 0)
				{
					n1 = n1 / divisor;
					printf("\ndividindo n1");
				}
				if (n2 % divisor == 0)
				{
					n2 = n2 / divisor;
					printf("\ndividindo n2");
				}
			}
		}

		printf("\nO MMC de %d e de %d é : %d\n", ent1, ent2, mmc);
		printf("\nE o MDC é: %d \n", mdc);
		printf("\nSe desejas continuar calculando apenas digite mais dois números, caso estejas satisfeito digite 0 para parar o algoritmo");

		if (ent1 != 0 && ent2 != 0)
		{
			ent1 = 1;
			ent2 = 1;
		}
		n1 = 0;
		n2 = 0;
		divisor = 2;
		mmc = 1;
		mdc = 1; // reinicia o loop de verificação se nenhum dos valores introduzidos foram zero, assumindo q o programa concluiu o loop de processamento
	} while (ent1 == 1 || ent2 == 1);

	return 0;
}