#include <stdlib.h>
#include <stdio.h>

int main() {
  // make a 4-byte allocation for an int, set the value to 42
  int* fav_num = (int*)malloc(sizeof(int));
  fav_num[0] = 42;

  // print the address of the allocation
  printf("fav_num: %p\n", fav_num);

  // now write to 4 bytes of memory starting 4
  // bytes beyond the end of the valid allocation
  fav_num[2] = 55;

  printf("*fav_num: %d\n", *fav_num);

  // if you leave out this line and compile with -fsanitize=address,
  // you will get a complaint about a memory leak
  free(fav_num);
}