# C-Plus-Plus-Study

#### Q. 입력된 문자열 뒤집기 -> 투 포인터 사용

	const int LINE_SIZE = 512;
	char line[LINE_SIZE];

	cout << "string to reverse" << endl;
	cin >> line;

	char* left = line;  // 첫캐릭터
	char* right = line + strlen(line) - 1; // 마지막캐릭터

	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		++left;
		--right;
	}

	cout << line << endl;
