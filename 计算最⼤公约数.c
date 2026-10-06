#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main5()
{
	//题⽬描述：
	//输⼊2个整数m和n，计算m和n的最⼤公约数，并打印出结果

	//方法一
	int m = 0;
	int n = 0;
	int max = 0; //最大公约数
	scanf("%d%*c%d", &m, &n);
	//从两值的较小值到1递减分别试除m和n
	for (int i = (m > n ? n : m); i >= 1; i--)
	{
		//能同时整除两数
		if (m % i == 0 && n % i == 0)
		{
			max = i;
			break;
		}
	}
	printf("%d\n", max);

	//方法二
	int o = 0;
	int p = 0;
	int q = 0; //储存辗转相除法的余数
	scanf("%d%*c%d", &o, &p);
	//辗转相除法余数为0停止循环
	while (q = o % p)
	{
		//让上次计算的除数做被除数，余数做除数
		o = p;
		p = q;
	}
	printf("%d\n", p);

	return 0;
}
