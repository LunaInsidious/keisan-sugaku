#include <stdio.h>

int main(void) { // int main()と同じ意味
  int a, b, c, d, e, f;
  printf("a, b, c, d, e, f の値をこの順番に入力してください.\n");
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &e);
  scanf("%d", &f);

  if (a * d - b * c != 0) {
    printf("x = %f\n", (double)(e * d - b * f) / (a * d - b * c));
    printf("y = %f\n", (double)(a * f - e * c) / (a * d - b * c));
  } else {
    printf("解が一意に定まりません\n");
  }

  return 0;
}
