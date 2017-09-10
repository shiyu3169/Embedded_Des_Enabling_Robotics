// This program computes n factorial.
// Presently there is a bug in this program.

#include<stdio.h>

/** compute factorial */ 
long factorial(int n);
 
int main() {
    int n = 0;
    long val;
    // note the \n at the end of print string. 
    // Linux typically buffers until a \n. So, when debugging 
    // a line that is "unfinished" (i.e. has no \n) may not appear 
    // in the terminal. Try it if you are adventurous ...
    printf("Enter value: \n");
    scanf("%d",&n);
    val=factorial(n);
    printf("Factorial of %d is %ld\n", n, val);
    return 0;
}
 
/** compute factorial */ 
long factorial(int n) {
    long result = 1;
    while(n--) {
        result*=n;
    }
    return result;
}
