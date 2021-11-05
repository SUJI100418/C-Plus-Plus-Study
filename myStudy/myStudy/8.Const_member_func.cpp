/*
*const ��?
�ٲ� �� ���� : ��� vs ����
-> ���α׷����� �Ǽ��� ������
-> ���� ��, const ��ġ�� �ȵǴ� �ǰ�? �⺻ const�� ¥�� �ƴѰŸ� ����.

*/


class Vector
{
public:
	void SetX(int x);
	void SetY(int Y);

	int GetX() const;  // const �Լ�, �ش� ��ü ���� � �͵� �ȹٲ�
	int GetY() const;

	void Add(const Vector& other);

private:
	int mX;
	int mY;
};

int Vector::GetX() const
{
	//mX = mX + 1; //����
	return mX;
}

void Vector::Add(const Vector& other)
{
	mX += other.mX;
	mY += other.mY;
}