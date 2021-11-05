/*

* 생성자 오버로딩 : Overloading
1. 생성자를 여러개 만들 수 있음, 인자나 개수 혹은 자료형이 다르면 다르다고 인지

* 소멸자 : Destructor
1. 객체가 지워 질때, 뉴로 만들었으면 딜리트 될 때 호출됨
2. 스택에 할당된 객체가 스택이 없어지면서 오브젝트가 지워질 때, 소멸자가 호출
3. 있는 이유? 언매니지드 언어기 때문
	-> C++는 메모리 관리를 스스로 해야 하는데, 클래스 안에서 어떤 메모리를 할당했다면, 메모리를 해제해야 하는 책임도 있다.
	-> 내 오브젝트가 언제 지워지는지를 알아야 내가 할당한 메모리도 지울 수 있다.
*/

#pragma once
#include <iostream>

using namespace std;

class Vector
{
public:
	~Vector();

private:
	int mX;
	int mY;
};

Vector::~Vector()
{
}


int main()
{
	return 0;
}

// 클래스 안에서 동적 메모리 할당

class MyString
{
public:
	MyString();
	~MyString();
private:
	char* mChars;  // 포인터 있으면 메모리 할당한다는 이야기~
	int mLength;
	int mCapacity;
};

MyString::MyString() :mLength(0), mCapacity(15)
{
	mChars = new char[mCapacity + 1];  // 클래스 내 동적 메모리 할당
}
MyString::~MyString()
{
	delete[] mChars;
}