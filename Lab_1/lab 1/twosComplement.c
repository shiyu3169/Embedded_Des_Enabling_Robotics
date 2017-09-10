#include <stdio.h>

int main(void) {
	/*Consider in 32bit system */
	int n;
	printf("Please enter one integer\n");
	scanf("%d", &n);
	/*if the input is positive, we don't need to do anything*/
	if (n >= 0) {
		printf("One's complement:%x,\n", n);
		printf("Two's complement:%x,\n", n);
	}
	/*if the input is negative, flip every bit and + 1 */
	else {
		printf("One's complement:%x,\n",abs(n) ^ 0xffffffff);
		printf("Two's complement:%x,\n",(abs(n) ^ 0xffffffff) +1);
	}
}