#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i, j;
  int A[2][2] = {{1, 2},
                 {3, 4}}; // 2x2行列を保存するための，2次元の配列を宣言せよ．
  int v[2] = {5,
              6}; // 2次元のベクトルを保存するための，１次元の配列を宣言せよ．
  int w[2] = {
      0,
      0}; //計算結果の２次元のベクトルを保存するための，１次元の配列を宣言せよ．
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      w[i] = w[i] + A[i][j] * v[j];
    }
  }
  srand((unsigned int)time(NULL)); // シードを設定
  printf("%d\n", rand());
  printf("%d, %d\n", w[0], w[1]);
  return 0;
}
