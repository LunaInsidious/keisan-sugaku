#include <stdio.h>

int main() {
  double A[2][3] = {0};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%lf ", A[i][j]);
    }
  }

  return 0;
}
