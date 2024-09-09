#include <iostream>

using namespace std;

void test01()
{
	string str1; //无参构造，创建一个空的字符串
	cout << "str1 = " << str1 << endl;   // str1 =

	const char* str = "最美的不是下雨天";
	string str2(str);
	cout << "str2 = " << str2 << endl;  // str2 = 最美的不是下雨天

	string str3(str2);
	cout << "str3 = " << str3 << endl;  // str2 = 最美的不是下雨天

	string str4(5, 'A');
	cout << "str4 = " << str4 << endl;  // str4 = AAAAA
	cout << endl;
}

void test02()
{
	// 重载赋值运算符
	string str1;
	str1 = "hello world";
	cout << "str1=" << str1 << endl;  // str1=hello world

	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;  // str2=hello world

	string str3;
	str3 = 'A';
	cout << "str3=" << str3 << endl;  // str3=A

	// assign()函数来实现赋值操作
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
	// 重载+=运算符
	string str1 = "我";
	str1 += "爱玩黑神话";
	cout << "str1 = " << str1 << endl;  // str1 = 我爱玩黑神话

	str1 += ',';
	cout << "str1 = " << str1 << endl;  // str1 = 我爱玩黑神话,

	string str2 = "悟空";
	str1 += str2;
	cout << "str1 = " << str1 << endl;  // str1 = 我爱玩黑神话,悟空

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
	// 从左往右查找
	string str1 = "abcdefgde";
	int pos = str1.find("de");
	cout << "de第一次出现的位置是：" << pos << endl;  
	// de第一次出现的位置是：3

	pos = str1.find("de", 5);
	cout << "de第二次出现的位置是：" << pos << endl; 
	// de第二次出现的位置是：7

	pos = str1.find("fgde", 0, 2);
	cout << "fg字符出现的位置是：" << pos << endl; 
	// fg字符出现的位置是：5

	pos = str1.find('g');
	cout << "g字符出现的位置是：" << pos << endl; 
	// g字符出现的位置是：6
	cout << endl;
}

void test05()
{
	// 从右往左进行查找
	string str1 = "abcdefgde";
	int pos = str1.rfind("de");
	cout << "de最后一次出现的位置是：" << pos << endl;  
	// de最后一次出现的位置是：7

	pos = str1.rfind("de", 5);  // 从下标为5的位置往前找
	cout << "de从后往前第二次出现的位置是：" << pos << endl; 
	// de从后往前第二次出现的位置是：3

	pos = str1.rfind("fgde", string::npos, 2);
	cout << "fg最后一次出现的位置是：" << pos << endl; 
	// fg最后一次出现的位置是：5

	string str1 = "abcdefgde";
	pos = str1.rfind('e');
	cout << "e最后一次出现的位置是：" << pos << endl; 
	// e最后一次出现的位置是：8

	// 替换
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
