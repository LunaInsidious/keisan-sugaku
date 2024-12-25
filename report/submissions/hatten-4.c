/**
 * 発展課題4
 * ギター音のシミュレーションを行ったときに利用した，音声ファイルを作成するpythonプログラムを利用して，
 * 適当な周波数のsin,cosを音声化すると，周波数に応じた高さの音が鳴る．これを利用して，簡単な曲を鳴らすプログラムを作成してみよ．
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

// https://www.maustopia.com/2021/11/07/sample_rate-2/
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846
#define BPM 120
// 1拍の長さ
#define BEAT_LENGTH (60.0 / BPM)
// 実際の演奏に近づけるために，音符と音符の間に短い休符を入れる。
// 感覚的に、値は0.0005くらいがいい感じっぽい。
#define REST_LENGTH 0.0005

// 音階とその音階を何拍出すかを表す構造体
typedef struct {
  char *noteName;
  double duration;
} Note;

// 音階データを生成する関数
void generateTone(double frequency, double duration, double *phase) {
  int num_samples = (int)(duration * SAMPLE_RATE);
  for (int i = 0; i < num_samples; i++) {
    *phase += 2 * PI * frequency / SAMPLE_RATE;
    double sample = sin(*phase); // 波形を生成
    printf("%lf\n", sample);
  }
}

// https://www.tomari.org/main/java/oto.html
// 音階名から周波数を計算して返す
double calculateFrequency(const char *noteName) {
  size_t len = strlen(noteName);

  // 最後の文字が0から8の範囲にない場合は例外
  if (noteName[len - 1] < '0' || noteName[len - 1] > '8') {
    return -1.0;
  }

  // 音階名とオクターブに分割
  char note[6];
  strncpy(note, noteName, len - 1);
  note[len - 1] = '\0';

  int octave = noteName[len - 1] - '0';

  // 通常常音階(ラ4)との差分を計算
  int octaveDiff = octave - 4; // ラ4が440Hzなので，オクターブの差分を計算
  int noteDiff = 0;            // 音階の差分を計算

  if (strcmp(note, "ド") == 0) {
    noteDiff = -9;
  } else if (strcmp(note, "ド#") == 0) {
    noteDiff = -8;
  } else if (strcmp(note, "レ") == 0) {
    noteDiff = -7;
  } else if (strcmp(note, "レ#") == 0) {
    noteDiff = -6;
  } else if (strcmp(note, "ミ") == 0) {
    noteDiff = -5;
  } else if (strcmp(note, "ファ") == 0) {
    noteDiff = -4;
  } else if (strcmp(note, "ファ#") == 0) {
    noteDiff = -3;
  } else if (strcmp(note, "ソ") == 0) {
    noteDiff = -2;
  } else if (strcmp(note, "ソ#") == 0) {
    noteDiff = -1;
  } else if (strcmp(note, "ラ") == 0) {
    noteDiff = 0;
  } else if (strcmp(note, "ラ#") == 0) {
    noteDiff = 1;
  } else if (strcmp(note, "シ") == 0) {
    noteDiff = 2;
  } else {
    printf("Invalid note name: %s\n", note);
    return -1.0;
  }

  int semitoneDiff = octaveDiff * 12 + noteDiff;

  // 周波数を計算
  double frequency = 440.0 * pow(2.0, semitoneDiff / 12.0);

  return frequency;
}

// 休符を生成する関数
void generateRest(double duration) {
  int num_samples = (int)(duration * SAMPLE_RATE);
  for (int i = 0; i < num_samples; i++) {
    printf("0.0\n"); // 無音部分を出力
  }
}

int main() {
  // 参考:https://youtu.be/htxK-W8PHR4?si=bjkZqvVMlr4EDv6k の難易度1
  Note notes[] = {
      {"ソ4", 0.75},   {"ソ4", 0.25}, {"ラ4", 1.0},  {"ソ4", 1.0},
      {"ド5", 1.0},    {"シ4", 2.0},  {"ソ4", 0.75}, {"ソ4", 0.25},
      {"ラ4", 1.0},    {"ソ4", 1.0},  {"レ5", 1.0},  {"ド5", 2.0},
      {"ソ4", 0.75},   {"ソ4", 0.25}, {"ソ5", 1.0},  {"ミ5", 1.0},
      {"ド5", 1.0},    {"シ4", 1.0},  {"ラ4", 1.0},  {"ファ5", 0.75},
      {"ファ5", 0.25}, {"ミ5", 1.0},  {"ド5", 1.0},  {"レ5", 1.0},
      {"ド5", 2.0}};

  // sizeofはバイト単位で返すのでこれで要素数を求めることができる。
  int num_notes = sizeof(notes) / sizeof(notes[0]);

  // 波形の位相
  double phase = 0.0;

  for (int i = 0; i < num_notes; i++) {
    double frequency = calculateFrequency(notes[i].noteName);
    if (frequency < 0) {
      printf("Invalid note name: %s\n", notes[i].noteName);
      return 1;
    }
    generateTone(frequency, BEAT_LENGTH * notes[i].duration, &phase);
    generateRest(REST_LENGTH);
  }

  return 0;
}
