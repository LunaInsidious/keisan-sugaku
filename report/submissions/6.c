/**
 * 問題6
 * 入力された数字（整数）に対して，2の倍数ならば2を表示し，2の倍数でないけれども，3の倍数ならば3を表示し，特に戻り値をもたないような関数
 * funcを作りたい（例えば，3ならば3が表示され，6ならば2が表示される．）次のプログラムの間違いを修正せよ．
 **/
#include <stdio.h>

void func(int n) {
  if (n % 2 == 0) {
    printf("2\n");
  } else if (n % 3 == 0) {
    printf("3\n");
  }
}

int main() {
  int n;
  scanf("%d", &n);
  func(n);
  return 0;
}
