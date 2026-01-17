#include<iostream>
#include "header.h"

class String 
{
private:
	char* string;
	int len;
	int totalMemory;
public:
	void SetTotalMem(int len)
	{
		if (totalMemory < len) totalMemory = len;
	}
	void AddLastNull(int len)
	{
		string[len] = '\0';
	}
	String(char c)
	{
		len = 1;
		string = new char[len+1];
		string[0] = c;
		SetTotalMem(len);
		AddLastNull(len);
	}
	String(const char* str)
	{
		len = strlen(str);
		string = new char[len+1];
		memcpy(string, str, len);
		SetTotalMem(len);
		AddLastNull(len);
	}
	String(const String& str)
	{
		len = str.len;
		string = new char[len+1];
		memcpy(string, str.string, str.len);
		SetTotalMem(len);
		AddLastNull(len);
	}
	void Copy(const String& str)
	{
		len = str.len;

		if (str.len > totalMemory)
		{
			delete[] string;
			string = new char[len+1];
		}
		memcpy(string, str.string, str.len);
		SetTotalMem(len);
		AddLastNull(len);
	}
	void Format(const String& str)
	{
		int totalLen = str.len + len;
		if (totalLen > totalMemory)
		{
			char* newStr = new char[totalLen+1];
			memcpy(newStr,string ,len);
			memcpy(newStr+len, str.string, str.len);
			delete[] string;
			string = newStr;
		}
		else
		{
			memcpy(string + len, str.string, str.len);
		}
		len = totalLen;
		SetTotalMem(len);
		AddLastNull(len);
	}
	String& operator=(const String& str)
	{
		len = str.len;
		if (str.len > totalMemory)
		{
			char* newString = new char[str.len+1];
			memcpy(newString, str.string, str.len);
			delete[] string;
			string = newString;

		}
		else
		{
			memcpy(string, str.string, str.len);
		}
		SetTotalMem(len);
		AddLastNull(len);
		return *this;
	}
	const char* GetString()
	{
		return string;
	}
};

int main()
{
	String str1('a');
	String str2("hello");
	String str3(str2);
	str1.Format(str3);
	
	char i[100];
	std::cin >> i;
	str1.Copy(i);
	std::cout << str1.GetString();
	

	return 0;
}