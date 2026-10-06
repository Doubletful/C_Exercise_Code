  //方法一暴力解法
int mySqrt(int x) {
  long long n = 1;
    while (n * n < x)
    {
        n += 1;
    }
    return n * n == x ? n : n - 1;
}
