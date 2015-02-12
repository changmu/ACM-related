/************************************************************* 
 * ��1+2+...+n��Ҫ����ʹ�ó˳�����for��while��if��switch��
 * �ؼ��ּ������ж���䡣
 *************************************************************/ 
// �ⷨһ�����ù��캯�����
#include <iostream>

using namespace std;

class Temp {
	private:
		static int N;
		static int Sum;

	public:
		Temp() { Sum += ++N; }

		static void Reset() { N = Sum = 0; }
		static int GetSum() { return Sum; }
};

int Temp::Sum = 0;
int Temp::N = 0;

int Sum_Solution1(int n)
{
	Temp::Reset();
	delete[] new Temp[n];

	return Temp::GetSum();
}

// �ⷨ���������麯�����
class A;
A *Array[2];

class A {
	public:
		virtual int Sum(int n) {
			return 0;
		}
};

class B: public A {
	public:
		virtual int Sum(int n) {
			return Array[!!n]->Sum(n - 1) + n;
		}
};

int Sum_Solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	return Array[1]->Sum(n);
}

// �ⷨ�������ú���ָ�����
typedef int (*fun)(int);

int Teminator(int n) { return 0; }

int Sum_Solution3(int n)
{
	static fun f[2] = {Sum_Solution3, Teminator};
	return f[!n](n - 1) + n;
}

// �ⷨ�ģ�����ģ��������⣬n�����Ǳ�������ȷ���ĳ���
template<int n> struct Sum_Solution4 {
	enum Value { N = Sum_Solution4<n - 1>::N + n };
};

template<> struct Sum_Solution4<1> {
	enum Value { N = 1 };
};

int main()
{
	int n;
//	while (cin >> n)
	cout << Sum_Solution4<100>::N << endl;
	return 0;
}
