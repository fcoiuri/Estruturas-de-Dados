#include <stdio.h>
#include <stdlib.h>

/* Ler um valor N. Calcular e escrever seu respectivo fatorial. Fatorial de N = N * (N-1) * (N-2) * (N-3) * ... * 1.

Entrada
A entrada cont�m um valor inteiro N (0 < N < 13).

Sa�da
A sa�da cont�m um valor inteiro, correspondente ao fatorial de N.

Exemplo de Entrada	Exemplo de Sa�da
4
int fat, n;

int main()
{
  scanf("%d", &n) ;

  for(fat = 1; n > 1; n = n - 1)
  {
      fat = fat * n;
  }

  printf("\n%d", fat);
  return 0;
24*/

int main(int argc, char *argv[]) {
	int n, fat;
	scanf("%d", &n);
	for(fat=1;n>=1;n--){
		fat *= n;
		printf("%d ", fat);
	}
	printf("\n%d ", fat);
	return 0;
}
