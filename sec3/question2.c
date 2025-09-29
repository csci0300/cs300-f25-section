#include <stdlib.h>
#include <stdio.h>

int main() {
  // make a 4-byte allocation for an int, set the value to 42
  int* fav_num = (int*)malloc(sizeof(int));
  fav_num[0] = 42;

  // make a 4-byte allocation for another int, set to 999
  int* fav_num2 = (int*)malloc(sizeof(int));
  fav_num2[0] = 999;

  // print the addresses of the allocations.
  printf("fav_num: %p\n", fav_num);
  printf("fav_num2: %p\n", fav_num2);

  // now write to 4 bytes of memory starting 28
  // bytes beyond the end of the valid allocation
  // (fav_num + 32 bytes).
  *(fav_num + 8) = 55;

  printf("*fav_num: %d\n", *fav_num);
  printf("*fav_num2: %d\n", *fav_num2);

  // if you leave out this line and compile with -fsanitize=address,
  // you will get a complaint about a memory leak
  free(fav_num);
  free(fav_num2);
}