#include <stdio.h>
#include <stdlib.h>
/*A seguinte sequ�ncia de n�meros 0 1 1 2 3 5 8 13 21... � conhecida como s�rie de Fibonacci. Nessa sequ�ncia, cada n�mero, depois dos 2 primeiros, � igual � soma dos 2 anteriores. Escreva um algoritmo que leia um inteiro N (N < 46) e mostre os N primeiros n�meros dessa s�rie.

Entrada
O arquivo de entrada cont�m um valor inteiro N (0 < N < 46).

Sa�da
Os valores devem ser mostrados na mesma linha, separados por um espa�o em branco. N�o deve haver espa�o ap�s o �ltimo valor.

Exemplo de Entrada	Exemplo de Sa�da
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
