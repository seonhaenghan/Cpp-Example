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