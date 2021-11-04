/*
* cin�� ���Ͽ�

1. C��� ���� scanf()�� ������ ����: NULL(\0)�� ���� ������ �� �ʿ��ϴ�. �ٵ� scanf�� ���̸� �� �� ����. -> ���˻縦 ���� �ʴ´�.
2. cin�� ���? ���� �Ȱ��� ������ ����
char[] == char * (cin�� �迭 ���� �𸣴°� �Ȱ���)

-> setw(n-1)���� �����ϸ� ��

* ��Ʈ�� ���� (Stream States)
1. using namespace ios_base;
2. �ֿܼ��� �Է��ϰ� ����ġ�� ���ͱ��� ��, ��� ���Ͽ��� ������ ���� �ȵ�

* �Է� ������ (Discarding Input)
1. cin.clear();  abc ���� -> �ٽ� �ʱ�ȭ
2. cin.ignore(); 456abc���� a����
3. get() : ������ ���ڸ� ������ ������ ��� ���� ������, �� ���� �о��, ������ ����
4. getline() : �������� �Է� ��Ʈ������ ����

*/

#pragma once
#include <iostream>

using namespace std;

int main()
{
	char myName[20];
	//cin >> myName;

	if (!cin.eof()) // end-of-file : ���� �� ������ �����ϰڴ�.
	{

	}

	// Q. �Էµ� ���ڿ� ������ -> �� ������ ���

	const int LINE_SIZE = 512;
	char line[LINE_SIZE];

	cout << "string to reverse" << endl;
	cin >> line;

	char* left = line;  // ùĳ����
	char* right = line + strlen(line) - 1; // ������ĳ����

	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		++left;
		--right;
	}

	cout << line << endl;

	return 0;
}