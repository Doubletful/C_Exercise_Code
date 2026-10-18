#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//求两个整数平均值的函数
int average(int m, int n)
{
	//m + (n - m) / 2 -> (2m + n - m) / 2 == (m + n) / 2
	//当n大于m时，(n - m)的正差值除2加较小值等于平均数
	//当n小于m时，(n - m)的负差值除2加较大值等于平均数
	return m + (n - m) / 2;
}

int main()
{ 
	//题⽬描述：
	//输⼊2个整数m和n，写⼀个函数average，求2个整数的平均值，考虑整数过⼤溢出的问题。

	int m = 0;
	int n = 0;
	scanf("%d%*c%d", &m, &n);
	int avg = average(m, n);
	printf("%d\n", avg);

	return 0;
}
