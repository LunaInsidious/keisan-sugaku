#include <stdio.h>

int main() {
  double a = 0.1;
  double b = 0.2;
  double c = a + b;
  printf("%d\n", c == (0.1 + 0.2) ? 1 : 2);
  return 0;
}
