/*

## ť FIFO : Fist In First Out
- ���� ��⿭ : �� ������ ��û, ť�� �� ������Ʈ �ϳ��� �װ�, �ϳ��� ������ ó��
- queue<string> q;
- q.push("aa");
- q.front(); q.back();

## ���� LIFO : Last In First Out
- ���� �޸𸮶� �۵� ����� �Ȱ���.
- stack<string> s;
- s.top(), s.puth(), s.pop() -> pop�� ��� ��ȯx, �׳� ������

## ����Ʈ : ���� ���� ���� C�� ������
- ����� ���� ����Ʈ
- ���� ������ ����/���� ����
- insert(1, value), push_front, push_back

����Ʈ ���� : Ž�� ���ϰ� ��ġ �ȴٸ� ����, ���� �ɸ��� �ð� O(1), ��� ��ġ�� ����/���� ����
����Ʈ ���� : Ž�� ������, �޸𸮰� �ҿ������̰�(CPU �޸� ĳ��, �������̾�� �������� ����� �ݴ�, ���Ϳ� ���� �� ����) ���������� ���� �Ұ����ϴ�.

----------------------

STL �����̳�, ����(�ڵ� �޸� ���� �迭)�� ��(Ű,����)�� ���� �߿�

-> �ᱹ STL ����? 
�޸𸮰� �ڵ����� �����Ǵ� ���ø� ����� ǥ�� �������̽�

Q. ��� �����̳ʿ� �˸´� ǥ�� �������̽��� �׻� ������?
-> vector.push_back()�� ����ó�� ���δ�. �׳� �����̳ʸ��� Ư¡���� �Լ��� ����°� ��������?

Q. �޸� �˾Ƽ� �������ִ°� ���� ������? 
-> ����� ���Ҵ����� �޸� ����ȭ ������ �ִ�. 

-----------------------



*/