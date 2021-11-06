/*
## 파일 시스템 : C++17의 새로운 라이브러리
- 디렉터리에서 파일 읽고, 수정하고 닫고
- OS 단 파일 이름 변경하기 등
- 운영체제 상관없이 공통적으로 쓴다

## 모듈 시스템 : 컴파일 시간을 줄이기 위해 지원
- 헤더, cpp 분리 안해도댐
- 헤더파일 바뀔때마다 복붙이 아니라, 바뀐거만 있을때 다시 컴파일한다.

Math.ixx
module Math;
export int Add();

import Math;

*/

#pragma once
#include <iostream>
#include <filesystem>
#include <string.h>
#include <fstream>  // 파일 입출력

using namespace std;
namespace fs = std::experimental::filesystem::v1;

static const char* FOLDER_NAME = "FileSystem_Threading";
static const char* FILE_NAME = "test.txt";

int main()
{
	// 경로 합치기
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

	// 파일 또는 디렉터리 복사
		//fs::copy(originalTextPath, copiedTextPath);

	// 파일 또는 디렉터리 바꾸기 or 이동
		//fs::rename(filePath, renamedPath);

	// 현재 디렉토리
		//fs::current_path();

	// 파일 속성(권한) 읽기
		//--wr--r--

	fs::path p = "../FileSystem_Threading";
	cout << fs::canonical(p) << endl;  // 상대경로 -> 절대경로

	//for (const fs::directory_entry& entry : fs::directory_iterator(p))
	//{
	//	std::cout << entry.path() << std::endl;
	//}

	//cout << typeid(p.string().c_str()).name() << endl;

	// 읽기 전용 오픈 -> 인풋 파일 스트림
	ifstream fin;

	fs::path path_test = fs::canonical(p) /= "test.txt";
	fs::path path_phone = fs::canonical(p) /= "phone.txt";

	string test_path = path_test.string().c_str();
	string phone_path = path_phone.string().c_str();

		// case 1. 파일 열기
	/*fin.open(test_path);
	if (fin.is_open())
	{
		cout << "파일 오픈" << endl;
	}
	else
	{
		cout << test_path << "파일 오픈 실패.." << endl;
	}*/

		// case 2. 한 단어씩 읽기
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

		// case 3. 한 줄씩 읽기
	/*string line;
	while (!fin.eof())
	{
		getline(fin, line);
		cout << line << endl;
	}*/

		// case 4. 문자열 하나와 숫자 하나
	fin.open(phone_path);

	string name;
	int number;
	while (!fin.eof())
	{
		fin >> name >> number;  // 스페이스 단위로 읽는다
		cout << name << " : " << number << endl;
	}

	fin.close();

	// 쓰기 전용 오픈 (없으면 만듬) -> 아웃풋 파일 스트림
	ofstream fout;
	fout.open(phone_path);

	string line;
	getline(cin, line);

	if (!cin.fail())
	{
		//fout << line << endl;
	}


	// 읽기, 쓰기 범용 파일 오픈 -> 파일 스트림
	fstream fs;



	
	return 0;
}