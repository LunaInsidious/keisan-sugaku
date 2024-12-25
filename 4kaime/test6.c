#include <stdio.h>

int main(void) {
  double InitialNonInfectedNum = 99;
  double InitialLatentInfectedNum = 0;
  double InitialInfectedNum = 1;
  double InitialRecoveredNum = 0;
  const double InfectionConst = 0.0003;
  const double RecoverConst = 0.02;

  double NonInfectedNum = InitialNonInfectedNum;
  double LatentInfectedNum = InitialLatentInfectedNum; // 潜伏期間中の感染者
  double InfectedNum = InitialInfectedNum;
  double RecoveredNum = InitialRecoveredNum;

  int DaysAfter = 0;

  printf("何日後の状態を知りたいですか？\n");
  scanf("%d", &DaysAfter);

  for (int i = 0; i < DaysAfter; i++) {
    // 新しく感染する場合、非感染者と感染者の人数に比例する。
    double NonInfectedNumTmp =
        NonInfectedNum - InfectionConst * NonInfectedNum * InfectedNum;
    // 潜伏感染者は潜伏感染者の人数に比例して回復する。
    double LatentInfectedNumTmp = InfectionConst * NonInfectedNum * InfectedNum;
    // 1日で快復しなかった潜伏感染者は感染者になる。
    // 感染者は感染者の人数に比例して回復する。
    double InfectedNumTmp = InfectedNum +
                            (1 - RecoverConst) * LatentInfectedNum -
                            RecoverConst * InfectedNum;
    double RecoveredNumTmp = RecoveredNum + RecoverConst * InfectedNum +
                             RecoverConst * LatentInfectedNum;

    NonInfectedNum = NonInfectedNumTmp;
    LatentInfectedNum = LatentInfectedNumTmp;
    InfectedNum = InfectedNumTmp;
    RecoveredNum = RecoveredNumTmp;
  }

  printf("感染定数%f, 快復定数%fの際の%d日後の状態\n", InfectionConst,
         RecoverConst, DaysAfter);
  printf("感染したことがない人は %lf 人\n", NonInfectedNum);
  printf("潜伏期間中の感染者は %lf 人\n", LatentInfectedNum);
  printf("感染している人は %lf 人\n", InfectedNum);
  printf("回復した人は %lf 人\n", RecoveredNum);
  return 0;
}
