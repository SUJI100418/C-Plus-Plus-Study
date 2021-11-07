/*

## 템플릿 : 중복코드 방지 -> 자료형만 다른 중복 코드를 없애는 훌륭한 방법
-> 매개변수 일반화
-> 컨테이너의 경우 매우 적합
-> 타입마다 중복된 코드를 만들지 않아도 된다. 
-> 타입이 뭔지 모르겠지만, 일단 받는다.

-> 템플릿을 인스턴스화할 때마다, 컴파일러가 내부적으로 코드를 생성
-> 근데, 템플릿에 넣는 자료형마다 .exe 파일 크기가 증가함................

### 상수 정의하는 방법으로, enum {Max=3}; 얘는 그냥 숫자 반환 <-> const int Max = 3; 이거 쓰면 메모리 일부되서 안됨

## 클래스 템플릿은 모든 구현체는 .h 헤더 파일에 넣어야 한다.
-> .cpp에서 구현하면 컴파일러가 못찾는다. 에러 반환
-> MyArry<int> scores; 타입 꼭 넣어줘야 한다.
-> MyArry scores; 에러난다.

---------------

typename vs class : 차이 없고, 그냥 typename 쓰자.

---------------

처음 만들 때, 벡터 크기 힌계 정해놓은것
template<typename T, size_t N>
class FixedVector  // 범위 정해진 벡터
{
	T mArray[N];
}

---------------

## 템플릿 특수화 : 일반적으로 이렇게 작동하는데, 이 경우만 이렇게 쓸게!
- 특정한 템플릿 매개변수를 받도록 템플릿 코드를 커스터마이즈 하는 것
- bool 받도록 특수화 된 vector

Template<class Allocator>  -> class T 부분 사라짐
class vector<bool, Allocator>  

----------------

템플릿 장점 : 컴파일 느려짐, 컴파일러가 컴파일 도중 각 템플릿 인스턴스에 대한 코드를 만들어줌
-> 자료형만 다른 중복 코드를 없애는 훌륭한 방법

템플릿 단점 : 코딩 양 줄어듬, 런타임 속도는 빠를지도? 근데 파일 크기 커질 수 있음

-----------------

STL 알고리듬 
-> 반복자를 통해 컨테이너에 접근해 [처음,마지막) 범위에서 쓸 수 있는 함수들
-> 컨테이너 크기를 변경하지 않음 - 추가 메모리 할당 없음

-> find(), copy(), swap(), sort(), merge(), ...

-> 카피  시, [처음,마지막) 범위기 때문에 마지막 안들어감
ex) begin(), begin()+2 = begin, begin()+1 만 들어감


*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>  // 컴파일 중에 해당 자료형에 대한 함수를 만들어준다.
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	cout << Add<int>(1, 2) << endl;
	cout << Add<float>(12.61f, 2.1574f) << endl;

	return 0;
}