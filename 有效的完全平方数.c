//LeetCode    367.有效的完全平方数

//方法一：二分查找
bool isPerfectSquare(int num) {
    int left = 0, right = num;
    while (left <= right)
    {
        long mid = left + (right - left) / 2;
        if (mid * mid == num)
            return true;
        else if (mid * mid > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

//方法二：数学
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
