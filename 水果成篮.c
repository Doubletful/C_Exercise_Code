//LeetCode    904.水果成篮

//方法二：滑动窗口简写
int totalFruit(int* fruits, int fruitsSize) {
    int hash[100000] = {0};
    int l = 0, cnt = 0, ans = 0;
    for (int r = 0; r < fruitsSize; r++)
    {
        cnt += hash[fruits[r]]++ == 0;
        while (cnt > 2)
        {
            cnt -= --hash[fruits[l++]] == 0;
        }
        ans = ans > r - l + 1 ? ans : r - l + 1;
    }
    return ans;
}
