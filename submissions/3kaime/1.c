#include <stdio.h>

int main() {
  int A = 0;
  int B = 0;

  printf("Please input the first number:\n");
  scanf("%d\n", &A);

  printf("Please input the second number:\n");
  scanf("%d\n", &B);

  const int Bigger = A > B ? A : B;

  printf("The bigger number is %d\n", Bigger);

  return 0;
}
