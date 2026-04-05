/* 
  파일이름: main.c
  작 성 자: 권용일 
  하 는 일: 스마트 홈트 & 다이어트 매니저 V1.0
*/

#include <stdio.h>

int main()
{
  //[조건1] 변수 5개 이상 & [조건 2] 자료형 3개 이상 (char, int, float)
  char initial;             // 이름 이니셜
  int age;                  // 나이
  float height;             // 키(cm)
  float weight;             // 몸무게(kg)
  float activity_level;     // 활동 지수
  float bmi;                // BMI 결과
  float daily_calories;     // 권장 칼로리 결과

  //[조건 3] 입출력 함수 사용 (printf, scanf)
  printf("=== 스마트 홈트 & 다이어트 매니저 V1.0 ===\n");

  printf("사용자의 이니셜(영문 1글자)을 입력하세여: ");
  scanf(" %c", &initial); //버퍼 문제를 막기 위해 %c 앞에 공백 추가

  printf("나이를 입력하세요: ");
  scanf("%d", &age);
  
  printf("키(cm)를 입력하세요: ");
  scanf("%f", &height);

  printf("몸무게(kg)를 입력하세요: ");
  scanf("%f", &weight);

  printf("활동 지수를 입력하세요 (예: 평균 1.5, 운동선호 1.7): ");
  scanf("%f", &activity_level);

  // [조건 4] 산술연산 1개 이상 사용 (사칙연산)
  // 1. BMI 계산 (cm단위인 키를 m로 변환하기 위해 100.0으로 나눔)
  bmi = weight / ((height / 100.0) * (height / 100.0));

  // 2. 일일 권장 칼로리 계산
  daily_calories = weight * 24 * activity_level;

  // 결과 출력
  printf("\n--- [%c]님의 건강 분석 결과 ---\n", initial);
  printf("나이: %d세\n", age);
  printf("계산된 BMI 지수: %.2f\n", bmi);
  printf("하루 권장 섭취 칼로리: %.2f kcal\n", daily_calories);
  printf("==========================================");

  return 0;
}