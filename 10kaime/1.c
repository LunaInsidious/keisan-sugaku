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
  double A[N][N] = {{2, 4, 8}, {4, 9, 17}, {6, 13, 26}};

  double L[N][N], U[N][N];

  LU(A, L, U);

  ShowMatrix(A, "A");
  ShowMatrix(L, "L");
  ShowMatrix(U, "U");

  return 0;
}
