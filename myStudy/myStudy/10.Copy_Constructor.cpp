/*
Ŭ�� = ���� ������ : ���� Ŭ������ ���� �ٸ� ��ü�� �̿��� ���ο� ��ü�� �ʱ�ȭ

-> ����� ���� �Ͼ�� �����ڿ��� �����ص帲
-> �������� �Ű������� const �� �ڽ�
-> ���� ���� Ŭ������ �ִ� �ٸ� ��ü�� ����
-> ���� �Ȱ��� Ŭ������ ����

-> �����Ϸ��� �ڵ����� �������, �⺻ ������ ó�� = ���� ���� (shallow copy)
*/

class Vector
{
public:
	Vector(const Vector& other); //const �� �ڽ� Ŭ����
private:
	int mX;
	int mY;
};

//other�� �ٸ� ��ü���� ���� Ŭ������ private�� ���� ����
Vector::Vector(const Vector& other) : mX(other.mX), mY(other.mY)
{
	// ���� ���� : ������, Ŭ������ ������ �� ������ �ִٸ�?
}

Vector a;     // �Ű� ���� ���� ������
Vector b(a);  // ���� ������ ȣ��

//--------------------------------------------------------------

// ���� ������ ������ -> Ŭ������ �����Ͱ� �ִٸ�? ���� �Ҵ��� �ִٸ�? �����͸� �׳� �����ع����� �޸� ���� ���� �߻�
// = ������ ����ִµ� ���纻�� delete�Ǹ� ������ ���� �����

#include <iostream>

class ClassRecord
{
public:
	ClassRecord(const int* scores, int count);  // ���� ���� : �����Ϸ��� �ڵ� ����
	ClassRecord(const ClassRecord* other);  // ���� ����
	~ClassRecord();
private:
	int mCount;
	int* mScores;
};

ClassRecord::ClassRecord(const int* scores, int count) : mCount(count)
{
	mScores = new int[mCount];
	memcpy(mScores, scores, mCount * sizeof(int));
}

ClassRecord::~ClassRecord()
{
	delete[] mScores;  
}

int scores[] = [1, 2, 3];
ClassRecord classRe(scores, 5); // -> ���� ������ �����
ClassRecord* classRe_copy = new ClassRecord(classRe);
delete classRe_copy;  // ������ ����ִµ� ���纻�� delete�Ǹ� ������ ���� �����, ������ ������ ����

//------------------------------------

// ���� ���� (deep copy)
// -> ���� ���� �����ڸ� ���� ������ ������ ����Ű�� ���� �����ͱ����� ����

ClassRecord::ClassRecord(const ClassRecord& other) : mCount(other.mCount)
{
	mScores = new int[mCount];
	memcpy(mScores, other.mScores, mCount * sizeof(int));  // ���� ��ü ����, ������ �纻�� ����
}