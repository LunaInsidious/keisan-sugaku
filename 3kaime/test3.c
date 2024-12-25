#include <stdio.h>

int main() {
  int a = 20;
  int b = 2;

  printf("(a + b)/2 = %d\n", (a + b) / 2);
  printf("a + b/2 = %d\n", a + b / 2);

  int c = 6;
  int d = 3;

  printf("ab + c/d = %d\n", a * b + c / d);
  printf("a/b*c = %d\n", a / b * c);
  printf("-a*b = %d\n", -a * b);
}
