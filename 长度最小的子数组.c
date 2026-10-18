//LeetCode    长度最小的子数组.c

//方法一：滑动窗口循环外更新答案
int minSubArrayLen(int target, int* nums, int numsSize) {
    int l = 0, ans = numsSize + 1, sum = 0;
    for (int r = 0; r < numsSize; r++)
    {
        sum += nums[r];
        while (sum - nums[l] >= target)
        {
            sum -= nums[l++];
        }
        if (sum >= target)
            ans = ans < r - l + 1 ? ans : r - l + 1;
    }
    return ans <= numsSize ? ans : 0;
}

//方法二：滑动窗口循环内更新答案
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
    return ans <= numsSize ? ans : 0;
}
