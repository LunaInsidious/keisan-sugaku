// list.c
#include <stdio.h>

struct data {
  double tate;
  double yoko;
  double menseki;
};

struct list {
  struct data rect;
  struct list *next;
};

int get_length(struct list *l) {
  // 次のデータがあるなら，次のデータの長さに１を加えたものを返す
  if (l->next != NULL) {
    return get_length(l->next) + 1;
  }
  // 自分だけなら長さは１
  return 1;
}

// 最後のデータのポインタを取得する関数を作りたい
struct list *get_last(struct list *l) {
  // 次のデータがあるなら，次のデータの最後を返す
  if (l->next != NULL) {
    return get_last(l->next);
  }
  // 自分だけなら自分を返す
  return l;
}

void add_element(struct list *l1, struct list *l2) {}

int main() {
  struct list l1;
  struct list l2;
  struct list l3;

  l1.rect.tate = 2.0;
  l1.rect.yoko = 3.0;
  l1.rect.menseki = 6.0;
  // NULL は，どこのアドレスも保存していない，という意味
  l1.next = NULL;

  l2.rect.tate = 1.0;
  l2.rect.yoko = 2.0;
  l2.rect.menseki = 2.0;
  // NULL は，どこのアドレスも保存していない，という意味
  l2.next = NULL;

  l3.rect.tate = 3.0;
  l3.rect.yoko = 4.0;
  l3.rect.menseki = 12.0;
  // NULL は，どこのアドレスも保存していない，という意味
  l3.next = NULL;

  l1.next = &l2;
  l2.next = &l3;

  printf("%d\n", get_length(&l1));
  printf("%lf\n",
         get_last(&l1)
             ->rect.menseki); // 最後のデータの面積である12が出力されてほしい

  return 0;
}
