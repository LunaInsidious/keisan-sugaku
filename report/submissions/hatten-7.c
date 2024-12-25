/**
 * 発展課題7
 * 線形計画法，特に単体法について調べてみて，プログラムを作成してみよ．
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITER 1000 // 最大反復回数
#define EPSILON 1e-6  // 許容誤差

// 行列の表示
void printTableau(int m, int n, double tableau[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%10.4f ", tableau[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/**
 * @param m 制約数 + 1
 * @param n 変数数 + スラック変数数 + 1
 * @param tableau 制約1, 制約2, ..., 目的関数の順に格納された拡張テーブル形式
 */
void simplex(int m, int n, double tableau[m][n]) {
  int iter = 0;

  while (iter < MAX_ITER) {
    iter++;

    // 1. ピボット列を選択（最も負の列）
    int pivotCol = -1;
    for (int i = 0; i < n - 1; i++) {
      // 目的関数行の係数が負の場合
      if (tableau[m - 1][i] < EPSILON) {
        if (pivotCol == -1 || tableau[m - 1][i] < tableau[m - 1][pivotCol]) {
          pivotCol = i;
        }
      }
    }

    // 最適解に到達（目的関数行に負の値がない）
    if (pivotCol == -1) {
      printf("最適解に到達しました。\n");
      break;
    }

    // 2. ピボット行を選択（最小比率テスト）
    int pivotRow = -1;
    double minRatio = INFINITY;
    for (int i = 0; i < m - 1; i++) {
      double ratio = tableau[i][n - 1] / tableau[i][pivotCol];
      if (ratio < minRatio) {
        minRatio = ratio;
        pivotRow = i;
      }
    }

    // 解が無限大の場合（制約がない）
    if (pivotRow == -1) {
      printf("解は無限大です。\n");
      return;
    }

    // 3. ピボット操作
    double pivotValue = tableau[pivotRow][pivotCol];
    for (int j = 0; j < n; j++) {
      tableau[pivotRow][j] /= pivotValue;
    }

    for (int i = 0; i < m; i++) {
      if (i != pivotRow) {
        double factor = tableau[i][pivotCol];
        for (int j = 0; j < n; j++) {
          tableau[i][j] -= factor * tableau[pivotRow][j];
        }
      }
    }

    // 中間結果を表示
    printf("反復 %d のテーブル:\n", iter);
    printTableau(m, n, tableau);
  }

  // 最適解を出力
  printf("最適解:\n");
  for (int i = 0; i < n - 1; i++) {
    // 単位列ベクトルかどうか
    int isBasic = 1;
    // 基底候補の行
    int basicRow = -1;
    for (int j = 0; j < m - 1; j++) {
      if (fabs(tableau[j][i] - 1.0) < EPSILON) {
        if (basicRow == -1) {
          basicRow = j;
        } else {
          isBasic = 0;
          break;
        }
      } else if (fabs(tableau[j][i]) > EPSILON) {
        isBasic = 0;
        break;
      }
    }

    if (isBasic && basicRow != -1) {
      printf("x%d = %10.4f\n", i + 1, tableau[basicRow][n - 1]);
    } else {
      printf("x%d = %10.4f\n", i + 1, 0.0);
    }
  }

  // 目的関数の値を出力
  printf("z = %10.4f\n", tableau[m - 1][n - 1]);
}

int main() {
  // 参考：(考え方のみ。コードもあったが無視して1から考えた)
  // https://okasho-engineer.com/simplex-method-first/
  // https://tsunelab-programming.com/linear_programming
  // 標準形に基づいた拡張テーブル形式 (スラック変数を含む)
  int m = 3; // 制約数 + 1
  int n = 5; // 変数数 + スラック変数数 + 1
  double tableau[3][5] = {
      {8, 2, 1, 0, 9},  // 制約1
      {3, 3, 0, 1, 12}, // 制約2
      {-2, -3, 0, 0, 0} // 目的関数
  };

  printf("初期テーブル:\n");
  printTableau(m, n, tableau);

  // 単体法実行
  simplex(m, n, tableau);

  return 0;
}
