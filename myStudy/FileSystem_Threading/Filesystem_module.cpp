/*
## ���� �ý��� : C++17�� ���ο� ���̺귯��
- ���͸����� ���� �а�, �����ϰ� �ݰ�
- OS �� ���� �̸� �����ϱ� ��
- �ü�� ������� ���������� ����

## ��� �ý��� : ������ �ð��� ���̱� ���� ����
- ���, cpp �и� ���ص���
- ������� �ٲ𶧸��� ������ �ƴ϶�, �ٲ�Ÿ� ������ �ٽ� �������Ѵ�.

Math.ixx
module Math;
export int Add();

import Math;

*/

#pragma once
#include <iostream>
#include <filesystem>
#include <string.h>
#include <fstream>  // ���� �����

using namespace std;
namespace fs = std::experimental::filesystem::v1;

static const char* FOLDER_NAME = "FileSystem_Threading";
static const char* FILE_NAME = "test.txt";

int main()
{
	// ��� ��ġ��
		// case 1
	fs::path path1 = "D:\\Suji";
	fs::path path2 = "myStudy";
	path1 /= path2;

	cout << path1 << endl;  // D:\\Suji\myStudy

		// case 2
	fs::path path3 = "D:\\Suji";
	fs::path path4 = "myStudy";
	path3 += path4;

	cout << path3 << endl; // D:\\SujimyStudy

	// ���� �Ǵ� ���͸� ����
		//fs::copy(originalTextPath, copiedTextPath);

	// ���� �Ǵ� ���͸� �ٲٱ� or �̵�
		//fs::rename(filePath, renamedPath);

	// ���� ���丮
		//fs::current_path();

	// ���� �Ӽ�(����) �б�
		//--wr--r--

	fs::path p = "../FileSystem_Threading";
	cout << fs::canonical(p) << endl;  // ����� -> ������

	//for (const fs::directory_entry& entry : fs::directory_iterator(p))
	//{
	//	std::cout << entry.path() << std::endl;
	//}

	//cout << typeid(p.string().c_str()).name() << endl;

	// �б� ���� ���� -> ��ǲ ���� ��Ʈ��
	ifstream fin;

	fs::path path_test = fs::canonical(p) /= "test.txt";
	fs::path path_phone = fs::canonical(p) /= "phone.txt";

	string test_path = path_test.string().c_str();
	string phone_path = path_phone.string().c_str();

		// case 1. ���� ����
	/*fin.open(test_path);
	if (fin.is_open())
	{
		cout << "���� ����" << endl;
	}
	else
	{
		cout << test_path << "���� ���� ����.." << endl;
	}*/

		// case 2. �� �ܾ �б�
	/*char character;
	while (true)
	{
		fin.get(character);
		if (fin.fail())
		{
			break;
		}
		cout << character;
	}*/

		// case 3. �� �پ� �б�
	/*string line;
	while (!fin.eof())
	{
		getline(fin, line);
		cout << line << endl;
	}*/

		// case 4. ���ڿ� �ϳ��� ���� �ϳ�
	fin.open(phone_path);

	string name;
	int number;
	while (!fin.eof())
	{
		fin >> name >> number;  // �����̽� ������ �д´�
		cout << name << " : " << number << endl;
	}

	fin.close();

	// ���� ���� ���� (������ ����) -> �ƿ�ǲ ���� ��Ʈ��
	ofstream fout;
	fout.open(phone_path);

	string line;
	getline(cin, line);

	if (!cin.fail())
	{
		//fout << line << endl;
	}


	// �б�, ���� ���� ���� ���� -> ���� ��Ʈ��
	fstream fs;



	
	return 0;
}