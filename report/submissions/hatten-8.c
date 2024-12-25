/**
 * 発展課題8
 * ポインタ（配列でも良い）を利用したプログラムを何か作成してみよ．
 */

#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int a = 1;
  int b = 2;

  printf("a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b);
}
