//LeetCode    1480.一维数组的动态和

//方法一：原地累加
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = 1; i < numsSize; i++)
    {
        nums[i] += nums[i - 1];
    }
    return nums;
}
