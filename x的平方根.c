int mySqrt(int x) {
  //方法一
  long long n = 1;
    while (n * n < x)
    {
        n += 1;
    }
    return n * n == x ? n : n - 1;
}
