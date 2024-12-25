/**
 * 発展課題5
 * 浮動小数点演算における「エラーフリー変換」と呼ばれる手法について調べてみて，実際にプログラムを作成してみよ．
 */

#include <float.h>
#include <math.h>
#include <stdio.h>

#define C ((1 << (DBL_MANT_DIG + 1) / 2) + 1)

// https://math-koshimizu.hatenablog.jp/entry/2019/04/22/183000
// Knuth's algorithm
void twoSum(double a, double b, double *sum, double *error) {
  *sum = a + b;
  double t1 = *sum - a;
  double t2 = *sum - t1;
  t1 = b - t1;
  t2 = a - t2;
  *error = t1 + t2;
}

// Dekker's algorithm
void twoProd(double a, double b, double *prod, double *error) {
  double a1 = a * C;
  double b1 = b * C;
  *prod = a * b;
  a1 = (a - a1) + a1;
  b1 = (b - b1) + b1;
  double a2 = a - a1;
  double b2 = b - b1;
  *error = (((a1 * b1 - *prod) + a1 * b2) + a2 * b1) + a2 * b2;
}

int main() {
  double a = 0.1, b = 0.1;
  double sum, error1;

  twoSum(a, b, &sum, &error1);

  printf("Sum: %.17g\n", sum);
  printf("Error: %.17g\n", error1);

  double prod, error2;

  twoProd(a, b, &prod, &error2);

  printf("Product: %.17g\n", prod);
  printf("Error: %.17g\n", error2);

  return 0;
}
