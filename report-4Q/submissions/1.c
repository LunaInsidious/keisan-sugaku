#include <stdio.h>

#define N 3 // 行列のサイズ

void LU(double A[N][N], double L[N][N], double U[N][N]) {
  // LとUの初期化
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        L[i][j] = 1; // 対角成分だけを1にすることで単位行列にする
      } else {
        L[i][j] = 0;
      }
      U[i][j] = 0; // U はゼロ行列にする
    }
  }

  // U の i + 1 行，Lの i + 1 列を，この順番に計算していく
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      U[i][j] = A[i][j];
      for (int k = 0; k < i; k++) {
        U[i][j] -= L[i][k] * U[k][j];
      }
    }

    for (int j = i + 1; j < N; j++) {
      L[j][i] = A[j][i];
      for (int k = 0; k < i; k++) {
        L[j][i] -= L[j][k] * U[k][i];
      }
      L[j][i] /= U[i][i];
    }
  }
}

// 行列を表示するための関数
void ShowMatrix(double mat[N][N], char name[]) {
  int i, j;
  printf("%s:\n", name);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%lf ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// main 関数
int main() {
  double A[N][N] = {{5, 6, 7}, {10, 20, 23}, {15, 50, 67}};
  double b[N] = {34, 93, 212};

  double L[N][N], U[N][N];

  LU(A, L, U);

  ShowMatrix(A, "A");
  ShowMatrix(L, "L");
  ShowMatrix(U, "U");

  // LU分解した結果からAx=bを解く
  double y[N], x[N];
  for (int i = 0; i < N; i++) {
    y[i] = b[i];
    for (int j = 0; j < i; j++) {
      y[i] -= L[i][j] * y[j];
    }
  }

  for (int i = N - 1; i >= 0; i--) {
    x[i] = y[i];
    for (int j = i + 1; j < N; j++) {
      x[i] -= U[i][j] * x[j];
    }
    x[i] /= U[i][i];
  }

  for (int i = 0; i < N; i++) {
    printf("x[%d] = %lf\n", i, x[i]);
  }

  return 0;
}
