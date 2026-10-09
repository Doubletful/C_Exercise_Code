#include <stdio.h>

int main7()
{
	//题⽬描述:
	//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 - … + 1 / 99 - 1 / 100的值，并打印出结果

	//记录运算结果
	double sum = 0.0;
	//从1~100递增除数i
	for (int i = 1; i <= 100; i++)
	{
		//i为奇数时相加
		if (i % 2 == 1)
		{
			sum += 1.0 / i;
		}
		else //i为偶数时相减
		{
			sum -= 1.0 / i;
		}
	}
	printf("%lf\n", sum);

	return 0;
}
