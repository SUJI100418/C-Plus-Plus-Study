/*

## ������ ���̺귯��
- ������
- ���ؽ�
- ���� ����

-> ������� �̵� ���������� ����� �ȵȴ�.
-> �ڽ� ������ ������ ���� ���� �����尡 ������ �ȵȴ�. -> main �Լ����� thread.join() ������ �ٿ� �߰�

----------------------------------------------------

-> ������ ���� : thread.join(); 
������ ��ü�� ���� �� ���� ���� �����带 �����. �� �Լ� ȣ�� �� ������ ��ü�� �����ϰ� �Ҹ��ų �� �ִ�.

-> ������ ID ���ϱ� : thread.get_id();
�迭�� �ְ�, 0�� 1�� 2�� ������ ����

-> ������ ����� : thread.detach(); 
�ڽ� ������. main ������ ���� ����
�ٽ� join �Ұ���~

-> std::ref(result);
���ξ������� ������ �����忡�� ������ �����ϱ�

-> this_thread::sleep_for(3) 
���� ������ 3�� ���� �ڶ�, �Ͻ� ����

-> this_thread::yield(); �ϵ�
�ٸ� �����忡�� �纸�ض�.
�纸 ����, ���� ��� ����

-> std::mutex (���� �ڿ� ���� �ذ�)
�� �����尣 ���� �ڿ�, ������
�ٵ�, �� �� ��׸� ����� �߻�

static std::mutex sMutex;  // ����ƽ���� �����Լ�, �� 1���� ������.
sMutex.Lock();
	�����ڿ� ���
sMutex.unLock();

-> sMutex.Lock() �ϰ� unLock() �� ������? C++17 
���ؽ����� �����ϴ� ��ü�� ����
����� ���� (���� �Ѳ����� �ɰ�, �Ѳ����� ǰ)

static sMutex;
scoped_Lock<mutex> lock(sMutex)

-> ���� ���� : std::condition_variable
��ȣ�� ���� �� ���� ���� ������ ������ ���߰� -> �̺��� ��ü ������ �ٽ� ����
std::unique_lock�� �� �����



*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

static mutex sMutex;
static int sNumber = 10;  // �����ڿ�

void Multiply(int rhs)
{
	sMutex.lock();
	cout << "�� �����常 ���� ����" << rhs << endl;
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

	cout << "���" << sNumber << endl;

	return 0;
}