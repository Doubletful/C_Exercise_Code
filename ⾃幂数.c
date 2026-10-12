#include <stdio.h>
#include <math.h>

int main11()
{
	//题⽬描述：
	//写⼀个代码打印1~100000之间的所有的⾃幂数，中间⽤空格分隔。

	for (int i = 1; i <= 100000; i++)
	{
		//记录i的位数
		int n = 0;
		int temp = i;
		//计算i的位数
		while (temp)
		{
			n++;
			temp /= 10;
		}
		//记录i每一位数的i的位数幂的和
		int sum = 0;
		temp = i;
		//计算i每一位数的i的位数幂的和
		while (temp)
		{
			//使⽤pow函数求某个数的次⽅数
			sum += (int)pow(temp % 10, n);
			temp /= 10;
		}
		if (sum == i)
		{
			//i为自幂数打印
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;

}
