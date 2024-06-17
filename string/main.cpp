#include <iostream>

using namespace std;

class MyString
{
	char* str; // указатель на строку
	int length; // длина строки

public:
	// методы класса
	MyString()
	{
		length = 80;
		str = new char[length + 1];
		for (int i = 0; i <= length; i++)
		{
			str[i] = ' ';
		}
		str[length] = '\0';
	}
	MyString(int size) : length(size)
	{
		str = new char[length + 1];
		for (int i = 0; i <= length; i++)
		{
			str[i] = ' ';
		}
		str[length] = '\0';
	}
	MyString(const char* nStr)
	{
		length = strlen(nStr);
		str = new char[strlen(nStr) + 1];
		strcpy_s(str, length + 1, nStr);
	}
	void Input()
	{
		cout << "Enter text --> ";
		cin.getline(str, length + 1);
	}
	void Print()
	{
		cout << str << endl;
	}
	void MyStrcpy(MyString& obj)
	{
		length = obj.length;
		str = new char[strlen(obj.str) + 1];
		strcpy_s(str, length + 1, obj.str);
	}
	bool MyStrStr(const char* str2)
	{
		char* result = strstr(str, str2);
		return result != 0;
	}
	int MyChr(char c)
	{
		for (int i = 0; i < length; i++)
		{
			if (str[i] == c)
			{
				return i;
			}
		}
		return -1;
	}
	int MyStrLen()
	{
		return strlen(str);
	}
	void MyStrCat(MyString& b)
	{
		char* newStr = new char[length + b.length + 1];
		for (int i = 0; i < length; i++)
		{
			newStr[i] = str[i];
		}
		for (int i = 0; i <= b.length; i++)
		{
			newStr[length + i] = b.str[i];
		}
		delete[] str;
		str = newStr;
		length += b.length;
	}
	void MyDelChr(char c)
	{
		int a = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] != c) {
				str[a++] = str[i];
			}
		}
		str[a] = ' ';
		length = a;
	}
	int MyStrCmp(const MyString& b)
	{
		return strcmp(str, b.str);
	}
	~MyString()
	{
		delete[] str;
	}
};

int main()
{
	MyString str1("IT");
	MyString str2("STEP");
	str1.MyStrCat(str2);
	str1.Print();
	MyString str3;
	str3.Input();
	str3.Print();
	cout << "Length --> " << str1.MyStrLen() << endl;
}