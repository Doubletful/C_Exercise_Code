int mySqrt(int x) {
  //给你一个非负整数 x ，计算并返回 x 的 算术平方根 
    long long n = 1;
    while (n * n < x)
    {
        n += 1;
    }
    return n * n == x ? n : n - 1;
}
