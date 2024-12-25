#include <stdio.h>

typedef struct {
  double tate;
  double yoko;
  double menseki;
} rect;

void area(rect *r) { r->menseki = r->tate * r->yoko; }

int main(void) {
  rect r;
  r.tate = 2.0;
  r.yoko = 3.0;
  area(&r);
  printf("%lf\n", r.menseki);
  return 0;
}
