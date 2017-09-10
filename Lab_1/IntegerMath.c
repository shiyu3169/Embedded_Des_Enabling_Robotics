#include <stdio.h>
/* function takes two integers and sum them together */
int add(int first, int second) {
	return first + second;
}
/* function takes two integers and substract the second from first integers */
int substract(int first, int second) {
	return first - second;
}
/* function takes two integers and mutiplys them */
int multiply(int first, int second) {
	return first * second;
}
/* function takes two integers and returns the result first integer is diveded by the second
*/
int divide(int first, int second) {
	return first / second;
}

/* the main function */
int main(void) {
	/*scan the input of positive integers*/
	printf("Enter 2 positive integers for calculation:\n");
	printf("Warning: positive integers only, other inputs may crash the program\n");
	int n, m;
	scanf("%d%d", &n, &m);

	/*check the input integers are positive*/	
	if (n <= 0 || m <= 0) {
	printf("Your inputs are invalid, please reenter 2 positive integers\n");
	scanf("%d%d", &n, &m);
	}
	printf("Please choose an operation from (+, -, *, /)");
	printf("Warning: operation only, other inputs may crash the program\n");

	/*scan the operation to call the coresponding function*/
	char s;
	scanf("%s", &s);
	if (s == '+') {
		printf("%i+%i = %i\n", n, m, add(n, m));
	}
	else if (s == '-') {
		printf("%i-%i = %i\n", n, m, substract(n, m));
	}
	
	else if (s == '*') {
		printf("%i*%i = %i\n", n, m, multiply(n, m));
	}

	else if (s == '/') {
		printf("%i/%i = %i\n", n, m, divide(n, m));
	}
	
	/*print error if user entered invalid inputs*/
	else {
		printf("Your input was invalid, please restart the program\n");
	}
	return 0;
}
