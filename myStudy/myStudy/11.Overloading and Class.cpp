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
-> cout::

*/

class Vector
{
public:
	Vector operator+(const Vector& other) const;
private:
	int mX;
	int mY;
};

// 연산자 오버로딩
Vector Vector::operator+(const Vector& other) const
{
	Vector sum;
	sum.mX = mX + other.mX;
	sum.mY = mY + other.mY;

	return sum;
}

void operator<<(std::ostream& os, const Vector& other)
{
	os << other.mX << ', ' << other.mY;
}