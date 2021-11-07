/*

## 맵 (Map) : 키로 값을 찾는다.
- 키와 값의 쌍으로 저장되며, 키는 중복될 수 없음
- 자동 정렬 기능 지원 -> 이진 탐색 트리 기반

### pair<key, value> : 두 데이터를 한 단위로 저장하는 구조

### insert() : 새 요소를 삽입

### [] : key에 대응하는 값을 참조로 반환해서 값 변경 가능하게 함
- 이미 있으면 값 덮어씀
- 없다면, 새 요소 삽입

### STL 맵은 항상 정렬된다. 따라서, 반드시 두 키를 비교하는 함수를 만들어야 한다.
- '<'  : 사용자 정의 자료형은 bool Cat::operator<const Cat& other> const {}

----------------

맵 장점 : 리스트나 벡터보다 탐색 속도가 빠르다 O(N). 키로 찾기 때문에 O(logN) -> 이진 탐색 트리 / 양쪽 나눠서 찾는다

맵 단점 : 자동 정렬이 단점(해쉬 맵이 아니라 자동 정렬 맵), 해쉬맵이 아니라 O(1)이 아님.

해쉬맵:O(1) vs 맵:O(logN) 차이? 
	- 맵 : 이진 탐색 트리
	- 해쉬맵

------------------

### 셋 : 집합
- 역시 정렬됨(이진 탐색 트리, 오름차순), 중복되지 않는 키를 요소로 저장
- 맵과 다른 점은 셋은 키만 들어감. 벨류 버림
- 매개 변수 하나만 들어간다.

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

	// find로 요소 찾기
	iter = myMap.find("Nabi");  // 해당 키의 포인터 리턴
	iter->second = 55;

	cout << iter->first << " : " << iter->second << endl;

	return 0;
}