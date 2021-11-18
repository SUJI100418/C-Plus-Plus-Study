## C# 코드 모음

### 1. 프로그래밍 언어의 역사

- 최초의 컴퓨터 애니악 = 전기 배선 작업으로 프로그래밍

- 존 폰 노이만이 에드박 창시 -> 이후, 0과1의 bit로 표현되는 기계어를 조합하여 프로그래밍 = 펀치 카드

- 기계어 -> 어셈블리어 탄생 = MOV : 010001 ... , 그러나 별도의 번역 과정 필요

- __컴파일러__ : 소스 코드를 컴파일(어셈블리어->기계어)하여 실행 파일(프로그램)을 만듦

- 포트란 : 스피드 코딩팀에서 만든 언어 ex) a = 5 + 1, 대 해적 시대처럼 컴퓨터 언어의 창조 시대가 열림

- C (B다음C, 유닉스 언어) -> C++ (OOP, C다음D가 아님, +1만큼 향상) : 벨 연구소 출신

- C# (++ 다음 ++, D아님) : 마이크로소프트 출신, 이름은 비슷하지만 완전히 다른 언어!

- .Net : 인터넷 서비스는 모든 기기에서 사용할 수 있어야 한다! 유니티가 여러 버전의 빌드를 제공하는 것처럼!

  --------

### 2. Hello, World!

- using + 네임 스페이스 : 해당 네임 스페이스 안의 클래스를 사용하겠다!

- using + static + 네임 스페이스 : 정적 멤버를 데이터 형식의 이름을 명시하지 않고 참조하겠다.

  > using static System.Console;      WhriteLine();

- Static void main() : 프로그램의 진입점 (Entry Point)

  > CLR 은 main() 앞에 static(전역, 1번 메모리 할당)이 없으면 진입점 못찾음 , 다른 함수는 코드 블록 실행될 때 메모리 할당
  >
  > CLR (1) 전역 메모리 할당, (2) 진입점 찾음. 근데, 메인이 static이 아니면 메모리에 안올라감

- CLR : 커먼 랭귀지 런타임, 자바 가상 머신과 비슷, 2번 씩 컴파일

  > 장점 : 플랫폼 최적화된 코드 생성, 단점 : 컴파일 비용 부담

----

### 3. 데이터 타입

- 데이터 종류 = 변수 : 데이터를 담는 일정 크기의 공간 (메모리)

  1. 기본 데이터 타입 : 9개 정수형, int e = 3_0000_0000; **_자릿수 구분자** 편리~
  2. 복합 데이터 타입 : 구조체, 클래스, 배열, 참조 형식 = new 연산자 + 생성자 필요
  3. 상수 const : 값을 바꾸지 말아야 할 변수
  4. 열거형 enum : 여러개의 상수를 모아놓은 것

- 초기화 (Init) : 최초의 데이터 할당, 안하면 쓰레기값 들어감

- __참조 형식__(힙, 스택 둘다 필요) : 힙에 데이터 저장, 스택에 힙 메모리 주소 저장

  - 스택은 { 에서 데이터를 생성하고 }를 만나면 없앤다. 청소부 있음, 근데 } 만나도 계속 쓰고 싶은 변수가 있다면? 힙에 할당해야 함
  - 힙은 청소부가 없어서, CLR 이 가비지 컬렉터를 대신 고용해서 청소한다. 대신 } 만나도 계속 유지 가능

- 서식 지정자 : https://blog.hexabrain.net/128

- __2의 보수법__ : 비트를 채울 때, 앞에 부호를 넣는다면, 11_11_11_11 의 값은? -1이다. 음수는 거꾸로 센다.

  > 00_00_00_00 이 +0 이면, 10_00_00_00 은? -0이 된다. 0은 음수 양수 상관없이 값이 1개인데 +0이랑 -0 두개가 생겨버렸다.
  > 그래서, 2의 보수법을 채택해서 음수를 표현한다.
  >
  > -1 표현법 : 00_00_00_01 을 반전 -> 11_11_11_10 -> 여기서 +1을 더하면? 11_11_11_11

- __오버 플로우__ : a = 최댓값; a +=1 값은? 의외로 0임. 천상의 끝은 최하층...?

  > 1111_1111 에 +1 을 더하면? 1_0000_0000, 근데 8개 비트만 표현 가능하니까 뒤에서 8개 까지만 채택, 나머지 버림

