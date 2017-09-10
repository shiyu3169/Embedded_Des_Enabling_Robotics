#include <stdlib.h>
#include <string.h>
#define TOTAL 10
#define MAXSTRSIZE 100


char *strings[TOTAL][MAXSTRSIZE];

int cstring_cmp(const void *a, const void *b) { 
    const char *ia = (const char *)a;
    const char *ib = (const char *)b;
    return strncmp(ia, ib, MAXSTRSIZE);
} 

int main(void) {

  int i;
  char n[MAXSTRSIZE];

  printf("Enter 10 strings:\n");

  for (i = 0; i < TOTAL; i++) {
    scanf("%s", &n);
    strncpy(strings[i], n, MAXSTRSIZE);

  } 

  size_t elemsize = sizeof(strings[0]);
  size_t count = sizeof(strings) / elemsize;

  qsort(strings, count, elemsize, cstring_cmp);

  printf("\n\nSorted Strings:\n");

  for (i = 0; i < TOTAL; i++) {
    printf("%s\n", strings[i]);
  } 
  return 0;
}
