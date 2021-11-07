/*

## NULL vs nullptr

NULL = 0 이라, 숫자. 
int* ptr = NULL; 이상한 함수 호출

nullptr =  null 포인터 상수
int* ptr = nullptr;

---------------------------------

## 고정 폭 정수형

int가 4바이트라는 표준이 없음.
char1 / short2/ long4 / int4/ longlong8

int8_t
intptr_t

새로 나온 표준형 자료형
int32_t score = student->GetScore();


----------------------------------

## Enum Class : 열거형

-> Enum : 정수라 비교하면 int 비교하는거랑 똑같다. 다른 클래스 비교인데도 그냥 숫자 비교 된다. (타입 체킹 안해줌)

enum class eScoreType{}
int num == eScoreType::Assignment3 // 에러, 타입 체킹 자료형 검사 한다.


----------------------------------

## 헤더에서 초기화




*/