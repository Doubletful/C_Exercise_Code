#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main4()
{
	//题⽬描述：
	//输⼊三个整数a, b, c，判断由a, b, c作为三条边组成的三⻆形，如果不能组成三⻆形则输出：
	//⾮三⻆形；如果是三⻆形，再继续判断，如果是等边三⻆形，则输出：等边三⻆形；
	//如果是等腰三⻆形，则输出：等腰三⻆形；否则输出普通三⻆形

	//方法一
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%*c%d%*c%d", &a, &b, &c);
	//判断是否构成三角形，两边之和大于第三边
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		printf("非三角形\n");
	}
	//判断等边三角形
	else if (a == b && b == c)
	{
		printf("等边三角形\n");
	}
	//判断等腰三角形
	else if (a == b || a == c || b == c)
	{
		printf("等腰三角形\n");
	}
	else
	{
		printf("普通三角形\n");
	}

	//方法二
	int d = 0;
	int e = 0;
	int f = 0;
	scanf("%d%*c%d%*c%d", &d, &e, &f);
	//判断是否构成三角形，两边之和大于第三边
	if (d + e > f && d + f > e && e + f > d)
	{
		//判断等边三角形
	    if (d == e && e == f)
	    {
		printf("等边三角形\n");
	    }
	    //判断等腰三角形
	    else if (d == e || d == f || e == f)
	    {
	    	printf("等腰三角形\n");
	    }
	    else
	    {
	    	printf("普通三角形\n");
	    }
	}
	else
	{
		printf("非三角形\n");
	}

	return 0;
}
