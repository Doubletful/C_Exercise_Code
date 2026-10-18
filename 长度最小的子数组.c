//LeetCode    长度最小的子数组.c

//方法一：滑动窗口
int minSubArrayLen(int target, int* nums, int numsSize) {
    int l = 0, ans = numsSize + 1, sum = 0;
    for (int r = 0; r < numsSize; r++)
    {
        sum += nums[r];
        while (sum >= target)
        {
            ans = ans < r - l + 1 ? ans : r - l + 1;
            sum -= nums[l++];
        }
    }
    return ans == numsSize + 1 ? 0 : ans;
}
