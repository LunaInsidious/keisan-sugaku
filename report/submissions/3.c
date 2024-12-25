/**
 * 問題3
 * 以下のプログラムが問題1のプログラムと同じ動作になるように，以下の2カ所に何かを書き込むことで，プログラムを完成させよ．
 **/
#include <stdio.h>

int main(void) {
  int i = 0;
  int sum = 0;
  while (i < 10) { // ( ) の中に何か書いてください．
    if (i % 2 == 0) {
      sum = sum + i;
    }
    i += 1; // この部分に何か書いてください．
  }
  printf("%d\n", sum);
  return 0;
}
