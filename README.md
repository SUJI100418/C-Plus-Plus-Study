쪽지 시험 링크 : https://quizlet.com/_6t5vcy?x=1qqt&i=24ux83

# C-Plus-Plus-Study
- Using Namespace
- cin, reverse string
- Reference; int& cat
- std::string, const char* cLine = line.c_str()
- OOP

---------------------------------------------------------------

#### Q. 입력된 문자열 뒤집기 -> 투 포인터 사용

	const int LINE_SIZE = 512;
	char line[LINE_SIZE];

	cout << "string to reverse" << endl;
	cin >> line;

	char* left = line;  // 문자열의 처음
	char* right = line + strlen(line) - 1; // 문자열의 마지막

	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		++left;
		--right;
	}

	cout << line << endl;


#### Q. 문자열 뒤집어서 덧붙이기 : abc -> abccba
	
	string line;
	cin >> line;
	
	int last_char = (int)line.size() - 1;

	// 맨 뒤 캐릭터에서 앞으로 순회
	for (int i = (int)line.size() - 1; i >= 0; --i)
	{
		line += line[i];
	}

	cout << "뒤에 덧붙이기 결과 : " << line << endl;


#### Q. 문자열에서 알파벳 대소문자로 이루어진 단어 중 제일 긴 단어 추출 : what is the longest word? -> longest



#### Q. 특정한 수에서 하나의 숫자를 제거했을 때, 만들 수 있는 가장 큰 수는? : 98134 -> 9834
