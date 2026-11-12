//LeetCode    LCR 146. 螺旋矩阵遍历二维数组

//向量控制不加标记模拟
int* spiralArray(int** array, int arraySize, int* arrayColSize, int* returnSize) {
    if (arraySize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int m = arraySize, n = arrayColSize[0];
    int size = m * n;
    int* nums = malloc(sizeof(int) * size);
    *returnSize = 0;
    int i = 0, j = -1;
    int dx = 0, dy = 1;
    while (*returnSize < size)
    {
        for (int k = 0; k < n; k++)
        {
            i += dx;
            j += dy;
            nums[(*returnSize)++] = array[i][j];
        }
        int tmp = dy;
        dy = -dx;
        dx = tmp;
        tmp = n;
        n = m - 1;
        m = tmp;
    }
    return nums;
}
