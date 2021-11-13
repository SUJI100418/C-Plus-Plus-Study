/*
 
## .넷 프레임워크 (.net framwork) = CLR, 플랫폼에 종속되지 않는 코드

    - win32 프로그램 -> 운영체제 -> exe (운영체제 종속)
    - .Net 프로그램 -> CLR (알아서 운영체제에 대응할 수 있도록. 리눅스, 윈도우 따로 만들필요없음) -> 운영체제
    - CLI : Common Language Infrastructure (공용 사용)

## C# 컴파일 과정
    
    - C# 코딩 -> 컴파일 -> .NET Framework -> 실행 
    -  (비주얼 스튜디오) /

## C# 언어
    
    - C++에서 파생된 객체 지향 언어, java 특징 + C/C++
    - 가비지 콜렉터로 메모리 관리가 쉽다.

## object
    
    - 객체 데이터 형태, 클래스 상속 적용

## nullable 형식

    - int? num = 100; -> 기존 데이터형 값 + null 추가
    - num.HasValue , num.Value 함수 사용 가능
    - if(isFlag.HasValue) {} // 프로그램 안전성 높일 수 있음

## var : 암시적 형식 지역 변수

    - 선언과 동시에 초기화
    - 지역 변수, for each 에서 자주 사용

## 형변환 : 캐스트

    - ToString()  : 숫자 -> 문자열  ex) a.ToString()
    - Parse()  : 문자열 -> 숫자
    - Convert. : 문자열 -> 숫자

## 값 vs 참조 : 함수에서 중요

    - 참조는 변환이 된다!
    - 함수 return 값이 크면 프로그램이 느려진다, 주소값만 넘겨주면 문제 해결!

## 박싱 vs 언박싱 : 힙 메모리 영역에 데이터 할당

## 삼항 연상자 : 조건식 ? 처리1 : 처리2

## 무한 반복 : for (;;){} or while (ture){}

## OUT : ref 키워드 처럼 레퍼런스(주소값), 전달하는 변수 초기화 없이 사용 가능하다.

    - static void InitNum(out int addNum)


 */

using System;  // 선언된 네임스페이스 내부 개체 접근

namespace CS_Study
{
    public class Point
    {
        public int x, y;
        public Point()
        {
            x = 5;
            y = 10;
        }

        private void PrintXY()
        {
            Console.WriteLine("point x: {0}, y: {1}", x, y);
        }
    }


    class Program  // 프로그램 구성의 기본, 필드와 메서드 분리
    {
        const int NUM = 100;
        static int run = 5;


        static int InitTitle(ref int _x)  // 함수
        {
            _x += 4;
            Console.WriteLine("<<InitTitle 함수>>: {0}", _x);
            return _x;
        }

        static bool CheckResult()
        {
            bool result = true;
            return result;
        }

        static void Func(int[] arr)  // 배열은 레퍼런스다. 바뀐다.
        {

        }


        public static void Main()
        {
            // --------------------------------------------------------------------------

            // 함수 and 레퍼런스 변수

            int x = 1;
            InitTitle(ref x);

            Console.WriteLine("ref 결과 : {0}", x);

            Console.WriteLine("Hello World!");  // + 줄바꿈
            Console.Write("{0}{1}{2}", 1, 2, 3);  // 줄바꿈 없음
            Console.Write("{0}{1}{2}", 4, 5, 6);
            Console.WriteLine("Hello World!2");

            // --------------------------------------------------------------------------

            var a = 5;
            Console.WriteLine(a * NUM);

            int[] arrNum = { 100, 200 };
            int[] refNUM = arrNum;
            refNUM[0] = 5;
            Console.WriteLine("{0}, {1}", arrNum[0], Object.ReferenceEquals(arrNum, refNUM));

            // 박싱 vs 언박싱  : 최소화 하는게 좋다.
            int ii = 123;
            object o = ii; // 박싱
            int jj = (int)o; // 언박싱
            jj = 456;

            // --------------------------------------------------------------------------

            //    - 배열 : 동일한 데이터형

            int[] arrNum2 = new int[5] { 0,1,2,3,4 };

            foreach(int data in arrNum2)
            {
                Console.WriteLine("foreach + arry : {0}", data);
            }

            //    - 다차원 배열 : 행과 열 구분

            int[,] arrNums = new int[2, 2] { { 0, 0 }, { 1, 1 } };

            const int MAP_X = 10;
            const int MAP_Y = 10;
            char[] title = { ' ', '-', ':', '1', '2', '3' };

            int[,] map = new int[MAP_X, MAP_Y];

            for (int i =0; i <MAP_X; i++)
            {
                for(int j = 0; j <MAP_Y; j++)
                {
                    if (j== MAP_Y - 1)
                    {
                        Console.WriteLine("i={0}, j={1}", i, j);
                    }
                }
            }

            // --------------------------------------------------------------------------

            Point point = new Point();
            Console.WriteLine("point x: {0}, y: {1}", point.x, point.y);
        }
    }
}
