#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string FullName;
	int rollon;
	int marks;
};

int main()  // compiler start to read here.
{
	Student studentA = { "NANA BIN, 1,2" };
	cout << studentA.FullName << studentA.rollon << studentA.marks << endl;

	return 0;
}