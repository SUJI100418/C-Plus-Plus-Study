/*
## 상속이란?

- 다른 클래스의 특성을 내려받은 것으로 (부모,자식) 클래스가 있다.
- 부모 클래스 : base 클래스
- 자식 클래스 : derived 클래스, 파생 클래스
	 - 부모의 멤버 변수 
	 - 부모의 멤버 함수
	 - 자신의 생성자, 소멸자

>cat is a animal.

### 생성자 호출 순서

- 부모 클래스가 먼저 호출되고 힙에 자리 할당 후 -> 자식 클래스가 할당됨
- 부모 클래스의 특정 생성자를 호출할때는 꼭 초기화 리스트를 사용해야 함. 대입은 늦음

### 자식 개체 지우기

- 자식 먼저 지운다
- 다음 ~Animal() 부모 소멸자 호출
- 부모 자식 만들고 -> 자식 부모 지우고

*/

#include<string>

class Animal
{
public:
	Animal(int age);
	void Move();

private:
	int mAge;
};

class Cat : public Animal {
public:
	Cat(int age, const char* name);
private:
	char* mName;
};

Cat::Cat(int age, const char* name):Animal(age)  // 부모의 생성자를 호출해서 age 넘겨주고 알아서 해주셈~ 하고 던져버린다. 
{
	size_t size = strlen(name) + 1;  // 문자열+1 이유는? 마지막 널문자 들어가야함
	mName = new char[size];
	strcpy(mName, name);  // 문자열 복사
}

int main()
{
	Cat* myCat = new Cat(3, "nabi");
	myCat->Move();

	return 0;
}