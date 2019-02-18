#include <stdio.h>
#include <stdlib.h>
/*A seguinte sequência de números 0 1 1 2 3 5 8 13 21... é conhecida como série de Fibonacci. Nessa sequência, cada número, depois dos 2 primeiros, é igual à soma dos 2 anteriores. Escreva um algoritmo que leia um inteiro N (N < 46) e mostre os N primeiros números dessa série.

Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 46).

Saída
Os valores devem ser mostrados na mesma linha, separados por um espaço em branco. Não deve haver espaço após o último valor.

Exemplo de Entrada	Exemplo de Saída
5

0 1 1 2 3*/
int main(int argc, char *argv[]) {
	int n, fibo=0, a=0, b=1;
	scanf("%d", &n);

	while(fibo<n){
		printf("%d ", fibo);
		fibo = a + b;
		a = b;
		b = fibo;
	}
	/*/{
        if(y%2==1)
        {
            printf("%d ",c);
            c=a+b;
            a=c;
        }
        else if(y==2)
            printf("%d ",c);
        else if(y%2==0)
        {
            printf("%d ",c);
            c=a+b;
            b=c;
        }
    }
    printf("%d\n",c);
    return 0;
}*/
	return 0;
}
