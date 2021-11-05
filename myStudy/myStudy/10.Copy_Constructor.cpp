/*
클론 = 복사 생성자 : 같은 클래스에 속한 다른 개체를 이용해 새로운 개체를 초기화

-> 복사는 많이 일어나니 생성자에서 지원해드림
-> 생성자의 매개변수가 const 나 자신
-> 나랑 같은 클래스에 있는 다른 개체를 복사
-> 나랑 똑같은 클래스에 속함

-> 컴파일러가 자동으로 만들어줌, 기본 생성자 처럼 = 얕은 복사 (shallow copy)
*/

class Vector
{
public:
	Vector(const Vector& other); //const 나 자신 클래스
private:
	int mX;
	int mY;
};

//other은 다른 개체지만 같은 클래스라 private에 접근 가능
Vector::Vector(const Vector& other) : mX(other.mX), mY(other.mY)
{
	// 얕은 복사 : 문제점, 클래스에 포인터 형 변수가 있다면?
}

Vector a;     // 매개 변수 없는 생성자
Vector b(a);  // 복사 생성자 호출

//--------------------------------------------------------------

// 얕은 복사의 문제점 -> 클래스에 포인터가 있다면? 동적 할당이 있다면? 포인터를 그냥 복사해버려서 메모리 공유 문제 발생
// = 원본이 살아있는데 복사본이 delete되면 원본도 같이 사라짐

#include <iostream>

class ClassRecord
{
public:
	ClassRecord(const int* scores, int count);  // 얕은 복사 : 컴파일러가 자동 생성
	ClassRecord(const ClassRecord* other);  // 깊은 복사
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
ClassRecord classRe(scores, 5); // -> 원본 정보도 사라짐
ClassRecord* classRe_copy = new ClassRecord(classRe);
delete classRe_copy;  // 원본이 살아있는데 복사본이 delete되면 원본도 같이 사라짐, 데이터 공유의 문제

//------------------------------------

// 깊은 복사 (deep copy)
// -> 직접 복사 생성자를 만들어서 포인터 변수가 가리키는 실제 데이터까지도 복사

ClassRecord::ClassRecord(const ClassRecord& other) : mCount(other.mCount)
{
	mScores = new int[mCount];
	memcpy(mScores, other.mScores, mCount * sizeof(int));  // 원본 객체 안전, 나만의 사본을 만듬
}