- __부동 소수점__ : 정수+유리수를 포함한 실수 영역을 다룸, float, double, 부동 소수점 표현을 위해 일부 비트를 사용하고 연산 느림

  > float 한정된 정밀도 : 4바이트(32bit) 중, 8비트만 지수부인데, 1개는 부호를 나타내야 하니까 7비트로 큰 수를 표현해야 함...what..?
  >
  > 그래서, 7개의 bit로 수를 대략적으로 표현해야함. 7비트 넘어가는 수 표현이 들어오면 나머지 버림

- Object : C#은 모든 데이터의 조상. int는 Object를 상속받아 만들어짐

  > object a = 123; 부모 클래스로 자식 클래스 생성, object는 모든 데이터를 다 담을 수 있음
  >
  > 이때, 123은 스택? 힙? "답은 __박싱=힙__이다." = object 형식에 값 형식의 데이터를 할당하려는 시도가 이루어지면 해당 데이터를 박싱해서 힙에 할당한다. = 값 형식과 참조 형식의 형변환 일종
  >
  > 그럼 __언박싱__은? 힙의 데이터를 __스택__에 할당하는 것! ex) int b = (int) a;

- __형변환__

  1. 정수끼리: 크기가 서로 다른 정수 = 1리터 우유를 300ml 컵에? 흘러넘쳐~ 오버 플로우 (천상계 끝은 최하층)
  2. 정수끼리 : 부호 있는 vs 부호 없는 정수 = 정밀도 손상! 2진수(저장) -> 10진수(복원, 0.2222 무한 소수 문제) -> 다시 2진수
  3. 부동 소수점 끼리: 크기가 서로 다른 부동 소수점
  4. 부동 소수점 vs 정수
  5. 문자열 vs 숫자 : 메소드 오버라이딩, int a = int.__Parse__("123"), string d = a.__ToString()__;

- Nullable a : int? a = null;

  > a.HasValue ; a.Value 속성 있음

- var : 데이터 형식을 알아서 파악, 약한 형식 검사 지원

  > 오해 마시라, C#은 강력한 형식 검사를 기본으로 한다. 수시로 컴파일 에러 발생
  >
  > 근데, var a = 1; 초기화까지 해주면 알아서 a 형식을 파악해줌, 대신 지역변수만 가능. 클래스 멤버 변수 사용 불가능. 생성자가 var 파악 못함

- 문자열 보간 : C# 6.0 이후 추가

  > int?[] arr = new int?[2];
  >
  > Console.Write($"{arr[0]}{(arr[1].HasValue? ",":"")}{arr[1]}");  -> ($"{a}{b}")

----

### 4. 연산자

- C# 6.0 이후 -> null 조건부 연산자 추가, 엘비스 연산자 = ?

  > a?.Count

----

### 5. 흐름 제어

- for : 초기화식; 조건식; 반복식;

----

### 6. 메소드로 코드 간추리기

- 매개변수 -> 참조에 의한 전달

  > static void Swap(ref int a, ref int b)
  >
  > Swap(ref x, ref y)

- 참조 반환 ref

  > Class a {
  >
  > result = 123;
  >
  > Public ref int Some() {
  >
  > ​	return ref result;}}
  >
  > ref int a = ref a.Some();

- 출력용 매개변수 out , 몫 나머지 등 2개 이상의 값을 return 하고자 할 때 유용, out은 ref에는 없는 안전장치가 있음.
  out 매개 변수에 결과를 저장하지 않으면 컴파일 오류 ~~

- 가변 개수의 인수 : int Sum(__params__ int[] args)

- 선택적 인수, 매개변수 일부 초기화해서 호출 시 생락 하는것

  > 오버로딩 = 매개변수에 따라 논리가 달라지는 경우
  >
  > 선택적 인수 = 논리는 동일한데 매개변수가 다른 경우

-----

### 7. 클래스

- Static 있으면, 클래스 본사 소속(전체 1개)=생성 없이 사용 가능~, 없으면 인스턴스 분사 소속

