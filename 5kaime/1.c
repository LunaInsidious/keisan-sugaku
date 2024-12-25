#include <stdio.h>

// 基本再生産数：0.001 * 100 / 0.01 = 10
const double a = 0.001;
const double b = 0.01;

double fs(double s, double i) { return -a * s * i; }
double fi(double s, double i) { return a * s * i - b * i; }
double fr(double i) { return b * i; }

int main(void) {
  double s, i, r;
  s = 99;
  i = 1;
  r = 0;

  double ns, ni, nr;
  ns = s;
  ni = i;
  nr = r;

  // 刻み幅
  const double h = 0.5;

  double t;
  t = 0;
  while (t <= 365) {
    printf("%lf %lf %lf %lf \n", t, s, i, r);
    ns = s + h * fs(s, i);
    ni = i + h * fi(s, i);
    nr = r + h * fr(i);

    // 次の日になるので「今日の値」を「明日の値」に書き換える．
    s = ns;
    i = ni;
    r = nr;
    t += h;
  }

  return 0;
}
