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

//方法二：方向向量
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int* nums = malloc(sizeof(int) * m * n);
    *returnSize = m * n;
    int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int id = 0;
    int i = 0, j = 0;
    for (int idx = 0; idx < m * n; idx++)
    {
        nums[idx] = matrix[i][j];
        matrix[i][j] = INT_MAX;
        int x = i + DIRS[id][0];
        int y = j + DIRS[id][1];
        if (x == m || y == n || x < 0 || y < 0 || matrix[x][y] == INT_MAX)
            id = (id + 1) % 4;
       i += DIRS[id][0];
       j += DIRS[id][1]; 
    }
    return nums;
}
