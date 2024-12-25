/**
 * 発展問題3
 * 株価変動の最も簡単なモデルとして
 * f_{n+1} = a * f_n + b * r_n
 * というものが知られている．ただし，f_nはn日目の株価，aは株価の平均的な拡大率，r_nは50％ずつの確率で-1または1をとる乱数，
 * bは乱数の大きさを調整するパラメータである．株価は（銀行の利息と同じように）基本的には増えていく(f_(n+1)=a*f_n)が，
 * ある程度，ランダムな動きもするため，b * r_nという項が加えられている．
 */

/**
 * 発展問題3-1
 * 1日目の株価，a, b,
 * n（日数）の値を引数として，n日後の株価f_nを戻り値とする関数を作成せよ．
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulateNextPrice(double a, double f, double b, int r) {
  return a * f + b * r;
}

double simulateStockPrice(double f, double a, double b, int n) {
  srand((unsigned int)time(NULL));
  for (int i = 0; i < n; i++) {
    int r = rand() % 2 == 0 ? -1 : 1;
    f = simulateNextPrice(a, f, b, r);
  }
  return f;
}
