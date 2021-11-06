/*

연산자 = 함수처럼 작동하는 부호

1. 단항 연산자 ex) &, ~
2. 이항 연산자 ex) &&, *=
3. 함수호출 연산자 : ()
4. 첨자 연산자 : []
5. new 
6. delete

friend 키워드 
-> 클래스 정의 안에 friend 키워드 사용하여 다른 클래스나 함수가 나의 private에 접근 가능하도록 허용
-> 다른 클래스에 내 금고 털라고 접근 권한 주는 함수 
-> friend void x() 를 클래스 함수로 만들어도 전역함수 취급함

* const& 이유?
-> 불필요한 개체의 사본 생성을 방지
-> 맴버 변수가 바뀌는것도 방지

*/

class Vector
{
public:
	friend Vector operator+(const Vector& other);  //전역 함수임
private:
	int mX;
	int mY;
};

// 연산자 오버로딩
Vector operator+(const Vector& other)  //전역 함수임
{
	Vector sum;
	sum.mX = mX + other.mX;
	sum.mY = mY + other.mY;

	return sum;
}

std::ostream& operator<<(std::ostream& os, const Vector& other)
{
	os << other.mX << ', ' << other.mY;
	return os;
}