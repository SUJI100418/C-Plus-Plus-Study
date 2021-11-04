/*
* cin에 대하여

1. C언어 에서 scanf()가 위험한 이유: NULL(\0)을 넣을 공간이 꼭 필요하다. 근데 scanf는 길이를 알 수 없다. -> 경계검사를 하지 않는다.
2. cin는 어떨까? 위에 똑같은 문제가 있음
char[] == char * (cin도 배열 길이 모르는건 똑같음)

-> setw(n-1)으로 지정하면 됨

* 스트림 상태 (Stream States)
1. using namespace ios_base;
2. 콘솔에서 입력하고 엔터치면 엔터까지 들어감, 대신 파일에서 읽으면 엔터 안들어감

* 입력 버리기 (Discarding Input)
1. cin.clear();  abc 멈춤 -> 다시 초기화
2. cin.ignore(); 456abc에서 a버림
3. get() : 뉴라인 문자를 만나기 전까지 모든 문자 가져옴, 한 줄을 읽어옴, 뉴라인 남김
4. getline() : 뉴라인을 입력 스트림에서 버림

*/

#pragma once
#include <iostream>

using namespace std;

int main()
{
	char myName[20];
	//cin >> myName;

	if (!cin.eof()) // end-of-file : 읽을 게 없으니 포기하겠다.
	{

	}

	// Q. 입력된 문자열 뒤집기 -> 투 포인터 사용

	const int LINE_SIZE = 512;
	char line[LINE_SIZE];

	cout << "string to reverse" << endl;
	cin >> line;

	char* left = line;  // 첫캐릭터
	char* right = line + strlen(line) - 1; // 마지막캐릭터

	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		++left;
		--right;
	}

	cout << line << endl;

	return 0;
}