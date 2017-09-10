#include <stdio.h> 

int main(void) { 
	/*ch is a char*/
	char ch = 'T';

	/* *chptr is a pointer point to ch */ 
	char *chptr = &ch;
	 /*name is a array of char with size equal to 6*/
	char name[6];

	/* a is an int equal to 1000 */
	int a = 1000; 
	/* *intptr is a pointer point to a */
	int *intptr = &a;
	
	/*fbnumber is a float*/
	float fnumber = 1.20000; 
	/* *fnumber is a pointer point to fnumber*/
	float *fptr = &fnumber;
	
	/* *ptr is a  pointer point to the first char of "my dog has fleas!"*/
	char *ptr = "My dog has fleas!";
	
	/*print out everything */
	printf("\n [%c],[%d],[%f],[%c],[%s]\n", *chptr, *intptr, *fptr, *ptr, ptr);
	
	/*update chptr to ptr */
	chptr = ptr;

	/*print out *chptr and chptr, *chptr point to the first letter of the string, chptr is the whole string*/
	printf("\n [%c],[%s]\n", *chptr, chptr);
	
	//assign different element to name array
	name[0] = 75; 
	name[1] = 97; 
	name[2] = 0x65; 
	name[3] = 0154; 
	name[4] = 105; 
	name[5] = 0;
	//print out each element based on ASCII characters mapping.
	printf("\n [%s]\n", name);
	return 0; 
}