//LeetCode    283.移动零

//方法一：两次遍历填补零
void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] != 0)
            nums[i++] = nums[j];
    }
    while(i < numsSize)
    {
        nums[i++] = 0;
    }
}

//方法二：双指针交换元素
