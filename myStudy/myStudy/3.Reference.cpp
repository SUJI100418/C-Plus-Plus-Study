/*
* ���� reference = ��Ī, �г��� , �ٵ� �� ��Ī�� �ʿ���? NULLüũ ���ص� ��, �����ʹ� NULL ����Ű�� ��縮�� ���ɼ� ����

1. ������ ����(�ּ� ������ ���� ��)�� ��� �� ��, �����ϰ� ���
	- ���� ���� ȣ�� Call by Value 
	- �ּҿ� ���� ȣ�� Call by Address
	- ������ ���� ȣ�� Call by Reference

2. ��Ī ���� int&(���?) ������ : &number �ּ� �ҷ����� ��ȣ�� ������ �ٸ�����
3. ���� ����� �ٲ� �� ����, �ٲٸ� ��� ���� �ٲ�

Q. ������ �����Ͷ� �ٸ��ɱ�?
����� ��ɾ���� �Ȱ��� �ۿ���
�����Ϸ��� ������ "������"�� �ٲ� �� -> ������ ������ ����� ���� ����

*/

#pragma once
#include <iostream>

using namespace std;

void swap_call_by_value(int arg1, int arg2) //���� ���� ���� : �޸� �󿡼� �纻�� ����
{
	// ���� : ���� �����ؼ� ���� �ٸ� ��򰡿� ����, ������ �ƴ� ������ ���� �ٲ�� �Լ� ������ ����~

	int temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

void swap_call_by_address(int* arg1, int* arg2)  // �ּҿ� ���� ���� : �޸� �󿡼� ������ ��ħ
{
	// �ּҸ� �޾� �����ϰ� ���� ��򰡿� ����, arg1 = num1 ���ּ�, arg2 = num2 ���ּ�
	// �Ҵ� �ȵ� �޸� ���� ���� +1, NULL ����ų �� �� ���� 

	int temp = *arg1;
	*arg1 = *arg2;
	*arg2 = temp;
}

void swap_call_by_reference(int& arg1, int& arg2)  // ����(��Ī)�� ���� ���� : �޸� �󿡼� ������ ��ħ
{
	// �ּҸ� �޾� �����ϰ� ���� ��򰡿� ����, arg1 = num1 ���ּ�, arg2 = num2 ���ּ�
	// ������ ��� �� ����, ������ NULL�� �� �� ����, �ٵ� �����ʹ� �����ؼ� ������
	// ������ ���� �� ���� and �Ҵ�� �޸𸮸� ��� ����
	 
	int temp = arg1;  // ������ ������ ���µ� ������ �ٲ��! 
	arg1 = arg2;
	arg2 = temp;
}

int main()
{
	int num1 = 1;  // ���� ������ �Լ� ȣ���� �Ű����� ���� = ����
	int num2 = 5;

	swap_call_by_value(num1, num2); // ���� �ȹٲ�
	swap_call_by_address(&num1, &num2);  // ���� �ٲ�
	swap_call_by_reference(num1, num2);  // ���� �ٲ�

	int number = 100;
	int& reference = number; // ������ ��, &number �ּ� �ҷ����� ��ȣ�� ������ �ٸ�����

	return 0;
}