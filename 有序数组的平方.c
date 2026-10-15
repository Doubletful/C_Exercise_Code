//LeetCode    977.有序数组的平方

//方法一：平方后双指针
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] *= nums[i];
    }
    int l = 0, r = numsSize - 1, i = numsSize - 1;
    while (l <= r)
    {
        ans[i--] = nums[l] > nums[r] ? nums[l++] : nums[r--];
    }
    *returnSize = numsSize;
    return ans;
}
