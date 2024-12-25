/**
 * 発展課題2：発展課題1の続き
 * 計算結果を可視化すると（パラメータにも依存するが）振り子の振れ幅が小さくなる傾向があったのではないかと思う．
 * これは，エネルギーの保存則が成り立たなくなっていることに原因がある．シンプレクティック数値積分法と呼ばれる方法について調べてみよ．
 * また，実際にそのような方法でプログラムを作成してみよ．
 */

#include <math.h>
#include <stdio.h>

double simulateNextX(double x, double v, double h) { return x + h * v; }

double simulateNextV(double x, double v, double h, double k) {
  return v - h * k * sin(x);
}

void updateBySymplectic(double *x, double *v, double h) {
  const double k = 1;

  // https://zenn.dev/torataro/articles/2023-03-19-numerical_simulation#%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E6%B3%95%E3%82%92%E5%B7%A5%E5%A4%AB%E3%81%99%E3%82%8B
  // こういうこと?
  *x = simulateNextX(*x, *v, h);
  *v = simulateNextV(*x, *v, h, k);
}

int main() {
  double x = 1;
  double v = 0;

  const double h = 0.001;

  for (double t = 0; t < 50; t += h) {
    updateBySymplectic(&x, &v, h);
    printf("%lf %lf %lf\n", t, x, v);
  }
}
