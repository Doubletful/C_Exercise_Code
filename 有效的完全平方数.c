//LeetCode    367.有效的完全平方数

//方法一：暴力解法
bool isPerfectSquare(int num) {
    for (long i = 1; i <= num; i++)
    {
        if (i * i == num)
            return true;
    }
    return false;
}

//方法二：数学公式
//数学知识：连续奇数之和等于平方数
//公式：n**2 = 1 + 3 + 5 + ⋯ + (2n − 1)
bool isPerfectSquare(int num) {
    int n = 1;
    while (num > 0)
    {
        num -= n;
        n += 2;
    }
    return num == 0;
}

//方法三：二分查找
bool isPerfectSquare(int num) {
    int l = 1, r = num;
    while (l <= r)
    {
        long i = l + (r - l) / 2;
        if (i * i == num)
            return true;
        else if (num / i < i)
            r = i - 1;
        else
            l = i + 1;
    }
    return false;
}
