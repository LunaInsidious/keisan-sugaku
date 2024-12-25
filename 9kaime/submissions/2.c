#include <stdio.h>

#define N 1000
#define VARIABLES 9

void solveConsecutiveEquations(double M[VARIABLES][VARIABLES + 1],
                               double x[VARIABLES]) {
  double m;

  for (int i = 0; i < VARIABLES; i++) {
    m = M[i][i];
    for (int j = i; j < VARIABLES + 1; j++) {
      M[i][j] = M[i][j] / m;
    }
    for (int j = 0; j < VARIABLES; j++) {
      if (i != j) {
        m = M[j][i];
        for (int k = i; k < VARIABLES + 1; k++) {
          M[j][k] = M[j][k] - m * M[i][k];
        }
      }
    }
  }

  // 変形後の行列と解を表示
  for (int i = 0; i < VARIABLES; i++) {
    for (int j = 0; j < VARIABLES + 1; j++) {
      printf("%lf ", M[i][j]);
    }
    printf("\n");
  }
}

int main() {
  double A[N][VARIABLES];
  double M[VARIABLES][VARIABLES + 1] = {0};
  double b[N];
  double m;

  // データを読み込む部分
  for (int i = 0; i < N; i++) {
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &b[i], &A[i][0], &A[i][1],
          &A[i][2], &A[i][3], &A[i][4], &A[i][5], &A[i][6], &A[i][7]);
    A[i][8] = 1.0; //定数項を付け加えるために 1.0 を追加
  }

  // 行列 M を計算
  for (int i = 0; i < VARIABLES; i++) {
    for (int j = 0; j < VARIABLES; j++) {
      for (int k = 0; k < N; k++) {
        M[i][j] = M[i][j] + A[k][i] * A[k][j];
      }
    }
  }

  // ベクトル c を計算
  for (int i = 0; i < VARIABLES; i++) {
    M[i][9] = 0;
    for (int k = 0; k < N; k++) {
      M[i][9] += A[k][i] * b[k];
    }
  }

  // 上のプログラムを使って x を計算
  solveConsecutiveEquations(M, b);

  return 0;
}
