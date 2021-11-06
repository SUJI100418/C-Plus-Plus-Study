/*

## 쓰레드 라이브러리
- 쓰레드
- 뮤텍스
- 조건 변수

-> 쓰레드는 이동 가능하지만 복사는 안된다.
-> 자식 쓰레드 끝나기 전에 메인 쓰레드가 끝나면 안된다. -> main 함수에서 thread.join() 마지막 줄에 추가

----------------------------------------------------

-> 쓰레드 조인 : thread.join(); 
쓰레드 개체가 끝날 때 까지 현재 쓰레드를 멈춘다. 이 함수 호출 후 쓰레드 개체를 안전하게 소멸시킬 수 있다.

-> 쓰레드 ID 구하기 : thread.get_id();
배열에 넣고, 0번 1번 2번 꺼내서 쓰자

-> 쓰레드 떼어내기 : thread.detach(); 
자식 버리기. main 끝나도 돌고 있음
다시 join 불가능~

-> std::ref(result);
메인쓰레드의 변수를 쓰레드에게 참조로 전달하기

-> this_thread::sleep_for(3) 
현재 쓰레드 3초 동안 자라, 일시 정지

-> this_thread::yield(); 일드
다른 쓰레드에게 양보해라.
양보 개념, 실행 대기 상태

-> std::mutex (공유 자원 문제 해결)
두 쓰레드간 공유 자원, 독점권
근데, 두 번 잠그면 데드락 발생

static std::mutex sMutex;  // 스태틱으로 전역함수, 딱 1개만 만들어라.
sMutex.Lock();
	공유자원 사용
sMutex.unLock();

-> sMutex.Lock() 하고 unLock() 안 했으면? C++17 
뮤텍스들을 내포하는 개체를 만듬
데드락 방지 (락을 한꺼번에 걸고, 한꺼번에 품)

static sMutex;
scoped_Lock<mutex> lock(sMutex)

-> 조건 변수 : std::condition_variable
신호를 받을 때 까지 현재 쓰레드 실행을 멈추고 -> 이벤드 개체 받으면 다시 실행
std::unique_lock을 꼭 써야함



*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

static mutex sMutex;
static int sNumber = 10;  // 공유자원

void Multiply(int rhs)
{
	sMutex.lock();
	cout << "한 쓰레드만 곱셈 실행" << rhs << endl;
	sNumber *= rhs;
	sMutex.unlock();
}

void MultiThrading()
{
	thread childThread1();
	Multiply(10);

	thread childThread2();
	Multiply(5);

}

int main()
{
	MultiThrading();

	cout << "결과" << sNumber << endl;

	return 0;
}