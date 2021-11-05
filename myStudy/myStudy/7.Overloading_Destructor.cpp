/*

* ������ �����ε� : Overloading
1. �����ڸ� ������ ���� �� ����, ���ڳ� ���� Ȥ�� �ڷ����� �ٸ��� �ٸ��ٰ� ����

* �Ҹ��� : Destructor
1. ��ü�� ���� ����, ���� ��������� ����Ʈ �� �� ȣ���
2. ���ÿ� �Ҵ�� ��ü�� ������ �������鼭 ������Ʈ�� ������ ��, �Ҹ��ڰ� ȣ��
3. �ִ� ����? ��Ŵ����� ���� ����
	-> C++�� �޸� ������ ������ �ؾ� �ϴµ�, Ŭ���� �ȿ��� � �޸𸮸� �Ҵ��ߴٸ�, �޸𸮸� �����ؾ� �ϴ� å�ӵ� �ִ�.
	-> �� ������Ʈ�� ���� ������������ �˾ƾ� ���� �Ҵ��� �޸𸮵� ���� �� �ִ�.
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

// Ŭ���� �ȿ��� ���� �޸� �Ҵ�

class MyString
{
public:
	MyString();
	~MyString();
private:
	char* mChars;  // ������ ������ �޸� �Ҵ��Ѵٴ� �̾߱�~
	int mLength;
	int mCapacity;
};

MyString::MyString() :mLength(0), mCapacity(15)
{
	mChars = new char[mCapacity + 1];  // Ŭ���� �� ���� �޸� �Ҵ�
}
MyString::~MyString()
{
	delete[] mChars;
}