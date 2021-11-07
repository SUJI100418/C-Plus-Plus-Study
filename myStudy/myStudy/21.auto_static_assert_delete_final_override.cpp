/*
-----------------------------------

## auto -> 자료형을 추론
-> 반드시 auto 변수를 초기화해야 함, 레퍼런스처럼 초기화 필수!

auto x = "Jang";
x = 50; // 에러

가독성 때문에, 포인터형을 받을 때 auto*를 쓰자.
const도 컴파일러가 알아서 걔 const인지 알지만, 역시 가독성 때문에 const를 붙이자.

auto& : 참조로 받을 때, 꼭 & 붙이자. 컴파일러는 참조인지 복사인지 구분 못함

-> 결국, 타이핑을 좀 줄여주지만... 가독성을 떨어뜨린다...

-> 대신 반복자는 auto 키워드가 매우 유용하다!! 반복자가 뭘하는지 너무 명확하다. 정형화된것
for (auto it = v.begin(); it != v.end(); ++ it) {}


-----------------------------------

## static_assert

-> assert : 실행 중에 어서션이 맞는지 평가. 조건이 맞는 지 평가. 오직 디버그 빌드에만 작동.. 왜 컴파일러가 몰라?
assert(name!=NULL); // 멈춤

-> static 정적 어썰트 : 실행 중 말고, 미리 체크하자. 컴파일 중에 어서션 평가하는 것. C++11 나온 기능
-> 실패하면 컴파일 에러 뱉음

1. 구조체 크기 체크 : static_assert(sizof(Student) == 74, "size mismatch");
2. 버전 체크
3. 배열 길이 체크


-----------------------------------

## default/delete

-> new delete 걔 아님

-> 암시적 생성자 = 컴파일러가 만들어주는 기본 생성자랑 얕은 복사 생성자가 문제가 됨

Dog() = default; // 컴파일러가 만들어주겠구나! 가독성 문제. 컴파일러는 바뀐게 없음

Dog(const Dog& other) = delete;  // 컴파일러야, 만들어 줄거 아는데, 지워. 컴파일러가 자동으로 생성자를 만들어주지 않기를 원한다면.

기존엔 private: Dog(const Dog& other); 에 숨겼음


-----------------------------------

## final/override

-> 마지막 재정의, 상속 안 해줄거야! 상속 막을 방법. 호적 파버리는거; 컴파일 도중 확인

class Animal final {} 
class Dog : public Animal {} // 에러

대신,

class Dog final : public Animal {} // 개의 대가 끊긴다...

Q. 잘못된 가상 함수 오버라이딩 막으려면? override 사용

Animall::virtual void SetW(float w);
Dog::virtual void SetW(int w); <- 오버라이드 할랬는데, 실수해서 새로운 함수 만들어버림; 컴파일러가 체크 못함

virtual void SetW(float w) override; 이렇게 쓴다.


-----------------------------------

## offsetof : 상대적 위치

offset(Student, ID)  // 바이트 단위


*/