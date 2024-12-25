/**
 * 発展課題6
 * 行列の固有値を計算するアルゴリズムについて調べてみて，プログラムを作成してみよ．
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// QR法
// https://ja.wikipedia.org/wiki/QR%E6%B3%95

// 固有ベクトルも求めるならばヤコビ法が使われる
// https://ja.wikipedia.org/wiki/%E3%83%A4%E3%82%B3%E3%83%93%E6%B3%95_(%E5%9B%BA%E6%9C%89%E5%80%A4%E5%95%8F%E9%A1%8C)

#define N 2           // 行列サイズ
#define EPSILON 1e-8  // 収束判定用の閾値
#define MAX_ITER 1000 // 最大反復回数

// https://af-e.net/c-language-qr-decomposition/
// QR分解: グラム・シュミットの正規直交化法
void qrDecomposition(double A[N][N], double Q[N][N], double R[N][N]) {
  for (int j = 0; j < N; j++) {
    // Rの対角成分を計算
    for (int i = 0; i < N; i++) {
      R[j][j] += A[i][j] * A[i][j];
    }
    R[j][j] = sqrt(R[j][j]);

    // Qの列ベクトルを計算
    for (int i = 0; i < N; i++) {
      Q[i][j] = A[i][j] / R[j][j];
    }

    for (int k = j + 1; k < N; k++) {
      // Rの残りの要素を計算
      for (int i = 0; i < N; i++) {
        R[j][k] += Q[i][j] * A[i][k];
      }

      // ak = ak - (q1・a1)q1 - (q2・a2)q2 - ... - (qn・an)qn
      for (int i = 0; i < N; i++) {
        A[i][k] -= Q[i][j] * R[j][k];
      }
    }
  }
}

// 行列の積
void multiply_matrices(double A[N][N], double B[N][N], double C[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = 0.0;
      for (int k = 0; k < N; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// QR法による固有値計算
void qr_method(double A[N][N], double eigenvalues[N]) {
  double Q[N][N], R[N][N];
  // 対角要素の変化をチェックするために，前回の対角要素を保存
  double prevDiagonal[N];
  int iter = 0;

  // 初期化
  for (int i = 0; i < N; i++) {
    prevDiagonal[i] = A[i][i];
  }

  while (iter < MAX_ITER) {
    iter++;

    // QR分解
    qrDecomposition(A, Q, R);

    // 新しい行列 A = R * Q
    multiply_matrices(R, Q, A);

    // 対角要素の変化をチェック
    int converged = 1;
    for (int i = 0; i < N; i++) {
      if (fabs(A[i][i] - prevDiagonal[i]) > EPSILON) {
        converged = 0;
        break;
      }
    }

    // 対角要素を更新
    for (int i = 0; i < N; i++) {
      prevDiagonal[i] = A[i][i];
    }

    // 収束チェック
    if (converged) {
      break;
    }
  }

  // 固有値を取得
  for (int i = 0; i < N; i++) {
    eigenvalues[i] = A[i][i];
  }
}

int main() {
  double A[N][N] = {{3, 1}, {2, 2}};

  double eigenvalues[N];
  qr_method(A, eigenvalues);

  printf("固有値:\n");
  for (int i = 0; i < N; i++) {
    printf("%lf\n", eigenvalues[i]);
  }

  return 0;
}
