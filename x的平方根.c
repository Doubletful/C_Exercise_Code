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

//方法二：牛顿迭代法
int mySqrt(int x) {
    long long n = x;
    while (n * n > x)
    {
        n = (n + x / n) / 2;
    }
    return n;
}
