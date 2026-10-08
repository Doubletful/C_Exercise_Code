#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main6()
{
	//题⽬描述：
	//输⼊2个整数m和n，计算m和n的最⼩公倍数，并打印出结果

	//方法一
	int m = 0;
	int n = 0;
	scanf("%d%*c%d", &m, &n);
	int bigger = (m > n ? m : n); //两值的较大值
	int smaller = (m < n ? m : n); //两值的较小值
	//从两值的较大值到两值乘积递增，递增差值为两值的较大值
	for (int i = bigger; i <= m * n; i+=bigger)
	{
		//试除较小值找最小公倍数
		if (i % smaller == 0)
		{
			printf("%d\n", i);
			break;
		}
	}

	//方法二
	int o = 0;
	int p = 0;
	int q = 0; //储存辗转相除法的余数
	scanf("%d%*c%d", &o, &p);
	int mul = o * p; //两值乘积
	//辗转相除法余数为0停止循环
	while (q = o % p)
	{
		//让上次计算的除数做被除数，余数做除数
		o = p;
		p = q;
	}
	//两值乘积除两值的最大公约数等于两值的最小公倍数
	printf("%d\n", mul / p);

	return 0;
}
