#include <iostream>

int matchhere(const char* regexp, const char* text);
int matchstar(int c, const char* regexp, const char* text);

int match(const char* regexp, const char* text)
{
    if('^' == regexp[0])
        return matchhere(regexp+1, text);

    do
    {
        if(matchhere(regexp, text))
            return 1;
    } while ('\0' != *text++);
    
    return 0;
}

int matchhere(const char* regexp, const char* text)
{
    if('\0' == regexp[0])
        return 1;

    // 通配符匹配
    if('*' == regexp[1])
        return matchstar(regexp[0], regexp+2, text);

    // 正则表达式末尾包含$， 那么仅当text位于末尾时才会匹配成功
    if('$'==regexp[0] && '\0'==regexp[1])
        return '\0' == *text;

    if('\0'!=*text && ('.'==regexp[0] || *text==regexp[0]))
        return matchhere(regexp+1, text+1);

    return 0;
}

// 在text开头查找c * regexp
int matchstar(int c, const char* regexp, const char* text)
{
    do
    {
        // 通配符* 匹配零个或者多个实例
        if(matchhere(regexp, text))
            return 1;
    } while ('\0' != *text && (c == *text++ || '.' == c));
    
    return 0;
}

int main(int, char**)
{
    const char* regexp = "abc";
    const char* text = "abababc";
    bool res = match(regexp, text);
    std::cout << "result:" << res << std::endl;
    return 1;
}
