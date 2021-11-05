/*
* 객체지향 프로그래밍 OOP = 사람이 바라보는 관점 처럼 접근하는 것

1. Object = 물체 ex) 고양이 / 한 존재
	 ex) 고양이 Class (객체)
			맴버 변수 (상태): 이름, 성별, 나이, 종
			맴버 함수 (행동): 먹기, 걷기, 말하기, 잠자기, 사고치기

		Cat 나비 = new Cat(); 객체화 하다. 인스턴스화 하다.

2. C++ 기본 접근 제어자는 private!  (해당 클래스에서만 접근 가능)
3. private은 클래스 단위임; 객체 단위 아님; = 자식은 내 상태 모름, 부모는 내 상태 암

4. stack : 예약된 로컬 메모리 공간으로 작음 1mb 이하, 함수 호출과 반환이 이 메모리에서 일어난다. but 큰 용량을 할당하면 스택 오버플로우 발생할 수 있음
			-> 변수와 매개변수를 위해 필요한 크기를 컴파일때 알 수 있어서 메모리 할당 시 공간 탐색 안해도 댐

5. heap : 전역 메모리 공간으로 큼 GB단위, 연속된 메모리 공간을 찾아야댐; 프로그래머가 메모리를 직접 할당 및 해제해야 함 -> 메모리 누수 but 언매니즈드 언어 가능

6. 객체 배열 생성 및 소멸 
	Vector* list = new Vector[10]

7. 가비지 콜렉터 는 C#에 있는데, 메모리를 알아서 해제해준다. 그러나, 가비지 콜렉터가 갑자기 돌면 성능이 느려지기 때문에 
	-> 실시간 고성능 프로그램에선 적합하지 않다.

8. 멤버 변수 초기화 : C++는 성능 때문에 값을 초기화해주지 않음
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vector
{
public:
	int mX;
	int mY;
};

// const Vector& a : 참조로 받는다=데이터 복사 안함, 이게 더 빠름; 그리고 값 변경 안할 것
Vector AddVector_stack(const Vector& a, const Vector& b)
{
	// 스택
	Vector result;
	result.mX = a.mX + b.mX;
	result.mY = a.mY + b.mY;

	return result;
}

Vector AddVector_heap(const Vector& a, const Vector& b)
{
	// heap, 근데 함수안에서 new하면 안좋음
	Vector* result = new Vector;
	result->mX = a.mX + b.mX;
	result->mY = a.mY + b.mY;

	delete result; // new 짝꿍 delete 확인 필요! 그 함수에서 new를 하면 그 함수에서 delete하시오.
}

int main()
{
	// 1. 객체 생성 : 스택과 힙에서 생성 가능하며 방법이 다름

	Vector a;  // stack 메모리에 생성 (빠름), 얘 이거 필요하대! ㅇㅋ할당
	
	Vector* b = new Vector();   // heap 메모리에 생성 (느림), new 하는 순간 포인터로 온다! 전역 메모리를 훑고 적당한 메모리 공간 찾아서 할당

	// 2. 객체 배열

	Vector* list = new Vector[10];  // 10개의 백터 객체를 힙에 만듬
	Vector** list = new Vector*[10];  //10개의 포인터를 10개 담을 수 있는 배열을 힙에 만듬

	delete[] list;  // 배열로 동적할당 했으면 [] 반드시 넣어라. 없으면 첫번째 맴버만 소멸자 호출함
	
	return 0;
}