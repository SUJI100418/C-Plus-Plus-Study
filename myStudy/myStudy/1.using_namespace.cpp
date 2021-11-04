/*
* namespace : �̸� �浹�� ���ϱ� ���� ������ �̸��� ���� ��, �ҹ��ڷ� ���°��� ��Ģ

1. std(���Ĵٵ� ���̺귯��, ���ӽ����̽�)::cout(Ŭ����, �ܼ� �ƿ�)
2. using ���ù� : std ���� ����, Ÿ���� ���̱� ���� ��

3. << ������ : push ������, ���α׷��Ӱ� ��� ���� ����
4. ������� ���� (Output Formatting) = ������ ��� : showbase �� ex) 16 ���� ���, ���� ��

�ּ� ���� : Ctrl + K + C
�ּ� ���� : Ctrl + K + U

�Ӽ� : ���� ����

*/

#pragma once // �ش��� �ѹ��� #include �� ; �浹 ����

#include <iostream>
#include <iomanip> // �Ŵ��÷���Ʈ : setw(), �Լ�ó�� �Ű������� �޴´�

using namespace std; 

namespace hello
{
	void SayHello() {};
}

namespace hi
{
	void SayHello() {};
}

int main()
{
	// namespace �ǽ�
	hello::SayHello();
	hi::SayHello();

	// using namespace std; �ǽ�
	cout << "Hello, World" << endl;

	// �������� ������ ���� �� ���
	int integer = 1;
	float decimal = 1.5f;
	char letter = 'A';
	char string[] = "Hello, world!";

	cout << string << endl;

	// showbase(�� �����ΰ�?) << hex : 16���� ���, oct �� 8����
	cout << showbase << hex << 123 << endl;

	// showpos : positive �� ��, + ���� �����ִ� ��
	cout << showbase << dec << showpos << 50 << endl;

	// setw(6) �÷� �� ���� : ����ڱ��� ������ ���ΰ�
	cout << setw(6) << right << 10;

	return 0;
}