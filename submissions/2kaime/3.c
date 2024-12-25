#include <stdio.h>

int main() {
  double TAX_RATE = 0.10;
  int SellingPrice = 0;

  printf("Please input the price:\n");
  scanf("%d", &SellingPrice);

  // 元の価格が小数であることを許容する。
  double InitialPrice = SellingPrice / (1 + TAX_RATE);

  printf("The initial price is %f\n", InitialPrice);

  return 0;
}
