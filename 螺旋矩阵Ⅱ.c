//LeetCode    59.螺旋矩阵Ⅱ

//方法一：判断下一位的值模拟
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

//方法二：设定并缩小边界模拟
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** nums = malloc(sizeof(int*) * n);
    (*returnColumnSizes) = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    int t = 0, l = 0, b = n - 1, r = n - 1;
    int cur = 1;
    while (cur <= n * n)
    {
        for (int i = l; i <= r; i++)
        {
            nums[t][i] = cur++;
        }
        t++;
        for (int i = t; i <= b; i++)
        {
            nums[i][r] = cur++;
        }
        r--;
        for (int i = r; i >= l; i--)
        {
            nums[b][i] = cur++;
        }
        b--;
        for (int i = b; i >= t; i--)
        {
            nums[i][l] = cur++;
        }
        l++;
    }
    return nums;
}

//方法三：向量控制模拟
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));
    int** ans = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        (*returnColumnSizes)[i] = n;
        ans[i] = calloc(n, sizeof(int));
    }
    int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int i = 0, j = 0, di = 0, cur = 1;
    while (cur <= n * n)
    {
        ans[i][j] = cur++;
        int x = i + DIRS[di][0];
        int y = j + DIRS[di][1];
        if (x < 0 || y < 0 || x >= n || y >= n || ans[x][y])
            di = (di + 1) % 4;
        i += DIRS[di][0];
        j += DIRS[di][1];
    }
    return ans;
}
