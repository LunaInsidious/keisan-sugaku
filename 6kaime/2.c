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
