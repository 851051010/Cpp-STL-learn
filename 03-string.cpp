#include <iostream>

using namespace std;

void test01()
{
	string str1; //�޲ι��죬����һ���յ��ַ���
	cout << "str1 = " << str1 << endl;   // str1 =

	const char* str = "�����Ĳ���������";
	string str2(str);
	cout << "str2 = " << str2 << endl;  // str2 = �����Ĳ���������

	string str3(str2);
	cout << "str3 = " << str3 << endl;  // str2 = �����Ĳ���������

	string str4(5, 'A');
	cout << "str4 = " << str4 << endl;  // str4 = AAAAA
	cout << endl;
}

void test02()
{
	// ���ظ�ֵ�����
	string str1;
	str1 = "hello world";
	cout << "str1=" << str1 << endl;  // str1=hello world

	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;  // str2=hello world

	string str3;
	str3 = 'A';
	cout << "str3=" << str3 << endl;  // str3=A

	// assign()������ʵ�ָ�ֵ����
	string str4;
	str4.assign("Hello Mme");
	cout << "str4=" << str4 << endl; // str4=Hello Mme

	string str5;
	str5.assign("hello mme", 5);
	cout << "str5=" << str5 << endl;  // str5=hello

	string str6(str5);
	cout << "str6=" << str6 << endl;  // str6=hello

	string str7(6,'X');
	cout << "str7=" << str7 << endl;  // str7=XXXXXX

	cout << endl;
}

void test03()
{
	// ����+=�����
	string str1 = "��";
	str1 += "�������";
	cout << "str1 = " << str1 << endl;  // str1 = �Ұ������

	str1 += ',';
	cout << "str1 = " << str1 << endl;  // str1 = �Ұ������,

	string str2 = "���";
	str1 += str2;
	cout << "str1 = " << str1 << endl;  // str1 = �Ұ������,���

	string str3 = "i like play";
	str3.append(" black legend ");
	str3.append("wukong wuneng wujing", 7);
	string str4 = "GG game";
	str3.append(str4, 3, 4);
	cout << "str3 = " << str3 << endl;  // str3 = i like play black legend wukong game
	cout << endl;
}

void test04()
{
	// �������Ҳ���
	string str1 = "abcdefgde";
	int pos = str1.find("de");
	cout << "de��һ�γ��ֵ�λ���ǣ�" << pos << endl;  
	// de��һ�γ��ֵ�λ���ǣ�3

	pos = str1.find("de", 5);
	cout << "de�ڶ��γ��ֵ�λ���ǣ�" << pos << endl; 
	// de�ڶ��γ��ֵ�λ���ǣ�7

	pos = str1.find("fgde", 0, 2);
	cout << "fg�ַ����ֵ�λ���ǣ�" << pos << endl; 
	// fg�ַ����ֵ�λ���ǣ�5

	pos = str1.find('g');
	cout << "g�ַ����ֵ�λ���ǣ�" << pos << endl; 
	// g�ַ����ֵ�λ���ǣ�6
	cout << endl;
}

void test05()
{
	// ����������в���
	string str1 = "abcdefgde";
	int pos = str1.rfind("de");
	cout << "de���һ�γ��ֵ�λ���ǣ�" << pos << endl;  
	// de���һ�γ��ֵ�λ���ǣ�7

	pos = str1.rfind("de", 5);  // ���±�Ϊ5��λ����ǰ��
	cout << "de�Ӻ���ǰ�ڶ��γ��ֵ�λ���ǣ�" << pos << endl; 
	// de�Ӻ���ǰ�ڶ��γ��ֵ�λ���ǣ�3

	pos = str1.rfind("fgde", string::npos, 2);
	cout << "fg���һ�γ��ֵ�λ���ǣ�" << pos << endl; 
	// fg���һ�γ��ֵ�λ���ǣ�5

	string str1 = "abcdefgde";
	pos = str1.rfind('e');
	cout << "e���һ�γ��ֵ�λ���ǣ�" << pos << endl; 
	// e���һ�γ��ֵ�λ���ǣ�8

	// �滻
	str1.replace(3, 2, "88888");
	cout << "str1=" << str1 << endl; 
	// str1=abc88888fgde
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
