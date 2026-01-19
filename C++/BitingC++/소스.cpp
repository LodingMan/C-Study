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
		if (totalMemory < len) totalMemory = len+1;
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
		AddLastNull(len);
		SetTotalMem(len);
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
	void Insert(int loc, const String& str)
	{
		if (len < loc) return;
		char* temp = string;

		int totalSize = len + str.len + 1;
		string = new char[totalSize];
		memcpy(string, temp, loc);
		memcpy(string + loc, str.string, str.len);
		memcpy(string + loc + str.len, temp + loc, len-loc);
		delete[] temp;

		len = len+str.len;
		AddLastNull(len);
		SetTotalMem(totalSize);
	}
	void Erase(int loc, int num)
	{
		if (loc + num > len) 
		{
			num = len - loc;
		}
		if (len < loc) return;
		for (int i = loc; i <= len - num; i++)
		{
			string[i] = string[i + num];
		}
		len -= num;
		AddLastNull(len);
	}
	int Find(int loc, const String& str)
	{
		int i, j;
		if (loc > len) return -1;
		for (i = loc; i <= len - str.len; i++)
		{
			for (j = 0; j < str.len; j++)
			{
				if (string[i + j] != str.string[j]) break;
			}
			if (j == str.len) return i;
		}

		return -1;
	}
	// 여기서 접두사 감지해서 리스트로만들어야됨.
	int* Pi(String& str)
	{
		int j = 0;
		const int length = str.len;
		int* temp = new int[str.len]();		
		for (int i = 1; i < length; i++)
		{

			if (str.string[i] == str.string[j]) 
			{
				temp[i] = ++j;
			}
			else
			{
				if(j != 0)
				j = temp[j-1];
			}
		}
		return temp;
	}
	int FindKLP(String& str)
	{
		int* pi = Pi(str);
		int j = 0;
		for (int i = 0; i < len; i++)
		{
			while(j != 0 && string[i] != str.string[j])
			{
				j = pi[j - 1];
			}
			if (string[i] == str.string[j])
			{
				if (j == str.len-1) return i - str.len;
				
				j++;
			}
		}
		return -1;
	}

};
int main()
{
	String str1("abacaabaccabacabaa");
	String str2("abacab");
	String str3(str2);
	//str2.Erase(2, 2);
	
	std::cout << str1.FindKLP(str2);
	

	return 0;
}