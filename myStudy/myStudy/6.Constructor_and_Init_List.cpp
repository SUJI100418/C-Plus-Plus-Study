/*

*생성자 Constructor

대입 vs 초기화 리스트 차이

*/

#pragma once
#include <iostream>

using namespace std;

class Vector
{
public:
	Vector()  // 대입 -> 초기화가 실행 된 다음 대입
	{
		mX = 0;
		mY = 0;
		
	}

	// 생성자: = 초기화 리스트
	Vector(): mX(0), mY(0)  // 초기화 리스트 = 생성하면서 초기화
	{
	}

private:
	int mX;
	int mY;
};

// 생성자 대입 문제점
class X
{
	const int mNameSize;
	Vector& mVector;

	X(Vector& v): mNameSize(10), mVector(v)  //-> 초기화 리스트는 상수나 참조변수도 초기화 가능
	{
		//mNameSize = 20;  //에러! const는 값 변경 불가능
		//mVector = v;     //레퍼런스도 값 변경 불가능!
	}
};

int main()
{
	return 0;
}

//-----------------------------------------

// 더 나은 Vector 클래스 만들기 : .h와 .cpp 나누자

//-----------------------------------------

// Cat.h
class Cat
{
public:
	Cat();
	Cat(int x, int y);

private:
	int mX;
	int mY;
};

// Cat.cpp
// Cat 클래스 :: 안에 있는 생성자 Cat():

//#include "Cat.h"
Cat::Cat():mX(0), mY(0){}

Cat::Cat(int x, int y): mX(x), mY(y){}
