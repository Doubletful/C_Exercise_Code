#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    //题目描述：
    //输入一个整数n，使用*打印对应n行的空心正方形图案，每个*后带有一个空格

    int n = 0;
    scanf("%d", &n);
    //打印行
    for (int i = 0; i < n; i++)
    {
        //打印列
        for (int j = 0; j < n; j++)
        {
            //打印顶行和底行，打印顶行判断条件，打印底行判断条件
            if (i == 0 || i == n - 1)
                //将"* "作为一个打印单位
                printf("* ");
            //打印左列和右列，打印左列判断条件，打印右列判断条件
            else if (j == 0 || j == n - 1)
                printf("* ");
            else
                //打印空格时将"  "作为一个打印单位，与单位"* "匹配
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}
