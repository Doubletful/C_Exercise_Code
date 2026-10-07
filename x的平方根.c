//LeetCode    69.x的平方根

//方法一：暴力解法
int mySqrt(int x) {
    long long n = 1;
    while (n * n < x)
    {
        n += 1;
    }
    return n * n == x ? n : n - 1;
}

//方法二：传统二分
int mySqrt(int x) {
    int l = 1, r = 46340;
    while (l <= r)
    {
        int i = l + (r - l) / 2;
        if (i * i <= x)
            l = i + 1;
        else
            r = i - 1;
    }
    return r;
}

//方法三：特制二分
int mySqrt(int x) {
    if (x == 1)
        return 1;
    int l = 0, r = x;
    while (r - l > 1)
    {
        int i = l + (r - l) / 2;
        if (i > x / i)
            r = i;
        else
            l = i;
    }
    return l;
}

//方法四：牛顿迭代法
int mySqrt(int x) {
    long long n = x;
    while (n * n > x)
    {
        n = (n + x / n) / 2;
    }
    return n;
}
