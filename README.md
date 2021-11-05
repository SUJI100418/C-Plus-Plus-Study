# C-Plus-Plus-Study
- Using Namespace
- cin, reverse string
- Reference; int& cat


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
