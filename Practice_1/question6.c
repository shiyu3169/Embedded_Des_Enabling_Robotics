#include <stdio.h>
#include <string.h>

#define SIZE 8

//sum the two input positive integers by logic operations
int sum(int a, int b) 
{
 	// Iterate till there is no carry  
    while (b != 0)
    {
        // carry now contains common set bits of x and y
        int carry = a & b;  
 
        // Sum of bits of x and y where at least one of the bits is not set
        a= a ^ b; 
 
        // Carry is shifted by one so that adding it to x gives the required sum
        b = carry << 1;
    }
    return a;
}

//compute the difference of two inut posiive integer by logic operations
int diff(int a, int b)
{
	//a - b = a + (-b)
	 return (sum(a, sum(~b, 1)));
}

//int to binary
void decimal_to_binary(int n)
{
	//variables use to count
   int c, d, count;

   //store the binary
   char *pointer;
 
   count = 0;
   pointer = (char*)malloc(32+1);
 
   //transfer int to binary, bit to bit
   for ( c = 31 ; c >= 0 ; c-- )
   {
      d = n >> c;
 
      if ( d & 1 )
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
 
      count++;
   }
   *(pointer+count) = '\0';
 	
   printf(pointer);
   free(pointer);
}


int main(void) {
	/*scan the input of two positive integers*/
	printf("Enter 2 positive integers for calculation:\n");
	int a, b;
	scanf("%d%d", &a, &b);
	
	/*check the input integers are positive*/	
	if (a <= 0 || b <= 0) {
	printf("Your inputs are invalid, please reenter 2 positive integers\n");
	scanf("%d%d", &a, &b);
	}

	/*scan the operation to call the coresponding function*/
	printf("Please choose an operation from (+ or -)");
	char s;
	scanf("%s", &s);
	
	if (s == '+') 
	{
		//print the signed int
		printf("%i+%i = %i\n", a, b, sum(a, b));

		//print the 2's comp
		printf("2's comp: ");
		decimal_to_binary(sum(a,b));
		printf("\n");
	}
	else if (s == '-') 
	{
		//prin the signed int
		printf("%i-%i = %i\n", a, b, diff(a, b));

		//print the 2's comp
		printf("2's comp: ");
		decimal_to_binary(diff(a,b));
		printf("\n");
	}
	//print error if user entered invalid inputs
	else 
	{
		printf("Your input was invalid, please restart the program\n");
	}
	return 0;
}