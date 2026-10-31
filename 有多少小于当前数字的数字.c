//LeetCode    1365.有多少小于当前数字的数字

//方法一：排序
int cmp(const void* a, const void* b) {
    //需要先转化为int**(原数组指针)后解引用找到元素(int*)后再访问指针指向空间的第一个值
    return (*(int**)a)[0] - (*(int**)b)[0]; //升序
}
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    //创建指针数组存储nums中的值及被排序前的原索引
    int* data[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        //为数组开辟内存，让每个指针变量元素指向2*int大小的空间
        data[i] = (int*)malloc(2 * sizeof(int));
        data[i][0] = nums[i]; //值
        data[i][1] = i; //原索引
    }
    //排序nums数组
    qsort(data, numsSize, sizeof(int*), cmp);

    //创建用于返回的数组
    int* ret = (int*)malloc(numsSize * sizeof(int));
    //指定返回数组的大小(用于题目的测试用例)
    *returnSize = numsSize;

    //定义被排序后的数组中每个值各自大于其余值的数量
    int prev = -1;
    for (int i = 0; i < numsSize; i++)
    {
        //遍历元素为1时为最小值，当其余值中存在与前一个值相等的情况，大于的值的个数相同
        if (prev == -1 || data[i][0] != data[i - 1][0])
        {
            prev = i; //有序数组的索引值即为各自值大于的值的个数
        }
        //通过data存储的各值的原索引找到prev(大于的值的个数)在ret中对应的存储位置
        ret[data[i][1]] = prev;
    }
    return ret;
}

//方法二：哈希累加总和统计
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    //定义哈希表统计数字个数
    int hash[101] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    }
    //计算小于等于当前数字的个数存放到当前数字的哈希位
    for (int i = 1; i <= 100; i++)
    {
        hash[i] += hash[i - 1];
    }
    //通过当前数字找到小于当前数字的总个数，特判当前数字为0的情况
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = nums[i] == 0 ? 0 : hash[nums[i] - 1];
    }
    return ans;
}

//方法三：哈希总和统计
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int* ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    //定义哈希表统计数字个数
    int hash[101] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    }
    //累加统计小于当前数字的总和
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            ans[i] += hash[j];
        }
    }
    return ans;
}
