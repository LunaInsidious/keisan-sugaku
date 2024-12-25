/**
 * 問題8
 * 「// nibai のプロトタイプ宣言」の部分に，関数nibaiのプロトタイプ宣言を記述せよ．
 */

#include <stdio.h>

// nibai のプロトタイプ宣言
int nibai(int x);

int main(void) {
  printf("%d\n", nibai(3));
  return 0;
}

int nibai(int x) { return 2 * x; }
