// homework_q2.c
#include <stdio.h>

// 文字列 c と d が同じかどうかを判定したい
int cmp(char *c, char *d) {
  int i = 0;

  while (c[i] != '\0' && d[i] != '\0') {
    if (c[i] != d[i]) {
      return 0;
    }
    i += 1;
  }

  return 1;
}

int main(void) {
  char c[] = "abc";
  char d[] = "def";
  char e[] = "abc";
  printf("%d\n", cmp(c, d)); // 0と表示されるようにしたい．
  printf("%d\n", cmp(c, e)); // 1と表示されるようにしたい．
  return 0;
}
