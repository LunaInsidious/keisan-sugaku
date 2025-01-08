#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define M 100
#define lambda 0.1
#define sigma 1.0

int solveMatrix(double D[M][M + 1]) {
  double m;

  for (int i = 0; i < M; i++) {
    m = D[i][i];
    for (int j = i; j < M + 1; j++) {
      D[i][j] = D[i][j] / m;
    }
    for (int j = 0; j < M; j++) {
      if (i != j) {
        m = D[j][i];
        for (int k = i; k < M + 1; k++) {
          D[j][k] = D[j][k] - m * D[i][k];
        }
      }
    }
  }

  return 0;
}

double k(double x, double y) {
  return exp(-((x - y) * (x - y)) / 2.0 / sigma / sigma);
}

// -5から5までの範囲で，M個のデータをランダムに生成する．
void generateData(double x[M]) {
  for (int i = 0; i < M; i++) {
    x[i] = 10.0 * rand() / (1.0 + RAND_MAX) - 5.0;
  }
}

// input は関数の入力． x[] は入力データを格納した配列．c[]
// は推定した係数を格納した配列．どちらもサイズは M．
double mymodel(double input, double x[M], double c[M]) {
  double output;
  output = 0.0;
  for (int i = 0; i < M; i++) {
    output = output + c[i] * k(x[i], input);
  }
  return output;
}

int main() {
  double x[M];
  generateData(x);

  double D[M][M + 1] = {};
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      D[i][j] = k(x[i], x[j]);
      if (i == j) {
        D[i][j] += lambda;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    D[i][M] = sin(x[i]);
  }

  solveMatrix(D);

  double c[M];
  for (int i = 0; i < M; i++) {
    c[i] = D[i][M];
  }

  double x0 = 0.0;
  while (x0 <= 5.0) {
    printf("%lf %lf %lf\n", x0, mymodel(x0, x, c), sin(x0));
    x0 += 0.1;
  }

  return 0;
}
