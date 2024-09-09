#include <iostream>
using namespace std;

// ��������ֵ�ĺ���
//void mySwap(int& a, int& b)
//{
//	cout << "int ���ͺ���" << endl;
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void mySwap(double& a, double& b)
//{
//	cout << "double ���ͺ���" << endl;
//	double temp = a;
//	a = b;
//	b = temp;
//}

// ʹ�ú���ģ�������н���
template <typename T, typename E>
void mySwap(T& a, E& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int num1 = 10, num2 = 20;
	cout << "����֮ǰ��" << "num1=" << num1 << "  num2=" << num2 << endl;
	// ����֮ǰ��num1=10  num2=20
	// ����ֱ�ӽ�����ʾ����ָ��
	mySwap<int>(num1, num2);
	cout << "����֮��" << "num1=" << num1 << "  num2=" << num2 << endl;
	// ����֮��num1=20  num2=10
	cout << endl;
	double num3 = 20.11, num4 = 35.12;
	cout << "����֮ǰ��" << "num3=" << num3 << "  num4=" << num4 << endl;
	// ����֮ǰ��num3=20.11  num4=35.12
	mySwap(num3, num4); //����һ����дҲ����
	cout << "����֮��" << "num3=" << num3 << "  num4=" << num4 << endl;
	// ����֮��num3=35.12  num4=20.11

	cout << endl;

	char ch1 = 'A', ch2 = 'B';
	cout << "����֮ǰ��" << "ch1=" << ch1 << "  ch2=" << ch2 << endl;
	// ����֮ǰ��ch1=A  ch2=B
	mySwap(num1, num2);
	cout << "����֮��" << "ch1=" << ch1 << "  ch2=" << ch2 << endl;
	// ����֮��ch1=A  ch2=B
	// ���϶����Զ������Ƶ�
	// �Զ������Ƶ����뱣֤�βε�������һ�µģ�������ִ��
	mySwap(num1, ch1);
	cout << endl;
	cout << num1 << endl;  //65
	cout << ch1 << endl;
}

// дһ������ģ�壬ʵ������ֵ�Ĵ�С�ıȽϣ����ؽϴ��ֵ��
// ���ԱȽ�double���ͣ�int�����Լ�char���͵ȵ�
template <typename E>
E Compare(E& d, E& e)
{
	return (d > e) ? d : e;
}
void test02()
{
	int num1 = 10, num2 = 20;
	double num3 = 20.11, num4 = 35.12;
	char ch1 = 'A', ch2 = 'B';
	cout << Compare(num1, num2) << endl;  //20
	cout << Compare(num3, num4) << endl;  //35.12
	cout << Compare(ch1, ch2) << endl;  //B
	cout << endl;
}

// дһ������ģ�壬���������е����ֵ�������е�����������ͳһ�ģ�����int���߶���double�������������͡�
template <typename T>
T myArr(T arr[], int size)
{
	T max = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i]; 
		}
	}
	return max;
}
void test03()
{
	int intArr[] = { 3,6,7,8,1,98,4,131,1463 };
	double douArr[] = { 2.34,12.443,51.12 };
	char chArr[] = { 'd','a','y','h' };
	cout << myArr(intArr, sizeof(intArr) / sizeof(intArr[0])) << endl;  // 1463
	cout << myArr(douArr, sizeof(douArr) / sizeof(douArr[0])) << endl;  // 51.12
	cout << myArr(chArr, sizeof(chArr) / sizeof(chArr[0])) << endl;  // y
	cout << endl;
}

// ��ͨ����
int addNum(int a, int b) { return a + b; }

// ����ģ��
template <class T>
T addTpl(T a, T b) { return a + b; }

void test04()
{
	// ��ͨ��������ʱ���Է�����ʽת��
	int a = 10;
	char ch = 'a';
	cout << addNum(a, ch) << endl;  // 107
	// ����β����Ͳ�һ�£�Ҳ��Ҫʵ����ʽ����ת���Ļ���
	// ����Ҫ������ʾ����ָ��������ᱨ��
	cout << addTpl<int>(a, ch) << endl; // 107
}

// ��ͨ�����뺯��ģ��ĵ��ù���
// ������ͨ����Ҳ�к���ģ��
void myPrint(int a, int b)
{
	cout << "��ͨ����";
	cout << "a = " << a << "  b = " << b << endl; // ��ͨ����a = 10  b = 20
}
template <typename T>
void myPrint(T a, T b)
{
	cout << "ģ�庯����������"; 
	cout << "a = " << a << "  b = " << b << endl;  // ģ�庯����������a = A  b = B
}
// �βε����Ͳ�ͬ
template <typename T,class E>
void myPrint(T a, E b)
{
	cout << "ģ�庯����������";  
	cout << "a = " << a << "  b = " << b << endl; // ģ�庯����������a = 10  b = 20
}
// �βεĸ�����ͬ
// �����βεĺ���ģ��
template <typename T>
void myPrint(T a, T b,T c)
{
	cout << "ģ�庯����������";
	cout << "a = " << a << "  b = " << b << endl; //ģ�庯����������a = 10.11  b = 20.22
}
void test05()
{
	cout << endl;
	myPrint(10, 20);  // �����ͨ�����ͺ���ģ�嶼��ƥ�䣬����ʹ����ͨ����
	myPrint('A', 'B'); // �������ģ���ܲ������õ�ƥ�����������ʹ�ú���ģ��
	myPrint<>(10, 20); // ����ʹ�ÿյĺ���ģ���β����ͱ���ǿ�Ƶ���ģ�庯��

	myPrint(10.11, 20.22);
	myPrint(10.11, 20.22,30.33);
}


int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	return 0;
}