#include <stdio.h>
#include <stdlib.h>
void allocArray(int ***p, int m, int n)
{
   int **temp = (int**)malloc(m * sizeof(int *));
   if (temp == NULL) {
     // Handle memory allocation failure
    fprintf( stderr, "Memory allocation failed\n");
    exit(1);
   }

   for (int i = 0; i < m; i++) {
    temp[i] = (int *)malloc(n * sizeof(int));
    if (temp[i] == NULL) {
      // Handle memory allocation failure
      fprintf(stderr,"Memory Allocation Failed \n");
      exit(1);
    }
   }
  //Update the pointer p to point to the allocated 2-D array
   *p = temp;
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));
}