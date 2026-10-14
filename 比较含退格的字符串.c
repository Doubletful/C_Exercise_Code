//LeetCode    844.比较含退格的字符串

//方法一：双指针模拟
bool backspaceCompare(char* s, char* t) {
    int s1 = 0, t1 = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '#')
        {
            if (s1) --s1;
        }
        else
            s[s1++] = s[i];
    }
    for (int i = 0; t[i]; i++)
    {
        if (t[i] == '#')
        {
            if (t1) --t1;
        }
        else
            t[t1++] = t[i];
    }
    s[s1] = t[t1] = '\0';
    return !strcmp(s, t);
}

//方法二：单循环双指针模拟
bool backspaceCompare(char* s, char* t) {
    int s1 = 0, t1 = 0;
    int slen = strlen(s), tlen = strlen(t);
    for (int i = 0; i < slen || i < tlen; i++)
    {
        if (i < slen)
        {
            if (s[i] == '#')
            {
                if (s1) --s1;
            }
            else
                s[s1++] = s[i];
        }
        if (i < tlen)
        {
            if (t[i] == '#')
            {
                if (t1) --t1;
            }
            else
                t[t1++] = t[i];
        }
    }
    s[s1] = t[t1] = '\0';
    return !strcmp(s, t);
}
