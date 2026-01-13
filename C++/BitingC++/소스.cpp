#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>   // strlen, strcpy, strcat


class string
{
private:
    char* str;
    int len; // '\0' 제외 길이

public:

    // 문자 c가 n개 있는 문자열
    string(char c, int n): str(nullptr), len(0)
    {
        if (n < 0) n = 0;
        len = n;
        str = new char[len + 1];
        for (int i = 0; i < len; ++i) str[i] = c;
        str[len] = '\0';
    }

    // C 문자열로부터 생성
    string(const char* s)
        : str(nullptr), len(0)
    {
        if (!s) s = "";
        len = static_cast<int>(std::strlen(s));
        str = new char[len + 1];
        std::strcpy(str, s);
    }

    // 복사 생성자 (깊은 복사)
    string(const string& s)
        : str(nullptr), len(s.len)
    {
        str = new char[len + 1];
        std::strcpy(str, s.str);
    }

    // 복사 대입 연산자 (Rule of Three)
    string& operator=(const string& s)
    {
        if (this == &s) return *this;

        char* newbuf = new char[s.len + 1];
        std::strcpy(newbuf, s.str);

        delete[] str;
        str = newbuf;
        len = s.len;
        return *this;
    }

    ~string()
    {
        delete[] str;
    }

    // 뒤에 붙이기
    void add_string(const string& s)
    {
        char* newbuf = new char[len + s.len + 1];
        std::strcpy(newbuf, str);
        std::strcat(newbuf, s.str);

        delete[] str;
        str = newbuf;
        len += s.len;
    }

    // 내용 덮어쓰기(복사)
    void copy_string(const string& s)
    {
        if (this == &s) return;
        *this = s; // 대입 연산자 재사용
    }
    bool equal(const string& s)
    {
        if (s.len != len) return false;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != s.str[i]) return false;
        }
        return true;
    }

    int strlen() const
    {
        return len;
    }

    const char* c_str() const
    {
        return str;
    }
};

int main()
{
    string s1("abc");     // "aaa"
    string s2("adc");       // "bc"
    //s1.add_string(s2);     // "aaabc"
    std::cout << s1.c_str() << "\n";   // aaabc
    std::cout << s1.strlen() << "\n";  // 5
    std::cout << s1.equal(s2);
    return 0;
}
