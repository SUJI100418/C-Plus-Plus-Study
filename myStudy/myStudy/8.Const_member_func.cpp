/*
*const 란?
바꿀 수 없음 : 상수 vs 변수
-> 프로그래머의 실수를 막아줌
-> 협업 시, const 고치면 안되는 건가? 기본 const로 짜고 아닌거를 빼자.

*/


class Vector
{
public:
	void SetX(int x);
	void SetY(int Y);

	int GetX() const;  // const 함수, 해당 개체 안의 어떤 것도 안바꿈
	int GetY() const;

	void Add(const Vector& other);

private:
	int mX;
	int mY;
};

int Vector::GetX() const
{
	//mX = mX + 1; //에러
	return mX;
}

void Vector::Add(const Vector& other)
{
	mX += other.mX;
	mY += other.mY;
}