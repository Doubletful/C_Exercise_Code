//LeetCode    26.删除有序数组中的重复项

//方法一：双指针
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    for (int j = 1; j < numsSize; j++)
    {
        if (nums[j] != nums[i])
            nums[++i] = nums[j];
    }
    return i + 1;
}