- vs 인스턴스 메소드 : 인스턴스 생성 후 사용 가능

  ```c#
  using System;
  		
  class Base
  {
  	protected string Name;
  	public Base(string Name)
  	{
  		this.Name = Name;
  		Console.WriteLine($"My name is {this.Name}.Base()");
  	}
  	~Base()
  	{
  		Console.WriteLine($"{this.Name}.Base(), Bye~");
  	}
  	public void BaseMethod()
  	{
  		Console.WriteLine($"{this.Name}.BaseMethod(), Doing!");
  	}
  }
  
  class Derived : Base
  {
  	public Derived(string Name) : base(Name)
  	{
  		Console.WriteLine($"My name is {this.Name}.Derived()");
  	}
  	~Derived()
  	{
  		Console.WriteLine($"{this.Name}.Derived(), Bye~");
  	}
  	public void DerivedMethod()
  	{
  		Console.WriteLine($"{this.Name}.DerivedMethod(), Doing!");
  	}
  }
  
  public class Program
  {
  	public static void Main()
  	{
  		Base a = new Base("Cat");
  		a.BaseMethod();
  		
  		Derived b = new Derived("MiMi");
  		b.DerivedMethod();
  		
  		Base c = new Derived("SiSi");
  		c.BaseMethod();
  	}
  }
  ```

- 기반 클래스와 파생 클래스간에 족보를 오르내리는 형변환이 가능하다.

- __기반 클래스로 파생 클래스를 인스턴스할 수 있다.__ Ex) mammal = new Cat();

- 근데, 왜 필요? = __코드의 생산성을 높히기 위해서! 같은 함수를 쓰는데 클래스가 달라서 메소드 오버로딩을 해야한다. __상속은 그 문제를 없애줌!

  >class Zookeeper. // 동물마다 Wash()함수를 오버로딩해서 사용해야 하는가? 같은 로직임에도 불구하고?
  >
  >{
  >
  >​	public void Wash(Dog dog) {}
  >
  >​	public void Wash(Cat cat) {} ............
  >
  >}

  > class Zookeeper // 그냥 부모 클래스에 함수 1개 선언하고 자식들이 부모 클래스 함수 써서 씻으면 됨!
  >
  > {
  >
  > ​	public void Wash(Animal animal) {} 
  >
  > }

  > Q. I think it's because the derived class needs to create an object of the base class but why?
  >
  > A. An instance of a derived class *is* an instance of the base class. If you have a rule for what must happen when you construct an Animal, and you're constructing a Giraffe, then *somehow* you have to execute the rule for constructing an Animal. In C# that mechanism is "call a base class constructor".
  >
  > A. A derived class is the base class plus extra things the derived class adds.
  >
  > You still need some code that initializes the base class portion so you can add your extra parts on top. The call to the base constructor is where that initialization happens.

- Is 와 as 연산자 : 부모와 자식간 형변환, as 는 참조 형식만 사용 가능

  ```c#
  using System;
  		
  class Animal
  {
  	public void Sleep(){ Console.WriteLine($"Sleep.Animal"); }
  }
  class Dog : Animal
  {
  	public void Bark(){ Console.WriteLine($"Bark.Dog"); }
  }
  class Cat : Animal
  {
  	public void Meow(){ Console.WriteLine($"Meow.Cat"); }
  }
  public class Program
  {
  	public static void Main()
  	{
  		Animal ani1 = new Dog();
  		Animal ani2 = new Cat();
  		
  		Cat cat = ani1 as Cat;
  		if(cat != null)
  			cat.Meow();
  		else
  			Console.WriteLine($"cat is not a Cat!");		// 출력!
  	}
  }
  ```

- __오버라이딩~ 다형성~__ : 하위 형식 다형성, 자신으로부터 상속받아 만들어진 파생 클래스를 통해 다형성을 실현

  1. 토니 스타크 : class 아머수트(장갑), class 아이언맨 : 아머수트, class 워머신 : 아머수트, 근데 워머신이랑 아이언맨의 수트 기능은 달라아햠
  2. 무기 재장착을 위해 아머수트의 Init() 함수를 재정의 해야 함 = 오버라이딩
  3. 그리고 장갑 장착을 위해 Base 아머 수트의 Init()도 호출할 수 있어야 함

- 아머수트의 차후 업그레이드를 고려해서 __virtual__ 로 선언 -> 오버라이딩으로 재정의해서 쓰면 됨

- __new__ 파생 클래스 vs Animal cat = __new__ Cat() , 동명이인

  1. new 파생 클래스는 메소드 숨기기 기능! base 메소드를 감추고 파생 클래스 함수를 호출
  2. new 생성자는 동적 할당

