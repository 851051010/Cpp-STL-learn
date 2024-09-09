#include <iostream>
using namespace std;

// 交换两个值的函数
//void mySwap(int& a, int& b)
//{
//	cout << "int 类型函数" << endl;
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void mySwap(double& a, double& b)
//{
//	cout << "double 类型函数" << endl;
//	double temp = a;
//	a = b;
//	b = temp;
//}

// 使用函数模板来进行交换
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
	cout << "交换之前：" << "num1=" << num1 << "  num2=" << num2 << endl;
	// 交换之前：num1=10  num2=20
	// 可以直接进行显示类型指定
	mySwap<int>(num1, num2);
	cout << "交换之后：" << "num1=" << num1 << "  num2=" << num2 << endl;
	// 交换之后：num1=20  num2=10
	cout << endl;
	double num3 = 20.11, num4 = 35.12;
	cout << "交换之前：" << "num3=" << num3 << "  num4=" << num4 << endl;
	// 交换之前：num3=20.11  num4=35.12
	mySwap(num3, num4); //类型一样不写也可以
	cout << "交换之后：" << "num3=" << num3 << "  num4=" << num4 << endl;
	// 交换之后：num3=35.12  num4=20.11

	cout << endl;

	char ch1 = 'A', ch2 = 'B';
	cout << "交换之前：" << "ch1=" << ch1 << "  ch2=" << ch2 << endl;
	// 交换之前：ch1=A  ch2=B
	mySwap(num1, num2);
	cout << "交换之后：" << "ch1=" << ch1 << "  ch2=" << ch2 << endl;
	// 交换之后：ch1=A  ch2=B
	// 以上都是自动类型推导
	// 自动类型推到必须保证形参的类型是一致的，否则不能执行
	mySwap(num1, ch1);
	cout << endl;
	cout << num1 << endl;  //65
	cout << ch1 << endl;
}

// 写一个函数模板，实现两个值的大小的比较，返回较大的值，
// 可以比较double类型，int类型以及char类型等等
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

// 写一个函数模板，返回数组中的最大值，数组中的数据类型是统一的，都是int或者都是double或者是其他类型。
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

// 普通函数
int addNum(int a, int b) { return a + b; }

// 函数模板
template <class T>
T addTpl(T a, T b) { return a + b; }

void test04()
{
	// 普通函数调用时可以发生隐式转化
	int a = 10;
	char ch = 'a';
	cout << addNum(a, ch) << endl;  // 107
	// 如果形参类型不一致，也需要实现隐式类型转化的话，
	// 就需要进行显示类型指定，否则会报错。
	cout << addTpl<int>(a, ch) << endl; // 107
}

// 普通函数与函数模板的调用规则
// 既有普通函数也有函数模板
void myPrint(int a, int b)
{
	cout << "普通函数";
	cout << "a = " << a << "  b = " << b << endl; // 普通函数a = 10  b = 20
}
template <typename T>
void myPrint(T a, T b)
{
	cout << "模板函数两个参数"; 
	cout << "a = " << a << "  b = " << b << endl;  // 模板函数两个参数a = A  b = B
}
// 形参的类型不同
template <typename T,class E>
void myPrint(T a, E b)
{
	cout << "模板函数两个参数";  
	cout << "a = " << a << "  b = " << b << endl; // 模板函数两个参数a = 10  b = 20
}
// 形参的个数不同
// 三个形参的函数模板
template <typename T>
void myPrint(T a, T b,T c)
{
	cout << "模板函数三个参数";
	cout << "a = " << a << "  b = " << b << endl; //模板函数三个参数a = 10.11  b = 20.22
}
void test05()
{
	cout << endl;
	myPrint(10, 20);  // 如果普通函数和函数模板都能匹配，优先使用普通函数
	myPrint('A', 'B'); // 如果函数模板能产生更好的匹配情况，优先使用函数模板
	myPrint<>(10, 20); // 可以使用空的函数模板形参类型表，来强制调用模板函数

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