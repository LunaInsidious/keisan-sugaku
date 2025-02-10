#include <math.h>
#include <stdio.h>

// データは 1000個
#define N 1000

int main() {
  // データの数を N とする．実際にはデータは100個.
  double data[N];
  int i;

  // 事前分布は，平均 0，分散 1
  double average = 0.0;
  double std = 1.0;

  for (i = 0; i < N; i++) {
    scanf("%lf\n", &data[i]);
  }

  // 求めた漸化式でアップデート
  for (i = 0; i < N; i++) {
    average = (data[i] * (std * std) + average) / (std * std + 1);
    std = sqrt((std * std) / (std * std + 1));

    // printf でアップデート後の average,std を出力
    printf("%lf %lf\n", average, std);
  }

  // printf で最終的に得られた average, std を出力
  printf("%lf %lf\n", average, std);

  return 0;
}
