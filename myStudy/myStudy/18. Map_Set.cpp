/*

## �� (Map) : Ű�� ���� ã�´�.
- Ű�� ���� ������ ����Ǹ�, Ű�� �ߺ��� �� ����
- �ڵ� ���� ��� ���� -> ���� Ž�� Ʈ�� ���

### pair<key, value> : �� �����͸� �� ������ �����ϴ� ����

### insert() : �� ��Ҹ� ����

### [] : key�� �����ϴ� ���� ������ ��ȯ�ؼ� �� ���� �����ϰ� ��
- �̹� ������ �� ���
- ���ٸ�, �� ��� ����

### STL ���� �׻� ���ĵȴ�. ����, �ݵ�� �� Ű�� ���ϴ� �Լ��� ������ �Ѵ�.
- '<'  : ����� ���� �ڷ����� bool Cat::operator<const Cat& other> const {}

----------------

�� ���� : ����Ʈ�� ���ͺ��� Ž�� �ӵ��� ������ O(N). Ű�� ã�� ������ O(logN) -> ���� Ž�� Ʈ�� / ���� ������ ã�´�

�� ���� : �ڵ� ������ ����(�ؽ� ���� �ƴ϶� �ڵ� ���� ��), �ؽ����� �ƴ϶� O(1)�� �ƴ�.

�ؽ���:O(1) vs ��:O(logN) ����? 
	- �� : ���� Ž�� Ʈ��
	- �ؽ���

------------------

### �� : ����
- ���� ���ĵ�(���� Ž�� Ʈ��, ��������), �ߺ����� �ʴ� Ű�� ��ҷ� ����
- �ʰ� �ٸ� ���� ���� Ű�� ��. ���� ����
- �Ű� ���� �ϳ��� ����.

set<int> scores;
scores.insert(10);

*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> myMap;

	myMap.insert(pair<string, int>("Nabi", 10));
	myMap["Nabi"] = 5;

	map<string, int>::iterator iter = myMap.begin();

	cout << iter->first << " : " << iter->second << endl;

	// find�� ��� ã��
	iter = myMap.find("Nabi");  // �ش� Ű�� ������ ����
	iter->second = 55;

	cout << iter->first << " : " << iter->second << endl;

	return 0;
}