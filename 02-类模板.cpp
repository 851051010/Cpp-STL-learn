#include <iostream>
using namespace std;

// ��ģ��
// ���������͵�ʱ��Ҳ�ܷ���Ĭ�ϵ�����
// Ĭ�ϵķ������ͣ�����ڴ��ε�ʱ��ָ��������Ĭ�����ͣ����ָ������ָ��������
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
	Person<string,int> p1("�������",1000);
	p1.show();   // name:�������  age:1000 

	Person<string, string> p2("���񻰰˽�", "�˰���");
	p2.show();  // name:���񻰰˽�  age:�˰���
	
	// ʹ��Ĭ�ϵķ�������
	Person<string> p3("������", 600);
	p3.show();  // name:������  age:600
}

// ����ģ�����ģ�������ʹ��
// ����ģ��Ķ����������Ĳ���
// 1��ָ�����������(�Ƽ�д����������⣬���ǲ������)
void showType(Person<string, int>& p)
{
	p.show();
}

// 2��������������ģ�廯(��һ��ʹ�ú���ģ�彫��������ģ�廯��������Ը���)
template <class T1,class T2>
void showTplPara(Person<T1, T2> &p)
{
	p.show();
}

// 3�� ��������ģ�廯
template <class T>
void showTplClass(T& p)
{
	p.show();
}

void test02()
{
	Person<string, int> p1("�������", 1000);
	showType(p1);  // name:�������  age:1000
	Person<string, string> p2("��������", "�˰���");
	showTplPara(p2);  // name:��������  age:�˰���
	Person<string> p3("������", 600);
	showTplClass(p3);  // name:������  age:600
}


// ��ģ�������̳�
// �����������ģ�壬�����������ģ��Ҳ��������ͨ��
// ��������඼����ģ�壬���������ķ��Ϳ��Բ�ͬ
// ��������඼����ģ�壬���������ķ���Ҳ���Զ���ͬһ�ַ�������

// ���常��ˮ����Fruit����ģ����
template <class T>
class Fruit
{
public:
	Fruit();
};

// �������������캯����������������
template <class T>  // ��Ҫ����ģ�������
Fruit<T>::Fruit()
{
	cout << "���Ǹ���Fruit�����ڹ��죬�����ǣ�" << typeid(T).name() << endl;
}

// �����������ģ�壬�����������ģ��Ҳ��������ͨ��
// ��������ͨ�࣬�̳�ģ����
class Apple : public Fruit<int>
{
public:
	Apple()
	{
		cout << "Apple�����ڹ��죬������ͨ�ࡣ" << endl;
	}
};

// ������ģ���� ����Ҳ��ģ���࣬�������Ƿ������Ͳ�ͬ
template <class T>
class Banana : public Fruit<int>
{
public:
	Banana()
	{
		cout << "Banana�����ڹ��죬������ģ�壬����������" << typeid(T).name() << endl;
	}
};

// ������ģ���࣬����Ҳ��ģ���࣬���ǵķ�����������ͬ��
template <class T>
class Orange : public Fruit<T>
{
public:
	Orange()
	{
		cout << "Orange�����ڹ��죬������ģ�壬����������" << typeid(T).name() << endl;
	}
};

void test03()
{
	Apple a; //Apple ����ͨ�࣬���ĸ�����ģ���࣬��ָ������int����
	Banana<double> b;  // ������ģ���࣬����Ҳ��ģ���࣬����͸�������Ͳ�ͬ�����������������̳е�ʱ����Ѿ��������
	Orange<long> o; //������ģ���࣬����Ҳ��ģ���࣬����͸����������ͬ������������ڼ̳е�ʱ��û�ж���Ҳ���÷���T����ʾ������������ʵ������ʱ���ȷ��
}

int main()
{
	test01();
	cout << endl;
	test02();
	test03();
	return 0;
}