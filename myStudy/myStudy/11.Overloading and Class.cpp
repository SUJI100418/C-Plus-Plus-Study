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
-> �ٸ� Ŭ������ �� �ݰ� �ж�� ���� ���� �ִ� �Լ� 
-> friend void x() �� Ŭ���� �Լ��� ���� �����Լ� �����

* const& ����?
-> ���ʿ��� ��ü�� �纻 ������ ����
-> �ɹ� ������ �ٲ�°͵� ����

*/

class Vector
{
public:
	friend Vector operator+(const Vector& other);  //���� �Լ���
private:
	int mX;
	int mY;
};

// ������ �����ε�
Vector operator+(const Vector& other)  //���� �Լ���
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