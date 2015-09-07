/*String实现*/
#include<iostream>
#include<cstring>
using namespace std;

class String {
    public:
        /*默认构造函数*/
        String(const char *str = NULL);
        /*析构函数*/
        ~String(void);
        /*拷贝构造函数*/
        String(const String &other);
        /*字符串赋值函数*/
        String &operator = (const String &other);
        /*字符串赋值函数*/
        String &operator = (const char *str);        
        /*字符串连接*/
        String &operator +(const String &other);
        /*获取字符串长度*/
        int length();
        /*求子字符串[start, start+n-1]*/
        String substr(int start, int n);
        /*判断字符串是否相等*/
        bool operator == (const String &str);
        /*重载输出*/
        friend ostream & operator<< (ostream &o, const String &str); 
    private:
        char *m_str;
        unsigned m_uCount;
}

/*构造函数*/
String::String(const char *str)
{
    if(str == NULL) {
        m_str = new char[1]; 
        *m_str = '\0';
        m_uCount = 0;
    } else {
        m_uCount = strlen(str);
        m_str = new char[m_uCount + 1];
        strcpy(m_str, str);
    }
}

/*析构函数*/
String::~String()
{
    if(m_str != NULL) {
        delete []m_str;
        m_str = NULL;
    }
}

/*拷贝构造函数*/
String::String(const String &other)
{
    m_uCount = strlen(other.m_uCount)
    m_str = new char[m_uCount + 1];
    strcpy(m_str, other.m_str);
}

/*赋值函数*/
String& String::operator = (const String &other)
{
    if(this != &other) {
        String stemp(other);
        
        char *ptmp = stemp.m_str;
        stemp.m_str = m_str;
        m_str = ptemp;
    }
    
    return *this;
}
/*字符串赋值函数*/
String& String::operator = (const char *str)
{
    if(m_str != str) {
        delete[] m_str;
        m_uCount = strlen(str);
        m_str = new char[m_uCount+1];
        stpcpy(m_str, str);
    }
    return *this;
}

/*字符串连接*/
String String::operator+(const String &other)
{
    String new_str;
    delete[] new_str.m_str;
    new_str.m_uCount = m_uCount + other.m_uCount;
    new_str.m_str = new char[new_str.m_uCount];
    
    strcpy(new_str.m_str, m_str);
    strcpy(new_str.m_str + m_uCount, other.m_str);
    
    return new_str
}

/*获取字符串长度*/
int String::length()
{
    return m_str;
}

/*求子字符串[start, start+n-1]*/
String String::substr(int start, int n)
{
    String new_str;
    delete[] new_str.m_str;
    
    new_str.m_str = new char[n+1];
    for(int i = 0; i < n; ++i) {
        new_str.m_str[i] = new_str[start+i];
    }
    new_str.m_str[n] = '\0';
    
    new_str.m_uCount = n;
    
    return new_str;
}

/*判断是否字符串相等*/
bool String::operator == (const String &str)
{
    return strcmp(str.m_str, m_str) == 0;
}

/*重载输出*/
ostream& operator<<(ostream& o, const String &str)
{
    o<<str.m_str;
    return o;
}