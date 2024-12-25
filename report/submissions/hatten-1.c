/**
 * 発展課題1
 * x: [0,∞) -> R, v: [0,∞) -> R についての連立常微分方程式を考える
 * （これは，振り子の動きを表す方程式になっている．xが振り子の角度を表し，vはその速度を表している．）
 * この方程式を，k=1の場合について，陰的オイラー法で解くプログラムを作成せよ．ただし，陰的オイラー法が定める非線形方程式は，不動点反復法で解くこと．
 * 作成した関数を利用して，時刻t=0からt=50までの解を求めるプログラムを作成してみよ．
 */

// 授業の発展課題で提出済みだが一応提出
#include <math.h>
#include <stdio.h>

double simulateNextX(double x, double v, double h) { return x + h * v; }

double simulateNextV(double x, double v, double h, double k) {
  return v - h * k * sin(x);
}

void updateBySymplectic(double *x, double *v, double h) {
  const double k = 1;

  double prevX = *x;
  double prevV = *v;
  double curX = simulateNextX(*x, *v, h);
  double curV = simulateNextV(*x, *v, h, k);

  // 繰り返しの停止を判断する差分
  const double LOOP_STOP_DIFF = 0.0001;
  while (fabs(curX - prevX) > LOOP_STOP_DIFF &&
         fabs(curV - prevV) > LOOP_STOP_DIFF) {
    prevX = curX;
    prevV = curV;
    curX = simulateNextX(prevX, prevV, h);
    curV = simulateNextV(prevX, prevV, h, k);
  }

  *x = curX;
  *v = curV;
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
