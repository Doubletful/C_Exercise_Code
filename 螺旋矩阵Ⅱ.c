//LeetCOde    59.螺旋矩阵Ⅱ

//方法一：模拟
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** nums = malloc(sizeof(int*) * n);
    *returnColumnSizes = malloc(sizeof(int*) *  n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    int i = 0, j = 0, cur = 2;
    nums[i][j] = 1;
    while (cur <= n * n)
    {
        while (j < n - 1 && nums[i][j + 1] == 0)
        {
            nums[i][++j] = cur++;
        }
        while (i < n - 1 && nums[i + 1][j] == 0)
        {
            nums[++i][j] = cur++;
        }
        while (j > 0 && nums[i][j - 1] == 0)
        {
            nums[i][--j] = cur++;
        }
        while (i > 0 && nums[i - 1][j] == 0)
        {
            nums[--i][j] = cur++;
        }
    }
    return nums;
}

//方法二：方向向量
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** nums = malloc(sizeof(int*) * n);
    *returnColumnSizes = malloc(sizeof(int*) *  n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    int dx = 0, dy = 1;
    int x = 0, y = 0;
    for (int i = 1; i <= n * n; i++)
    {
        nums[x][y] = i;
        if (nums[(x + dx + n) % n][(y + dy + n) % n] != 0)
        {
            int tmp = dy;
            dy = -dx;
            dx = tmp;
        }
        x += dx;
        y += dy;
    }
    return nums;
}
