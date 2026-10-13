//LeetCode    844.比较含退格的字符串

//方法一：双指针模拟
bool backspaceCompare(char* s, char* t) {
    int l1 = 0, l2 = 0;
    for (int r = 0; s[r]; r++)
    {
        if (s[r] == '#')
        {
            if (l1) --l1;
        }
        else
            s[l1++] = s[r];
    }
    for (int r = 0; t[r]; r++)
    {
        if (t[r] == '#')
        {
            if (l2) --l2;
        }
        else
            t[l2++] = t[r];
    }
    s[l1] = '\0';
    t[l2] = '\0';
    return !strcmp(s, t);
}
