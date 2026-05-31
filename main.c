/* 
  파일이름: main.c
  작 성 자: 권용일 
  하 는 일: 스마트 홈트 & 다이어트 매니저 V3.0
*/

#include <stdio.h>

// 1. 전역/지역 변수 관리
int total_usage_count = 0;  // 전체 이용 횟수를 저장하는 전역 변수

// 2. 함수 선언 (3개 이상의 개별 함수 분리)
// 매개변수(인자)를 받고, 결과를 return 하는 함수들
float calculate_bmi(float height, float weight);
float calculate_calories(float weight, float activity_level);
// 매개변수를 받으며, 내부에서 전역 변수를 업데이트하는 함수
void print_analysis_result(char initial, int age, float bmi, float daily_calories);

int main()
{
  // main 함수 내부에서만 사용되는 지역 변수들
  int choice;               // choice 
  char initial;             // 이름 이니셜
  int age;                  // 나이
  float height;             // 키(cm)
  float weight;             // 몸무게(kg)
  float activity_level;     // 활동 지수
  float bmi;                // BMI 결과
  float daily_calories;     // 권장 칼로리 결과

  // 3. 사용자 메뉴 구성 (while(1) 무한 루프 활용)
  while(1)
  {
    printf("\n=== 스마트 홈트 & 다이어트 매니저 V3.0 ===\n");
    printf("1. 건강 정보 입력 및 분석\n");
    printf("2. 누적 이용 횟수 조회\n");
    printf("3. 프로그램 종료\n");
    printf("메뉴를 선택하세요 (1~3): ");
    scanf("%d", &choice);

    if(choice == 1)
    {
      // 입력 부
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

      // 메인 로직은 목차처럼 함수 호출 위주로 간결하게 구성
      bmi = calculate_bmi(height, weight);
      daily_calories = calculate_calories(weight, activity_level);

      // 결과 출력 맟 전역변수 업데이트 함수 호출
      print_analysis_result(initial, age, bmi, daily_calories);
    }
    else if(choice == 2)
    {
      // 조회 부
      printf("\n현재까지 총 %d번의 건강 분석이 수행되었습니다.\n", total_usage_count);
    }
    else if(choice == 3)
    {
      // 4. 사용자가 '종료' 선택 시 break로 끝내기
      printf("\n프로그램을 종료합니다. 건강한 하루 보내세요!\n");
      break;
    }
    else
    {
      printf("\n 잘못된 입력입니다. 1, 2, 3 중에서 선택해 주세요.\n");
    }
  }  
  
  return 0;
}
// =========================
// 함수 정의부
// =========================

// 매개변수를 전달받고 반환값을 return 하는 함수 1
float calculate_bmi(float height, float weight)
{
  float height_m = height /100.0; //지역 변수
  return weight / (height_m * height_m);
}

// 매개변수를 전달받고 반환값을 return 하는 함수 2 
float calculate_calories(float weight, float activity_level)
{
  return weight * 24 * activity_level;
}

// 전역 변수 값을 내부에서 직접 변경하는 함수 3
void print_analysis_result(char initial, int age, float bmi, float daily_calories)
{
  // 핵심 평가 요소 : 함수 내부에서 전역변수 값 업데이트 로직 포함
  total_usage_count++;

  printf("\n--- [%c]님의 건강 분석 결과 ---\n", initial);
  printf("나이 : %d세 \n", age);
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

}