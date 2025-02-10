#include <stdio.h>
#include <stdlib.h>

// blas, lapackは行列を列メジャーで扱うことに注意

// https://www.ibm.com/docs/ja/xl-c-aix/13.1.0?topic=blas-function-syntax
extern void dgemm_(const char *transa, const char *transb, int *l, int *n,
                   int *m, double *alpha, const void *a, int *lda, void *b,
                   int *ldb, double *beta, void *c, int *ldc);

// https://netlib.org/lapack/explore-html-3.6.1/d7/d3b/group__double_g_esolve_ga5ee879032a8365897c3ba91e3dc8d512.html
extern void dgesv_(const int *n, const int *nrhs, double *A, const int *lda,
                   int *ipiv, double *b, const int *ldb, int *info);

// 行列の積 C = A * B
void test_blas_dgemm() {
  // M: Aの行数
  // N: Bの列数
  // K: Aの列数、Bの行数
  int M = 2, N = 3, K = 2;

  //   A = [[1, 2],
  //        [3, 4]]
  // の列メジャー表現 => {1, 3, 2, 4}
  double A[4] = {1.0, 3.0, 2.0, 4.0};
  //   B = [[5, 6, 7],
  //        [8, 9,10]]
  // の列メジャー表現 => {5, 8, 6, 9, 7, 10}
  double B[6] = {5.0, 8.0, 6.0, 9.0, 7.0, 10.0};
  double C[6] = {0.0};

  // 係数。 dgemmは C = alpha * A * B + beta * C を計算する
  double alpha = 1.0, beta = 0.0;

  // 転置なし
  char transA = 'N';
  char transB = 'N';

  // Leading Dimension
  // M, N, Kは計算に使う行列の行数、列数
  // lda, ldb, ldcは実際の行列の行数
  // 参考: http://azalea.s35.xrea.com/blas/sample1.html
  int lda = 2, ldb = 2, ldc = 2;

  dgemm_(&transA, &transB, &M, &N, &K, &alpha, A, &lda, B, &ldb, &beta, C,
         &ldc);

  // 結果を出力
  printf("C = A * B\n");
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      printf("%f ", C[j * M + i]);
    }
    printf("\n");
  }
}

void test_lapack_dgesv() {
  int n = 3, nrhs = 1, lda = 3, ldb = 3, info;
  // LU分解で行ったピボットの情報を格納する配列
  int ipiv[3];

  // 連立方程式 Ax = b を解く
  //   A = [[3, 2, -4],
  //        [2, 3, 3],
  //        [5, -3, 1]]
  // の列メジャー表現 => {3, 2, 5, 2, 3, -3, -4, 3, 1}
  double A[9] = {3.0, 2.0, 5.0, 2.0, 3.0, -3.0, -4.0, 3.0, 1.0};
  double b[3] = {3.0, 15.0, 14.0};

  dgesv_(&n, &nrhs, A, &lda, ipiv, b, &ldb, &info);

  if (info == 0) {
    printf("Ax = b の解\n");
    for (int i = 0; i < 3; i++) {
      printf("x[%d] = %f\n", i, b[i]);
    }
  } else {
    printf("dgesv failed with info = %d\n", info);
  }
}

int main() {
  test_blas_dgemm();
  printf("\n");
  test_lapack_dgesv();
  return 0;
}
