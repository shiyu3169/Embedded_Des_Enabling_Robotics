// This program does some array computation ... and crashes.
// Note that crash location and cause may not be the same.

#include <stdio.h>

int main() {
    long int i, j, k, array[100];
    
    for (i=0; i<100; i++) {
		for (j=0; j<100; j++) {
			k += i / j;
		}
	}
    printf("Result is: %ld \n", k);
}
