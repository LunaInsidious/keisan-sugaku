#include <stdio.h>
#include <stdlib.h>

int main() {
  // 1000件のデータから求めた回帰係数
  const double c1 = 37980.091506;
  const double c2 = 154.981087;
  const double c3 = 2.671621;
  const double c4 = -37.112428;
  const double c5 = 28.375507;
  const double c6 = 129.811052;
  const double c7 = 202023.597623;
  const double c8 = 65042.141377;
  const double c9 = 365049.078579;

  // N+1件目からのデータを取得
  const int N = 0;
  // M件のデータを取得
  const int M = 1000;

  // 差分を保持しておく
  double diffs[M];

  // 1行ずつ読み込む
  for (int i = 0; i < M; i++) {
    char command[100];
    sprintf(command, "head -n %d cadata.txt | tail -n 1", 28 + N + i);

    FILE *fp;
    fp = popen(command, "r");
    if (fp == NULL) {
      printf("Failed to run command\n");
      return 1;
    }

    char result[1000];
    double answer, x1, x2, x3, x4, x5, x6, x7, x8;

    if (fgets(result, sizeof(result), fp) != NULL) {
      double answer, x1, x2, x3, x4, x5, x6, x7, x8;
      if (sscanf(result, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", &answer, &x1,
                 &x2, &x3, &x4, &x5, &x6, &x7, &x8) == 9) {
        // printf(
        //     "読み取ったデータ: 住宅価格=%lf, 収入=%lf, 築年数=%lf, "
        //     "総部屋数=%lf, "
        //     "総ベッドルーム数=%lf, 人口=%lf, 世帯数=%lf, 緯度=%lf,
        //     経度=%lf\n", answer, x1, x2, x3, x4, x5, x6, x7, x8);

        double predictedPrice = c1 * x1 + c2 * x2 + c3 * x3 + c4 * x4 +
                                c5 * x5 + c6 * x6 + c7 * x7 + c8 * x8 + c9;
        // printf("予測された住宅価格: %lf\n", predictedPrice);
        printf("diff: %lf\n", predictedPrice - answer);
        diffs[i] = predictedPrice - answer;
      } else {
        printf("データの解析に失敗しました。\n");
      }
    } else {
      printf("データの読み込みに失敗しました。\n");
    }
    pclose(fp);
  }

  // 差分の平均を求める
  double sum = 0;
  for (int i = 0; i < M; i++) {
    sum += diffs[i];
  }
  double average = sum / M;
  printf("diffの平均: %lf\n", average);

  return 0;
}
