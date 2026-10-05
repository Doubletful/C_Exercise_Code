#include <stdio.h>
#include <math.h>

int main3()
{
	//题⽬描述：
	//使⽤C语⾔写⼀个程序打印100~200之间的素数，数字中间使⽤空格分割

	//方法一
	//遍历100~200之间的数字
	for (int i = 100; i <= 200; i++)
	{
		//记录是否为素数的标志
		int flag = 1;
		//排除偶数
		if (i % 2)
		{
			//从2~i-1递增试除i
			for (int j = 2; j <= i - 1; j++)
			{
				if (i % j == 0)
				{
					//能被其中一个数整除更改标志
					flag = 0;
				}
			}
			if (flag)
			{
				printf("%d ", i);
			}
		}
	}
	printf("\n");

	//方法二(优化)
	//遍历100~200之间的奇数
	for (int i = 101; i <= 200; i += 2)
	{
		//记录是否为素数的标志
		int flag = 1;
		//从2~根号i递增试除i
        for (int j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				//能被其中一个数整除更改标志
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;

}

