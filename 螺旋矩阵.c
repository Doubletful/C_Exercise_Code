//LeetCode    54.螺旋矩阵

//方法一：设定并缩小边界模拟
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = *matrixColSize;
    int r = n - 1, b = m - 1, l = 0, t = 0;
    int* nums = malloc(sizeof(int) * m * n);
    int idx = 0;
    while (idx < m * n)
    {
        for (int i = l; i <= r; i++)
        {
            nums[idx++] = matrix[t][i];
        }
        t++;
        for (int i = t; i <= b; i++)
        {
            nums[idx++] = matrix[i][r];
        }
        r--;
        if (t <= b)
        {
            for (int i = r; i >= l; i--)
            {
                nums[idx++] = matrix[b][i];
            }
            b--;
        }
        if (l <= r)
        {
            for (int i = b; i >= t; i--)
            {
                nums[idx++] = matrix[i][l];
            }
            l++;
        }
    }
    *returnSize = m * n;
    return nums;
}

//方法二：向量控制加标记模拟
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = *matrixColSize;
    int i = 0, j = 0; 
    int* nums = malloc(sizeof(int) * m * n);
    *returnSize = m * n;
    int dx = 0, dy = 1;
    for (int idx = 0; idx < m * n; idx++)
    {
        nums[idx] = matrix[i][j];
        matrix[i][j] = INT_MAX;
        if (matrix[(i + dx + m) % m][(j + dy + n) % n] == INT_MAX)
        {
            int tmp = dy;
            dy = -dx;
            dx = tmp;
        }
        i += dx;
        j += dy;
    }
    return nums;
}

//方法三：向量控制
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = *matrixColSize;
    int size = m * n;
    int* nums = malloc(sizeof(int) * size);
    *returnSize = 0;
    int i = 0, j = -1;
    int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int id = 0; *returnSize < size; id = (id + 1) % 4)
    {
        for (int k = 0; k < n; k++)
        {
            i += DIRS[id][0];
            j += DIRS[id][1];
            nums[(*returnSize)++] = matrix[i][j];
        }
        int tmp = n;
        n = m - 1;
        m = tmp;
    }
    return nums;
}
