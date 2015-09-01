/*String实现*/
class String {
    public:
        /*构造函数*/
        String(const char *str = NULL);
        /*析构函数*/
        ~String(void);
        /*拷贝构造函数*/
        String(const String &other);
        /*赋值函数*/
        String &operator = (String &other);
        
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
    } else {
        m_str = new char[strlen(str) + 1];
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
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str;
}

/*赋值函数*/
String::String &operator = (String &other)
{
    if(this != &other) {
        String stemp(other);
        
        char *ptmp = stemp.m_str;
        stemp.m_str = m_str;
        m_str = ptemp;
    }
    
    return *this;
}
