#include <stdio.h>

int main(void){
	int n, m;
	/*scan input integers */
 	printf("Please enter two integers\n");
	scanf("%d%d", &n, &m);
	/*print decimal, hex anc oct*/
	printf("Decimal:%u, %u\n",n,m);
	printf("Hexadecimal:%x, %x\n",n,m);
	printf("Octal:%o, %o\n",n,m);
        
	
	/*Operations*/	
	printf("AND: %d\n", n & m);
	printf("OR: %d\n", n | m);
	printf("XOR: %d\n", n ^ m);
	
	return 0;
}
