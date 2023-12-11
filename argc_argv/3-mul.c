#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  int i = atoi(argv[1]);
  int j = atoi(argv[2]);
   int multi;
   multi = i*j;
   {   if (argc != 3)
   {
     printf("ERROR\n");
     return 1;
   }
   else
     {
        printf("%d\n", multi);
    }

    return 0;
   }}
