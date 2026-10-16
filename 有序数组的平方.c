//LeetCode    977.有序数组的平方

//方法一：平方后双指针
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] *= nums[i];
    }
    int l = 0, r = numsSize - 1, i = numsSize - 1;
    while (l <= r)
    {
        ans[i--] = nums[l] > nums[r] ? nums[l++] : nums[r--];
    }
    return ans;
}

//方法二：取反比较双指针
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int l = 0, r = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        int x = nums[l], y = nums[r];
        if (-x > y)
        {
            ans[i] = x * x;
            l++;
        }
        else
        {
            ans[i] = y * y;
            r--;
        }
    }
    return ans;
}
