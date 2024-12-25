#include <stdio.h>

int main() {
  int JapaneseScore = 0;
  int EnglishScore = 0;
  int SocialScore = 0;

  printf("Please input your Japanese score:\n");
  scanf("%d", &JapaneseScore);

  printf("Please input your English score:\n");
  scanf("%d", &EnglishScore);

  printf("Please input your Social score:\n");
  scanf("%d", &SocialScore);

  double Average = (JapaneseScore + EnglishScore + SocialScore) / 3.0;

  printf("Your average score is %f\n", Average);
  return 0;
}
