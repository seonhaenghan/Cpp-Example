# �̸����� (namespace)

## namespace�� Ư�� ������ �̸��� �ٿ��ֱ� ���� ������ ����̴�.

## 1. namespace�� �ʿ��� ����
- ���α׷��� ����ȭ�Ǿ� ���� �̸��� �浹������ ����
- ���� ��� �� ȸ�簡 ������ �Ѵٰ� ���� ���� �� ������ ���� �ϸ� �ߺ��Ǵ� �̸��� �߻����� ���� �� ����.
- ������Ʈ�� �����ϱ� ���� �Լ� �� ������ �̸��� ��� ���ؼ� �̸� �浹�� �߻����� �ʰ� �ϴ� ���� �ذ�å�� �� �� ���� ������
- namespace��� ������ �����ؼ� �̷��� ������ ���� �ٺ����� �ذ�å�� ������

## 2. namespace�� �⺻����
- �Ʒ� �ڵ�� �̸��浹�� �������� ������ �ڵ�� �Ű� ���� ���̴�.

 #include <iostream>
 void SimpleFunc(void)
 {
	 std::cout << "BestCom�� ������ �Լ�"<<std::endl;
 }

  void SimpleFunc(void)
 {
	 std::cout << "ProgCom�� ������ �Լ�"<<std::endl;
 }

 int main(void)
 {
	 SimpleFunc();
	 return 0;
 }

- ���� ������ �̸��� �Ű����� ���� �����ϱ� ������ ������ ���� �� �� ����
- �׷��� BestCom�� ���� �Լ��� �ڽŸ����� namespace�� ����� �� �ȿ� �Լ��� �����ϰų� ������ �����Ѵٸ�?

 namespace BestComTmpl		// 'BestComTempl'�� namespace�� �̸�
 {
	 // namespace ����
 }

- ���������� ProgCom�� ������ ���� �ڽŸ��� namespace�� ����� �� �ȿ� �Լ��� �����ϰų� ������ �����Ѵٸ�?

 namespace ProgComTmpl		// 'ProgComTmpl'�� namespace�� �̸� 
 {	
	 // namespace ����
 }

- �̸��浹�� �߻����� ����.

- NameSp1.cpp���� ���� ::�� ������ (�������� ������ [score resolution operator])��� �ϸ�
- �� �̸��� �ǹ� �ϵ��� namespace�� ������ �� ����ϴ� �������̴�.

## 3. namespace ����� �Լ� ����� ������ ���� 
- �Լ��� ������ ������Ͽ� �����ϰ�, �Լ��� ���Ǵ� �ҽ����Ͽ� �����ϴ� ���� �����̴�.
- ������ namespace��ݿ��� �Լ��� ����� ���Ǹ� �����ϴ� ����� NameSp2.cpp ������ ���� Ȯ���� �� �ִ�.
- ������ namespace�� ���ǵ� �Լ��� ȣ�� �� namespace�� ������ �ʿ䰡 ����
- �ش� ������ NameSp3.cpp���� Ȯ���� �� ���� 

## 4. namespace�� ��ø 
- namespace ������ Ư���� ��ø�� namespace�� �ٸ� namespace �ȿ� ���Ե� �� �ִ�.

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

- �� 3���� num�� �����ϴµ�, ���� ����� namespace�� �ٸ��� ������ �浹 ������ �߻����� �ʾҴ�.
- �� ���� num�� �����ϴ� ����� �Ʒ��� ����.

Ex)
 std::cout << Parent::num << std::endl;
 std::cout << Parent::SubOne::num << std::endl;
 std::cout << Parent::SubTwo::num << std::endl;

- ������� 2, 3, 4�� ��µȴ�. 

## 5. std::cout, std::cin, std::endl
- ���ݱ��� �ܼ� ������� ������ �� std::cout, std::cin�� ����� �Դ�.
- �ش� ������ namespace std�� ����� cout Ȥ�� cin, endl�� ������ �� �ִ�.
- ������ ������� <iostream>�� ����Ǿ� �ִ� cout, cin �׸��� endl�� namespace std�ȿ� ����Ǿ� 
- �ִٴ� ����� ���� �� ���� 

## 6. Using�� �̿��� namespace�� ���� 

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
	 using Hybrid::HybridFunc;		// Ű���� using�� �̿��� Hybrid�� ���ǵ� HybridFunc�� ȣ���� ������ namespace�� �������� �ʰ� 
									// ȣ���ϰڴٴ� ���� �����ϰ� ����
	 HybridFunc();					// ����� using ������ ���� namespace�� ���� ���� HybridFunc�Լ��� ȣ���ϰ� ����	
	 return 0; 
 }

- ���� �������� ����  ���� ������ HybridFunc�� namespace Hybrid���� ã����� ������ ������
  >> using Hybrid::HybridFunc; 
- �� �� HybridFunc�� �Լ� �̸��� �� ���� �ְ�, ���� �̸��� �� �� �ִ�.
- using�� main�Լ� �ۿ� �����Ͽ� �������� ����� �� �ִ�.

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

- �� �ڵ�ó�� ������ using�� �����ϴ� ���� �ƴ϶� ��ü namespace�� using���� ������ �� �ִ�.
  >> using namespace std;
- �̴� �̸����� std�� ����� ��� �Ϳ� ������ ������ namespace�� ������ �����ϰڴٴ� ������
- using namespace������ ���Ǽ��� �������� �ݸ�, �� ��ŭ �̸��浹�� �߻��� Ȯ���� ��������.

## 7. namespace�� ��Ī
- namespace�� ��ø�Ǹ鼭���� �����ϰ� ���Ǵ� ���� ���� �幰��.
- ������ ���� ������� �� 
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

- �Ʒ��� ���� ������� ���� num1, num2�� �����ϴ� ����� �ſ� �����ϴ�. 
	Ex)
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;
- �׷��� �̷��� ��� AAA::BBB::CCC�� ���� �̸��� ��Ī�� �� �� �ִ�.
	Ex) namespace ABC = AAA::BBB::CCC;
- �̴� AAA::BBB::CCC�� ABC��� ��Ī�� �ֱ� ���� ���屸���̴�. �̷��� ��Ī�� �־����� ����, ������ ���� num1, num2�� ������ ����
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

## 8. �������� ������ (Scope Resolution Operator)
 - ���������� �̸��� ���������� �̸��� ���� ��� ���������� ���������� ���� �������ٴ� Ư¡�� �ִ�. 
	Ex)
	int val = 100;		// Global variable

	int SimpleFunc(void)
	{
		int val  = 20;	// Local variable
		val += 3;		// Local var >> val�� �� 3 ���� 
	}

- �� �ڵ忡�� ���̵��� SimpleFunc ���� ���������� ������ �̸��� ���������� ����Ǿ��� ������
- �̾ �����ϴ� ���忡���� �������� val�� ���� 3������Ų��. 
- �׷��ٸ� SimpleFunc �Լ� ������ �������� val�� �����Ϸ��� �������� �����ڸ� ����ϸ� �ȴ�.
	Ex)
	int val = 100;		// Global

	int SimpleFunc(void)
	{
		int val = 20;	// Local
		val += 3;		// �������� val�� �� 3 ����
		::val += 7;		// �������� val�� �� 7 ���� 
	}
