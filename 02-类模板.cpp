#include <iostream>
using namespace std;

// 类模板
// 在声明泛型的时候也能泛型默认的类型
// 默认的泛型类型，如果在传参的时候不指定，就用默认类型，如果指定就用指定的类型
template <class NameType,class AgeType=int>
class Person
{
	NameType m_Name;
	AgeType m_Age;
public:
	Person(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void show()
	{
		cout << "name:" << m_Name << "  age:" << m_Age << endl;
	}
};

void test01()
{
	Person<string,int> p1("黑神话悟空",1000);
	p1.show();   // name:黑神话悟空  age:1000 

	Person<string, string> p2("黑神话八戒", "八百岁");
	p2.show();  // name:黑神话八戒  age:八百岁
	
	// 使用默认的泛型类型
	Person<string> p3("黑神话悟净", 600);
	p3.show();  // name:黑神话悟净  age:600
}

// 函数模板和类模板的联合使用
// 将类模板的对象当做函数的参数
// 1、指定传入的类型(推荐写法，方便理解，但是不够灵活)
void showType(Person<string, int>& p)
{
	p.show();
}

// 2、将参数的类型模板化(进一步使用函数模板将参数类型模板化，灵活度相对更高)
template <class T1,class T2>
void showTplPara(Person<T1, T2> &p)
{
	p.show();
}

// 3、 将整个类模板化
template <class T>
void showTplClass(T& p)
{
	p.show();
}

void test02()
{
	Person<string, int> p1("黑神话悟空", 1000);
	showType(p1);  // name:黑神话悟空  age:1000
	Person<string, string> p2("黑神话悟能", "八百岁");
	showTplPara(p2);  // name:黑神话悟能  age:八百岁
	Person<string> p3("黑神话悟净", 600);
	showTplClass(p3);  // name:黑神话悟净  age:600
}


// 类模板遇到继承
// 如果父类是类模板，子类可以是类模板也可以是普通类
// 父类和子类都是类模板，父类和子类的泛型可以不同
// 父类和子类都是类模板，父类和子类的泛型也可以定义同一种泛型类型

// 定义父类水果类Fruit，是模板类
template <class T>
class Fruit
{
public:
	Fruit();
};

// 在类内声明构造函数，在类外来定义
template <class T>  // 需要加上模板的声明
Fruit<T>::Fruit()
{
	cout << "我是父类Fruit，正在构造，类型是：" << typeid(T).name() << endl;
}

// 如果父类是类模板，子类可以是类模板也可以是普通类
// 子类是普通类，继承模板类
class Apple : public Fruit<int>
{
public:
	Apple()
	{
		cout << "Apple类正在构造，它是普通类。" << endl;
	}
};

// 父类是模板类 子类也是模板类，但是它们泛型类型不同
template <class T>
class Banana : public Fruit<int>
{
public:
	Banana()
	{
		cout << "Banana类正在构造，它是类模板，它的类型是" << typeid(T).name() << endl;
	}
};

// 父类是模板类，子类也是模板类，他们的泛型类型是相同的
template <class T>
class Orange : public Fruit<T>
{
public:
	Orange()
	{
		cout << "Orange类正在构造，它是类模板，它的类型是" << typeid(T).name() << endl;
	}
};

void test03()
{
	Apple a; //Apple 是普通类，它的父类是模板类，被指定成了int类型
	Banana<double> b;  // 子类是模板类，父类也是模板类，子类和父类的类型不同，父类的类型在子类继承的时候就已经定义好了
	Orange<long> o; //了类是模板类，父类也是模板类，子类和父类的类型相同，父类的类型在继承的时候没有定义也是用泛型T来表示，所以在子类实例化的时候才确定
}

int main()
{
	test01();
	cout << endl;
	test02();
	test03();
	return 0;
}