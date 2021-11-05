/*

*������ Constructor

���� vs �ʱ�ȭ ����Ʈ ����

*/

#pragma once
#include <iostream>

using namespace std;

class Vector
{
public:
	Vector()  // ���� -> �ʱ�ȭ�� ���� �� ���� ����
	{
		mX = 0;
		mY = 0;
		
	}

	// ������: = �ʱ�ȭ ����Ʈ
	Vector(): mX(0), mY(0)  // �ʱ�ȭ ����Ʈ = �����ϸ鼭 �ʱ�ȭ
	{
	}

private:
	int mX;
	int mY;
};

// ������ ���� ������
class X
{
	const int mNameSize;
	Vector& mVector;

	X(Vector& v): mNameSize(10), mVector(v)  //-> �ʱ�ȭ ����Ʈ�� ����� ���������� �ʱ�ȭ ����
	{
		//mNameSize = 20;  //����! const�� �� ���� �Ұ���
		//mVector = v;     //���۷����� �� ���� �Ұ���!
	}
};

int main()
{
	return 0;
}

//-----------------------------------------

// �� ���� Vector Ŭ���� ����� : .h�� .cpp ������

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
// Cat Ŭ���� :: �ȿ� �ִ� ������ Cat():

//#include "Cat.h"
Cat::Cat():mX(0), mY(0){}

Cat::Cat(int x, int y): mX(x), mY(y){}
