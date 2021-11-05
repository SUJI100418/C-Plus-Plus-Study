/*
* 문자열 비교 연산자 : Relationg

apple == firstName : 같으면 0 반환, 아스키 코드로 보면 AB<AC = 사전 상의 순서 비교

string은 class 이다. -> 여러 함수가 있음;

1. size() 
2. length()
3. c_str() : const char* = 해당 string이 가지고 있는 문자 배열의 시작 주소를 가리키는 포인터 반환
	왜 필요한가? c 스타일의 문자열을 써야 기존 c 함수 쓸 수 있음; c언어에는 string이 없음
	운영체제 함수도 c기반이라 char*를 요청한다. 


4. c 헤더 써도 됩니까? c++ 어플에서는 여전히 성능 상의 이유로 많은 c함수 사용함
	<string.h> -> <cstring> 

5. 왜 string이 더 좋을까? 문자 배열 길이에 관해 고민할 필요 없음
	-> 어떻게 작동? line에서 pointer(힙 메모리 할당:동적)를 이용해 메모리 복사로 할당
	-> 결국 메모리 단편화 문제가 발생; 힙 메모리 할당도 느림

*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// std::string(클래스)
	string firstName = "Jang";
	string fullName = "Suji Jang";

	// 대입
	fullName = firstName;
	
	// 덧붙이기
	fullName += "Gaule";
	cout << fullName <<' ' << fullName.size()<< endl;

	// const char* 시작 주소 반환 : 메모리랑 길이 알아서 관리해주는 것!
	// char* 포인터가 가리키는 위치는 메모리 복사 및 할당 때문에 바꿀 수 있는데,
	// const 포인터가 가리키고 있는 문자열 내용(캐릭터 어레이)은 바꿀 수 없다.

	string line;
	cin >> line;

	// const 읽는 방법 : 오른쪽에서 왼쪽으로 읽어라! const char* = 포인터 투 ;차 콘스트 (캐릭터를 바꿀 수 없다) 
	// 주소를 못 바꾸게 하고 싶다면 : 콘스트 포인트 투 차 = char *const
	const char* cLine = line.c_str();  // 클래스에서 c스타일의 char가 나온대!
	cout << cLine << endl;

	// Q. 문자열 뒤집어서 덧붙이기 : abc -> abccba
	
	int last_char = (int)line.size() - 1;

	// 맨 뒤 캐릭터에서 앞으로 순회
	for (int i = (int)line.size() - 1; i >= 0; --i)
	{
		line += line[i];
	}

	cout << "뒤에 덧붙이기" << line << endl;

	return 0;
}
