/*
* ���ڿ� �� ������ : Relationg

apple == firstName : ������ 0 ��ȯ, �ƽ�Ű �ڵ�� ���� AB<AC = ���� ���� ���� ��

string�� class �̴�. -> ���� �Լ��� ����;

1. size() 
2. length()
3. c_str() : const char* = �ش� string�� ������ �ִ� ���� �迭�� ���� �ּҸ� ����Ű�� ������ ��ȯ
	�� �ʿ��Ѱ�? c ��Ÿ���� ���ڿ��� ��� ���� c �Լ� �� �� ����; c���� string�� ����
	�ü�� �Լ��� c����̶� char*�� ��û�Ѵ�. 


4. c ��� �ᵵ �˴ϱ�? c++ ���ÿ����� ������ ���� ���� ������ ���� c�Լ� �����
	<string.h> -> <cstring> 

5. �� string�� �� ������? ���� �迭 ���̿� ���� ����� �ʿ� ����
	-> ��� �۵�? line���� pointer(�� �޸� �Ҵ�:����)�� �̿��� �޸� ����� �Ҵ�
	-> �ᱹ �޸� ����ȭ ������ �߻�; �� �޸� �Ҵ絵 ����

*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// std::string(Ŭ����)
	string firstName = "Jang";
	string fullName = "Suji Jang";

	// ����
	fullName = firstName;
	
	// �����̱�
	fullName += "Gaule";
	cout << fullName <<' ' << fullName.size()<< endl;

	// const char* ���� �ּ� ��ȯ : �޸𸮶� ���� �˾Ƽ� �������ִ� ��!
	// char* �����Ͱ� ����Ű�� ��ġ�� �޸� ���� �� �Ҵ� ������ �ٲ� �� �ִµ�,
	// const �����Ͱ� ����Ű�� �ִ� ���ڿ� ����(ĳ���� ���)�� �ٲ� �� ����.

	string line;
	cin >> line;

	// const �д� ��� : �����ʿ��� �������� �о��! const char* = ������ �� ;�� �ܽ�Ʈ (ĳ���͸� �ٲ� �� ����) 
	// �ּҸ� �� �ٲٰ� �ϰ� �ʹٸ� : �ܽ�Ʈ ����Ʈ �� �� = char *const
	const char* cLine = line.c_str();  // Ŭ�������� c��Ÿ���� char�� ���´�!
	cout << cLine << endl;

	// Q. ���ڿ� ����� �����̱� : abc -> abccba
	
	int last_char = (int)line.size() - 1;

	// �� �� ĳ���Ϳ��� ������ ��ȸ
	for (int i = (int)line.size() - 1; i >= 0; --i)
	{
		line += line[i];
	}

	cout << "�ڿ� �����̱�" << line << endl;

	return 0;
}
