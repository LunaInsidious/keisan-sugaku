#include <stdio.h>

// 基本再生産数：0.00009 * 100/0.01 = 0.9
const double a = 0.00009;
const double b = 0.01;

double fs(double s, double i) { return -a * s * i; }
double fi(double s, double i) { return a * s * i - b * i; }
double fr(double i) { return b * i; }

int main(void) {
  double s, i, r;
  s = 99;
  i = 1;
  r = 0;

  // 陽的オイラー法を用いた値を格納する変数
  double eulerS, eulerI, eulerR;
  eulerS = 0;
  eulerI = 0;
  eulerR = 0;

  // heun法を用いた値を格納する変数
  double ns, ni, nr;
  ns = 0;
  ni = 0;
  nr = 0;

  // 刻み幅
  const double h = 0.5;

  double t;
  t = 0;

  while (t <= 365) {
    printf("%lf %lf %lf %lf \n", t, s, i, r);
    eulerS = s + h * fs(s, i);
    eulerI = i + h * fi(s, i);
    eulerR = r + h * fr(i);

    ns = s + h / 2 * (fs(s, i) + fs(eulerS, eulerI));
    ni = i + h / 2 * (fi(s, i) + fi(eulerS, eulerI));
    nr = r + h / 2 * (fr(i) + fr(eulerI));

    // 次の日になるので「今日の値」を「明日の値」に書き換える．
    s = ns;
    i = ni;
    r = nr;
    t += h;
  }

  return 0;
}
