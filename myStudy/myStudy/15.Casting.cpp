/*
## 캐스팅, 형변환 : 기본은 스태틱 써라!!!!!!! 제일 안전하다, 잘못하면 컴파일러가 잡아주겠지!

### 암시적 캐스팅 -> 컴파일러가 변환해줌

### 명시적 캐스팅 -> 프로그래머가 형 변환을 직접 하는 것
- const_cast, static_cast, dynamic_cast, reinterpret_cast : C++ 에서 4개 지원
- 기존 int num = (int)a <- 실수를 컴파일러가 캐치하지 못함, 그래서 C++에서 4개 지원

### 1. 정적 캐스팅 Stacit Casting -> 컴파일 중에 결정된다.
- int num = static_cast<int>(float_num); // 함수처럼 보인다.
- 값 : 두 숫자 형 간의 변환
- 개체 포인터 : 베이스 클래스를 파생 클래스로 변환 ex) Animal* myCat = new Cat(); Cat* otherCat = static_cast<Cat*>(myCat);


### 2. 리인터프리트 캐스팅 (재해석 캐스트, 가장 위험한 캐스트): 주소를 담는 포인터
Animal* myPet = new Cat(1, "coco");
unsigned int myPetAddr = reinterpret_cast<unsigned int>(myPet);

연관 없어도 형변환 허용 -> 이진수 표기가 달라지지 않음
Cat* <-> Houst*
Cat* <-> int


### 3. 컨스트 캐스팅, const_cast = 하지말아야 할 캐스팅
컨스트를 빼줘.
근데, 형을 바꿀 순 없음
void MyFun(const& int other) <-로 받았는네 여기서 other 값을 바꿀 수 있음

### 4. 동적 캐스팅
Animal* myPet = new Dog();
Cat* myCat = dynamic_cast<Cat*>(myPet); // 컴파일 되는데, NULL을 반환한다.
다형성은 포인터 참조만 된다.
포인터 또는 참조형 캐스팅할때만 쓴다.
호환되지 않은 자식형을 캐스팅하면 NULL을 반환한다.

대신, 컴파일 중에 RTTI 켜야 NULL을 반환한다. 안키면 static이랑 똑같이 쓴다.

*/


직렬화 (serialize)에는 위험한 리인터프리트 캐스팅 써야함
-> 데이터를 파일로 저장
-> 포인터를 직렬화 하려면 포인터를 int로 재해석 해야 한다.
-> int 주소를 다시 포인터로 바꿔씀