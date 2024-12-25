#include <stdio.h>

// 行列のサイズなどを表す定数は const int などのように const をつけて宣言する
const int N = 3;

int main() {
  // 行列は２次元の配列として定義する．また，右辺のベクトルも一緒に保存する．
  double M[3][4] = {{1, 2, 1, 4}, {2, -1, 3, 4}, {3, 1, -2, 2}};
  double x[3] = {0, 0, 0};
  double m;
  int i, j, k;

  for (i = 0; i < N; i++) {
    m = M[i][i];
    for (j = i; j < N + 1; j++) {
      M[i][j] = M[i][j] / m;
    }
    for (j = 0; j < N; j++) {
      if (i != j) {
        m = M[j][i];
        for (k = i; k < N + 1; k++) {
          M[j][k] = M[j][k] - m * M[i][k];
        }
      }
    }
  }

  // 変形後の行列と解を表示
  for (i = 0; i < N; i++) {
    for (j = 0; j < N + 1; j++) {
      printf("%lf ", M[i][j]);
    }
    printf("\n");
  }

  return 0;
}
