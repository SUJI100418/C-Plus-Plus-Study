/*

### C++ 흑마법 = 다중 상속, C#은 안씀
- 메모리 측면에서 살펴봐야 함 (면접용)
- 다이아몬드 상속 등 여러 문제 발생

-> 대신 인터페이스 사용하자.

### 추상 클래스 = 구체적인 클래스(함수의 구현체가 있는 클래스)가 아닌 것
- 구체적인 함수의 구현이 없는 클래스
- virtual void Speak() = 0;  -> 순수 가상함수
- 동물이 무슨 말을 할지 모르겠당. 0의미 = null, 여기선 구현 안할겜 = 추상클래스
- 구현체가 없는 멤버 함수로 파생 클래스가 구현해야댐

- 순수 가상함수를 가지고 있는 베이스 클래스
	- 추상 클래스는 객체를 만들 수 없음
	- 근데, 포인터나 참조형으론 사용 가능함 ex) Animal* myCat = new Cat(); 이거 된다는 소리 , Animal* myAnimal = new Animal() 이건 안됨


### 인터페이스
- 데이터가 없고, 순수 가상함수만 있음, 동작만 정의
- 전구 스위치의 온/오프 동작만 정의


*/

class Teacher
{

};

class Student
{

};

class TA : public Teacher, public Student // 다중 상속
{
	// 어떤 부모의 생성자가 호출될까?
	// 초기화 리스트 상관없이, 상속 순서대로 호출


};

TA* myTA = new TA();

myTA->Student::Fun();  // 어떤 함수인지 알려줘야댐 -> 문제점1

// 다이아몬드 문제 -> 라이거

애니멀 - 타이거, 라이언
라이거 - 타이거 + 라이언

라이어 안에 animal은 몇개? 2개

상속 받을때 라이언에도 virtual public Animal, 타이거에도 virtual pulic Animal으로 상속 받으면
애니멀은 1개만 상속받지만... 글쎄..? 버추얼 상속 -> 문제점2

//--------------
// 인터페이스 : 다중 상속이기만... 데이터 중복도 없고 함수 중복도 없음

class IFlyable
{
public:
	virtual void Fly() = 0;
};

class IWalkable
{
public:
	virtual void Walk() = 0;
};

class Bat : public IFlyable, IWalkable  // 동작을 다중 상속 받음
{
public:
	void Fly();
	void Walk();
};

