//LeetCode    27.移除元素

//方法一：双指针
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (nums[j] != val)
            nums[i++] = nums[j];
    }
    return i;
}

//方法二：双指针优化
