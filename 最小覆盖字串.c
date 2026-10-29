//LeetCode    76.最小覆盖字串

//方法一：滑动窗口，存储字母的个数和种类
char* minWindow(char* s, char* t) {
    int cnt_t[128] = {0};
    int cnt_s[128] = {0};
    int tcnt = 0, scnt = 0;
    for (int i = 0; t[i]; i++)
    {
        tcnt += cnt_t[t[i]]++ == 0;
    }
    int l = 0, ans_l = -1, ans_r = INT_MAX / 2; // -1表未找到答案的标志，除2避免溢出
    for (int r = 0; s[r]; r++)
    {
        int ch1 = s[r];
        if (cnt_t[ch1])
        {
            cnt_s[ch1]++;
            if (cnt_s[ch1] == cnt_t[ch1])
                scnt++;
        }
        while (tcnt == scnt)
        {
            if (r - l < ans_r - ans_l)
            {
                ans_l = l;
                ans_r = r;
            }
            int ch2 = s[l++];
            if (cnt_t[ch2])
            {
                if (cnt_s[ch2] == cnt_t[ch2])
                    scnt--;
                cnt_s[ch2]--;
            }
        }
    }
    if (ans_l < 0)
        return "";
    s[ans_r + 1] = '\0';
    return s + ans_l;
}

//方法二：优化，只存储字母的个数
bool is_satisfaction(int* cnt_s, int* cnt_t)
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (cnt_s[i] < cnt_t[i])
            return false;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (cnt_s[i] < cnt_t[i])
            return false;
    }
    return true;
}
char* minWindow(char* s, char* t) {
    int cnt_s[128] = {0};
    int cnt_t[128] = {0};
    for (int i = 0; t[i]; i++)
    {
        cnt_t[t[i]]++;
    }
    int ans_l = -1, ans_r = INT_MAX / 2;
    int l = 0;
    for (int r = 0; s[r]; r++)
    {
        cnt_s[s[r]]++;
        while (is_satisfaction(cnt_s, cnt_t))
        {
            if (r - l < ans_r - ans_l)
            {
                ans_l = l;
                ans_r = r;
            }
            cnt_s[s[l++]]--;
        }
    }
    if (ans_l < 0)
        return "";
    s[ans_r + 1] = '\0';
    return s + ans_l;
}
