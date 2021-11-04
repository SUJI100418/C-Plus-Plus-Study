/*
* 참조 reference = 별칭, 닉네임 , 근데 왜 별칭이 필요함? NULL체크 안해도 됨, 포인터는 NULL 가르키면 삑사리날 가능성 있음

1. 포인터 연산(주소 변경이 없을 때)이 없어도 될 때, 안전하게 써라
	- 값에 의한 호출 Call by Value 
	- 주소에 의한 호출 Call by Address
	- 참조에 의한 호출 Call by Reference

2. 별칭 선언 int&(펭귄?) 참조형 : &number 주소 불러오는 기호랑 같지만 다른거임
3. 참조 대상을 바꿀 순 없음, 바꾸면 모두 값이 바뀜

Q. 참조랑 포인터랑 다른걸까?
어셈블리 명령어에서는 똑같이 작용함
컴파일러는 참조를 "포인터"로 바꿔 줌 -> 참조는 오로지 사람을 위한 개념

*/

#pragma once
#include <iostream>

using namespace std;

void swap_call_by_value(int arg1, int arg2) //값에 의한 복사 : 메모리 상에서 사본을 복사
{
	// 스택 : 값을 복사해서 스택 다른 어딘가에 저장, 원본이 아닌 복사한 값이 바뀌고 함수 나가면 날라감~

	int temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

void swap_call_by_address(int* arg1, int* arg2)  // 주소에 의한 복사 : 메모리 상에서 원본을 고침
{
	// 주소를 받아 복사하고 스택 어딘가에 저장, arg1 = num1 집주소, arg2 = num2 집주소
	// 할당 안된 메모리 접근 가능 +1, NULL 가르킬 수 도 있음 

	int temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

void swap_call_by_reference(int& arg1, int& arg2)  // 참조(별칭)에 의한 복사 : 메모리 상에서 원본을 고침
{
	// 주소를 받아 복사하고 스택 어딘가에 저장, arg1 = num1 집주소, arg2 = num2 집주소
	// 참조형 사용 시 장점, 변수는 NULL이 될 수 없음, 근데 포인터는 가능해서 위험함
	// 포인터 보다 더 간결 and 할당된 메모리만 사용 가능
	 
	int temp = arg1;  // 포인터 연산이 없는데 원본이 바뀐다! 
	arg1 = arg2;
	arg2 = temp;
}

int main()
{
	int num1 = 1;  // 지역 변수나 함수 호출의 매개변수 저장 = 스택
	int num2 = 5;

	swap_call_by_value(num1, num2); // 원본 안바뀜
	swap_call_by_address(&num1, &num2);  // 원본 바뀜
	swap_call_by_reference(num1, num2);  // 원본 바뀜

	int number = 100;
	int& reference = number; // 참조형 임, &number 주소 불러오는 기호랑 같지만 다른거임

	return 0;
}