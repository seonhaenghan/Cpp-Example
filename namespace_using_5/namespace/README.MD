# 이름공간 (namespace)

## namespace는 특정 영역에 이름을 붙여주기 위한 문법적 요소이다.

## 1. namespace가 필요한 이유
- 프로그램이 대형화되어 가며 이름의 충돌문제가 등장
- 예를 들어 세 회사가 협업을 한다고 가정 했을 때 협업을 진행 하며 중복되는 이름이 발생하지 않을 수 없음.
- 프로젝트를 진행하기 전에 함수 및 변수의 이름을 모두 정해서 이름 충돌이 발생하지 않게 하는 것이 해결책이 될 수 없기 때문에
- namespace라는 문법을 정의해서 이러한 문제에 대한 근본적인 해결책을 제시함

## 2. namespace의 기본원리
- 아래 코드는 이름충돌의 문제점을 간단히 코드로 옮겨 놓은 것이다.

 #include <iostream>
 void SimpleFunc(void)
 {
	 std::cout << "BestCom이 정의한 함수"<<std::endl;
 }

  void SimpleFunc(void)
 {
	 std::cout << "ProgCom이 정의한 함수"<<std::endl;
 }

 int main(void)
 {
	 SimpleFunc();
	 return 0;
 }

- 위의 예제는 이름과 매개변수 형이 동일하기 떄문에 문제가 됨을 알 수 있음
- 그런데 BestCom이 만든 함수를 자신마느이 namespace를 만들고 이 안에 함수를 정의하거나 변수를 선언한다면?

 namespace BestComTmpl		// 'BestComTempl'이 namespace의 이름
 {
	 // namespace 내부
 }

- 마찬가지로 ProgCom이 다음과 같이 자신만의 namespace를 만들어 이 안에 함수를 정의하거나 변수를 선언한다면?

 namespace ProgComTmpl		// 'ProgComTmpl'이 namespace의 이름 
 {	
	 // namespace 내부
 }

- 이름충돌이 발생하지 않음.

- NameSp1.cpp에서 사용된 ::을 가리켜 (범위지정 연산자 [score resolution operator])라고 하며
- 그 이름이 의미 하듯이 namespace를 지정할 때 사용하는 연산자이다.

## 3. namespace 기반의 함수 선언과 정의의 구분 
- 함수의 선언은 헤더파일에 저장하고, 함수의 정의는 소스파일에 저장하는 것이 보통이다.
- 하지만 namespace기반에서 함수의 선언과 정의를 구분하는 방법을 NameSp2.cpp 예제를 통해 확인할 수 있다.
- 동일한 namespace에 정의된 함수를 호출 시 namespace를 명시할 필요가 없음
- 해당 내용은 NameSp3.cpp에서 확인할 수 있음 

## 4. namespace의 중첩 
- namespace 마지막 특성인 중첩은 namespace은 다른 namespace 안에 삽입될 수 있다.

Ex)
 namespace Parent
 {
	 int num = 2;

	 namespace SubOne
	 {
		 int num = 3;
	 }

	 namespace SubTwo
	 {
		 int num = 4;
	 }
 }

- 총 3개의 num이 존재하는데, 각각 선언된 namespace가 다르기 때문에 충돌 문제가 발생하지 않았다.
- 각 변수 num에 접근하는 방법은 아래와 같다.

Ex)
 std::cout << Parent::num << std::endl;
 std::cout << Parent::SubOne::num << std::endl;
 std::cout << Parent::SubTwo::num << std::endl;

- 순서대로 2, 3, 4가 출력된다. 

## 5. std::cout, std::cin, std::endl
- 지금까지 콘솔 입출력을 진행할 때 std::cout, std::cin을 사용해 왔다.
- 해당 구성은 namespace std에 선언된 cout 혹은 cin, endl로 생각할 수 있다.
- 때문에 헤더파일 <iostream>에 선언되어 있는 cout, cin 그리고 endl은 namespace std안에 선언되어 
- 있다는 결론을 내릴 수 있음 

