#include <stdio.h>

int main(void){
	int n, m;
 	printf("Please enter two integers\n");
	scanf("%d%d", &n, &m);
	printf("Decimal:%u, %u\n",n,m);
	printf("Hexadecimal:%x, %x\n",n,m);
	printf("Octal:%o, %o\n",n,m);


	return 0;
}
