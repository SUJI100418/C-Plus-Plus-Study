/*
## ����̶�?

- �ٸ� Ŭ������ Ư���� �������� ������ (�θ�,�ڽ�) Ŭ������ �ִ�.
- �θ� Ŭ���� : base Ŭ����
- �ڽ� Ŭ���� : derived Ŭ����, �Ļ� Ŭ����
	 - �θ��� ��� ���� 
	 - �θ��� ��� �Լ�
	 - �ڽ��� ������, �Ҹ���

>cat is a animal.

### ������ ȣ�� ����

- �θ� Ŭ������ ���� ȣ��ǰ� ���� �ڸ� �Ҵ� �� -> �ڽ� Ŭ������ �Ҵ��
- �θ� Ŭ������ Ư�� �����ڸ� ȣ���Ҷ��� �� �ʱ�ȭ ����Ʈ�� ����ؾ� ��. ������ ����

### �ڽ� ��ü �����

- �ڽ� ���� �����
- ���� ~Animal() �θ� �Ҹ��� ȣ��
- �θ� �ڽ� ����� -> �ڽ� �θ� �����

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

Cat::Cat(int age, const char* name):Animal(age)  // �θ��� �����ڸ� ȣ���ؼ� age �Ѱ��ְ� �˾Ƽ� ���ּ�~ �ϰ� ����������. 
{
	size_t size = strlen(name) + 1;  // ���ڿ�+1 ������? ������ �ι��� ������
	mName = new char[size];
	strcpy(mName, name);  // ���ڿ� ����
}

int main()
{
	Cat* myCat = new Cat(3, "nabi");
	myCat->Move();

	return 0;
}