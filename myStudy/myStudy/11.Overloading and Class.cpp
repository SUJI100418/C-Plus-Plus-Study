/*

������ = �Լ�ó�� �۵��ϴ� ��ȣ

1. ���� ������ ex) &, ~
2. ���� ������ ex) &&, *=
3. �Լ�ȣ�� ������ : ()
4. ÷�� ������ : []
5. new 
6. delete

friend Ű���� 
-> Ŭ���� ���� �ȿ� friend Ű���� ����Ͽ� �ٸ� Ŭ������ �Լ��� ���� private�� ���� �����ϵ��� ���
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

// ������ �����ε�
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