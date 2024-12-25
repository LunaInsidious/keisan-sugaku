#include <stdio.h>

int main(void) {
  double InitialNonInfectedNum = 99;
  double InitialInfectedNum = 1;
  double InitialRecoveredNum = 0;
  const double InfectionConst = 0.0003;
  const double RecoverConst = 0.02;

  double NonInfectedNum = InitialNonInfectedNum;
  double InfectedNum = InitialInfectedNum;
  double RecoveredNum = InitialRecoveredNum;

  const int DaysAfter = 365;

  for (int i = 0; i < DaysAfter; i++) {
    double NonInfectedNumTmp =
        NonInfectedNum - InfectionConst * NonInfectedNum * InfectedNum;
    double InfectedNumTmp = InfectedNum +
                            InfectionConst * NonInfectedNum * InfectedNum -
                            RecoverConst * InfectedNum;
    double RecoveredNumTmp = RecoveredNum + RecoverConst * InfectedNum;

    NonInfectedNum = NonInfectedNumTmp;
    InfectedNum = InfectedNumTmp;
    RecoveredNum = RecoveredNumTmp;
  }

  printf("感染定数%f, 快復定数%fの際の%d日後の状態\n", InfectionConst,
         RecoverConst, DaysAfter);
  printf("感染したことがない人は %lf 人\n", NonInfectedNum);
  printf("感染している人は %lf 人\n", InfectedNum);
  printf("回復した人は %lf 人\n", RecoveredNum);
  return 0;
}
