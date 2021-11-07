/*

## STL 컨테이너 목적
- 템플릿 기반
- 메모리 자동 관리 ex) 배열 너무 불편했음

ex) 벡터, 맵, 스택, 큐, 리스트, 덱(디큐)

-------------------------------

## 벡터 = 메모리 자동으로 관리해주는 배열이다.
- 어떤 자료형도 넣을 수 있는 동적 배열 (메모리 자동으로 늘려준다.)
	- 클래스(오브젝트), 포인터
	- 그 안에 저장된 모든 요소들이 연속된 메모리 공간에 위치한다. 

### 반복자 - iter 결국 포인터

### 역방향(리벌스) 반복자 - rbegin() 맨 끝 요소, rend() 시작 요소 하나 전

### 특정 위치에 있는 요소 삽입 : 뒤로 한칸 씩 밀림, 재할당 + 복사 문제 발생
- vector<int>::iterator it = scores.begin();
- it = scores.intert(it, 80);   // 포인터!

### 특정 위치에 있는 요소 삭제 : 재할당x, 근데 재할당은 있다.
- it = scores.erase(it);  // 지워진 자리를 채운걸 다시 it으로 가리킨다.

### 벡터 교환하기
- anotherScores.assign(7,100);  // 요소 대입, 100이 7개 있음
- scores.swap(anotherScores);   // 그냥 주소 포인터만 바꾸면 댐, 생각보다 느리지 않다 

### 벡터 축소하기
- scores.resize(2); 만약 5개였으면, 뒤에 3개 날림 : 크기 바꿈

### 용량 변경하는 함수
- scores.reserve();  잡아놓은 크기 바꿈

-------------------------------

### 개체 벡터
- scores.push_back(Score(30,"C++"));  // 스택에 객체 만든 다음 복사해서 넣는다.

### 매개 변수로 const 를 받으면 -> const_iterator 써야한다! 가리키는 걸 바꿀 일은 없다는 뜻 

### 포인터 벡터
- scores.push_back(new Score(30,"C++"));  // 복사할 양이 적어진다.
- iter 돌아서, delete *iter 해줘야 한다.

-------------------------------

벡터 장점 : 순서 상관 없이 임의적으로 접근 가능, 제일 마지막에 추가 혹은 삭제가 굉장히 빠르다

벡터 단점 : 중간 요소 삽입 삭제가 느리고, 재할당이나 요소 복사에 드는 비용이 크다.

*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> scores;
	scores.reserve(3);  // 벡터의 용량을 늘린다. 새로운 저장 공간을 재할당하고 기존 요소들을 모두 새 공간으로 복사

	scores.push_back(30);  // scores.pop_back();
	scores.push_back(50);

	//할당된 요소 공간 수 capacity = 3, 실제로 들어가 있는 요소 수 size = 2
	cout << scores.capacity() << scores.size() << endl;

	// 복사 생성자를 사용하여 생성
	vector<int> scores2(scores);

	cout << scores2[0] << scores2[1] << endl;

	int i = 1;
	scores[i] = 3; // 반환값이 참조라 원본이 바뀐다.

	// STL 컨테이너 요소들을 순회하는데 사용하는 포인터
	//	begin() 첫번째 요소 반환, end() 마지막 요소 바로 뒤를 가리킴, string 뒤에 null로 생각하시오.
	for (vector<int>::iterator iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << " ";  // 반복자는 사실 포인터
	}




}