#include <stdio.h>

int main() {
  unsigned char a = 0;
  unsigned int b = 0;
  unsigned long c = 0;

  char d = 0;
  int e = 0;
  long f = 0;

  printf("unsigned char %ld\n", sizeof(a));
  printf("unsigned int %ld\n", sizeof(b));
  printf("unsigned long %ld\n", sizeof(c));
  printf("char %ld\n", sizeof(d));
  printf("int %ld\n", sizeof(e));
  printf("long %ld\n", sizeof(f));
}
