#include <stdlib.h>
#define TOTAL 10


int nums[TOTAL];

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
 }

int main(void){

  int i, n;

  printf("Enter 10 numbers:\n");

  for (i = 0; i < TOTAL; i++) {
    scanf("%d", &n);
    nums[i] = n;
  }

  qsort(nums, TOTAL, sizeof(int), cmpfunc);

  printf("\n\nSorted numbers:\n");

  for (i = 0; i < TOTAL; i++) {
    printf("%i\n", nums[i]);
  } 
  return 0;
}
