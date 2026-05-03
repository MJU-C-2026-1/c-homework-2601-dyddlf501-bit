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
  scanf(" %c", &initial);   //버퍼 문제를 막기 위해 %c 앞에 공백 추가

  printf("나이를 입력하세요: ");
  scanf("%d", &age);
  
  printf("키(cm)를 입력하세요: ");
  scanf("%f", &height);

  printf("몸무게(kg)를 입력하세요: ");
  scanf("%f", &weight);

  printf("활동 지수를 입력하세요 (예: 평균 1.5, 운동선호 1.7): ");
  scanf("%f", &activity_level);

  // [조건 4] 산술연산 1개 이상 사용 (사칙연산)
  // 1. BMI 계산 (V1.0의 오타 수정 완료)
  bmi = weight / ((height / 100.0) * (height / 100.0));

  // 2. 일일 권장 칼로리 계산
  daily_calories = weight * 24 * activity_level;

  // 결과 출력
  printf("\n--- [%c]님의 건강 분석 결과 ---\n", initial);
  printf("나이: %d세\n", age);
  printf("계산된 BMI 지수: %.2f\n", bmi);
  
  // [2차 과제: 조건 분기 적용] BMI 수치에 따른 비만도 판별
  printf("건강상태: ");
  if(bmi < 18.5)
  {
    printf("저체중입니다. 영양 섭취를 조금 더 늘려보세요!\n");
  }
  else if(bmi < 23.0)
  {
    printf("정상 체중입니다. 현재의 훌륭한 상태를 유지하세요!\n");
  }
  else if(bmi < 25.0)
  {
    printf("과체중입니다. 가벼운 유산소 운동을 시작해볼까요?\n");
  }
  else
  {
    printf("비만입니다. 체계적인 식단과 운동 관리가 필요합니다.\n");
  }
  
  printf("하루 권장 섭취 칼로리: %.2f kcal\n", daily_calories);
  printf("==========================================");

  return 0;
}