- __클래스 vs 구조체 차이는__ ? 클래스는 참조 형식 (힙 할당) 생성자 필요 얕은 복사 || 구조체는 값 형식 (스택 할당), 깊은 복사, 생성자 사용 불가능

- 튜플은? 클래스인가 구조체 인가? || 구조체이다. 그러므로, 값 형식. 스택 할당@ var tuple = (123, 789);

-----

### 8. 인터페이스와 추상클래스

- 인터페이스는 인스턴스를 만들 수 없다.

- 인터페이스를 상속받는 클래스는 인터페이스의 모든 내용을 구현해야 한다.

- 꼭 구현해주세요. 기획 넘겼는데, 받는 프로그래머 다수가 알아서 자기 맘대로 구현하는거~ 약간 과제 테스트 느낌?

  ```c#
  using System;
  
  interface ILogger  // 인터페이스
  {
  	void WriteLog(string message);
  }
  
  class ConsoleLogger : ILogger  // 인터페이스 상속  
  {
  	public void WriteLog(string message)
  	{
  		Console.WriteLine($"...,{message}"); // 인터페이스 구현
  	}
  }
  class ClimateMoniter
  {
  	private ILogger logger;
  	public ClimateMoniter(ILogger logger)  // 생성자에서 logger 받음
  	{	
  		this.logger = logger;
  	}
  	public void start()
  	{
  		string a = "Aaa";
  		logger.WriteLog(a);
  	}
  }
  public class Program
  {
  	public static void Main()
  	{
  		ClimateMoniter c = new ClimateMoniter(new ConsoleLogger());
  		c.start();
  	}
  }
  ```

- 추상 클래스 : 구현을 갖되 인스턴스는 만들지 못함, 메타몽

  1. 이 클래스를 직접 인스턴스화 하지 말고 파생 클래스로 만들어 사용하세요
  2. 메소드 a 는 메소드 b를 꼭 오버라이딩 해서 사용하세요.

-----

### 9. 프로퍼티

- 뭔가, 데이터 오염시키면 안되고~ get/set 쓰기는 귀찮을때!?

  ```C#
  class MyClass
  {
    private int MyNum;
    public int MyNum  // 프로퍼티
    {
      get  // get 만 구현하면 읽기 전용!
      {
        return myNum;
      }
      /*set
      {
        myNum = value;
      }*/
    }
  }
  ```

- public int 보다, 다양한 조건을 두고 초기화 가능!

------

### 10. 배열과 컬렉션 그리고 인덱서

- System.Array : ForEach<T>() 배열의 모든 요소에 동일한 작업 수행

-----

### 11. 일반화 프로그래밍

- 데이터 형식 일반화 , 매개변수 입력이 다를뿐 안에 내부 로직은 똑같을 때 사용
- T : 템플릿

----

### 12. 예외 처리하기

- 비정상적인 상황 대처하기
- 예외를 처리하지 못하면 프로그램이 죽는다!
- Try, catch, throw, finally

----

### 13. 대리자와 이벤트

- 값이 아닌 코드를 매개변수에 넘기고 싶을 때

- 매개변수가 같은 함수 전달?

  ```c#
  using System;
  
  delegate int MyDelegate(int a, int b);  // 대리자 선언
  
  class Calculator
  {
  	public int Plus(int a, int b) {return a+b;}
  	public static int Minus (int a, int b) {return a-b;}
  }	
  
  public class Program
  {
  	public static void Main()
  	{	
  		Calculator c = new Calculator();
  		MyDelegate Callback;
  		
  		Callback = new MyDelegate(c.Plus);  // 참조 전달
  		Console.WriteLine(Callback(3,4));  // 메소드 호출하듯 대리자 호출 => 참조하는 메소드 실행
  	}
  }
  ```

- 대리자 = 메소드에 대한 참조. 비교 메소드를 참조할 대리자의 매개변수로 받을 수 있도록 작성하면 됨, 외부에서 사용 가능

- 이벤트 : 대리자를 event 한정자로 수식해서 만듬, 외부에서 사용 불가

- 이벤트 발생 -> 이벤트 핸들러 호출

----

### 14. 람다식

- int sum = (int a, int b) => a + b;
- 람다식은 대리자보다 더 간단하다
- 대리자 2.0 -> 람다식 3.0 등장 : 결론, 람다 써라

---

### 15. LINQ

- 데이터 질의 기능
- 숫자 배열에서 짝수만 찾아 추출하고 결과 출력