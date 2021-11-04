/*
* namespace : 이름 충돌을 피하기 위해 공간에 이름을 붙인 것, 소문자로 쓰는것이 원칙

1. std(스탠다드 라이브러리, 네임스페이스)::cout(클래스, 콘솔 아웃)
2. using 지시문 : std 생략 가능, 타이핑 줄이기 위한 용

3. << 연산자 : push 연산자, 프로그래머가 기능 변경 가능
4. 출력형식 지정 (Output Formatting) = 조정자 사용 : showbase 등 ex) 16 진수 출력, 정렬 등

주석 설정 : Ctrl + K + C
주석 해제 : Ctrl + K + U

속성 : 빌드 제외

*/

#pragma once // 해더가 한번만 #include 됨 ; 충돌 방지

#include <iostream>
#include <iomanip> // 매니플레이트 : setw(), 함수처럼 매개변수를 받는다

using namespace std; 

namespace hello
{
	void SayHello() {};
}

namespace hi
{
	void SayHello() {};
}

int main()
{
	// namespace 실습
	hello::SayHello();
	hi::SayHello();

	// using namespace std; 실습
	cout << "Hello, World" << endl;

	// 여러가지 변수형 정의 및 출력
	int integer = 1;
	float decimal = 1.5f;
	char letter = 'A';
	char string[] = "Hello, world!";

	cout << string << endl;

	// showbase(몇 진법인가?) << hex : 16진수 출력, oct 는 8진수
	cout << showbase << hex << 123 << endl;

	// showpos : positive 일 때, + 사인 보여주는 것
	cout << showbase << dec << showpos << 50 << endl;

	// setw(6) 컬럼 수 셋팅 : 몇글자까지 세팅할 것인가
	cout << setw(6) << right << 10;

	return 0;
}