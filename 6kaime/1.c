#include <stdio.h>

// e^xの近似値を求める関数
/*
 * @param n: 近似を何次まで行うか
 */
double simulateExp(double x, int n) {
  double sum = 1;
  double iNum = 1; // i次の項
  for (int i = 1; i <= n; i++) {
    iNum *= x / i;
    sum += iNum;
  }
  return sum;
}

int main() {
  double x = 0;
  int n = 1;

  printf("何次まで展開しますか?\n");
  scanf("%d", &n);

  if (n < 1) {
    printf("1以上の整数を入力してください。\n");
    return 1;
  }

  printf("求めたいe^xのxの値を入力してください。\n");
  scanf("%lf", &x);

  printf("e^%lf ≒ %lf\n", x, simulateExp(x, n));

  return 0;
}