## 6. Using을 이용한 namespace의 명시 

Ex)
 #include <iostream>

 namespace Hybrid(void)
 {
	 void HybridFunc(void)
	 {
		 std::cout<<"So simple function!"<<std::endl;
		 std::cout<<"In namespace Hybrid!"<<std::endl;
	 }
 }

 int main(void)
 {
	 using Hybrid::HybridFunc;		// 키워드 using을 이용해 Hybrid에 정의된 HybridFunc를 호출할 때에는 namespace를 지정하지 않고 
									// 호출하겠다는 것을 선언하고 있음
	 HybridFunc();					// 상단의 using 선언을 통해 namespace의 지정 없이 HybridFunc함수를 호출하고 있음	
	 return 0; 
 }

- 위의 예제에서 보듯  다음 선언은 HybridFunc를 namespace Hybrid에서 찾으라는 일종의 선언임
  >> using Hybrid::HybridFunc; 
- 이 때 HybridFunc는 함수 이름이 될 수도 있고, 변수 이름이 될 수 있다.
- using을 main함수 밖에 선언하여 전역으로 사용할 수 있다.

Ex)
 #include <iostream>
 using std::cin;
 using std::cout;
 using std::endl;

 int main(void)
 {
	 int num = 20;
	 cout<<"Hello World!"<<endl;
	 cout<<"Hello "<< "World"<<endl;
	 cout<<num<<' '<<'A';
	 cout<<' '<<3.14<<endl;

	 return 0;
 }

- 위 코드처럼 일일히 using을 선언하는 것이 아니라 전체 namespace를 using으로 선언할 수 있다.
  >> using namespace std;
- 이는 이름공간 std에 선언된 모든 것에 접근할 때에는 namespace의 지정을 생략하겠다는 선언임
- using namespace선언이 편의성이 높아지는 반면, 그 만큼 이름충돌이 발생할 확률은 높아진다.

## 7. namespace의 별칭
- namespace가 중첩되면서까지 과도하게 사용되는 경우는 극히 드물다.
- 다음과 같이 사용했을 때 
  Ex)
  namespace AAA
  {
	  namespace BBB
	  {
		  namespace
		  {
			  int num1;
			  int num2;
		  }
	  }
  }

- 아래와 같은 방법으로 변수 num1, num2에 접근하는 방법은 매우 불현하다. 
	Ex)
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;
- 그래서 이러한 경우 AAA::BBB::CCC와 같은 이름에 별칭을 줄 수 있다.
	Ex) namespace ABC = AAA::BBB::CCC;
- 이는 AAA::BBB::CCC에 ABC라는 별칭을 주기 위한 문장구성이다. 이렇게 별칭이 주어지고 나면, 다음과 같이 num1, num2에 접근이 가능
	Ex) ABC::num1 = 10;
		ABC::num2 = 20;
 
	Ex)
 #include <iostream>
 using namespace std;

 namespace AAA
 { 
 	namespace BBB 
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

int main(void)
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC; 
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	return 0; 
}

## 8. 범위지정 연산자 (Scope Resolution Operator)
 - 지역변수의 이름이 전역변수의 이름과 같을 경우 전역변수는 지역변수에 의해 가려진다는 특징이 있다. 
	Ex)
	int val = 100;		// Global variable

	int SimpleFunc(void)
	{
		int val  = 20;	// Local variable
		val += 3;		// Local var >> val의 값 3 증가 
	}

- 위 코드에서 보이듯이 SimpleFunc 내에 전역변수와 동일한 이름의 지역변수가 선언되었기 때문에
- 이어서 등장하는 문장에서는 지역변수 val의 값을 3증가시킨다. 
- 그렇다면 SimpleFunc 함수 내에서 전역변수 val에 접근하려면 범위지정 연산자를 사용하면 된다.
	Ex)
	int val = 100;		// Global

	int SimpleFunc(void)
	{
		int val = 20;	// Local
		val += 3;		// 지역변수 val의 값 3 증가
		::val += 7;		// 전역변수 val의 값 7 증가 
	}

