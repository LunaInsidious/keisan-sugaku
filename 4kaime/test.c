#include <stdio.h>

int main() {
  float a = 1.0; // float は単精度浮動小数点数．
  float b = 2.0;
  float c = a + b;
  printf("%f %f %f\n", a, b, c);
  printf("%d\n", c == 3.0 ? 1 : 2); // cが0.3ならば１，そうでないなら２を表示
  double d = 0.1;                   // double は倍精度浮動小数点数．
  double e = 0.2;
  double f = d + e;
  printf("%f %f %f\n", d, e, f);
  printf("%d\n", f == 0.3 ? 1 : 2); // fが3.0ならば１，そうでないなら２を表示
  return 0;
}
