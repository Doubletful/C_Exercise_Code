#include <stdio.h>

int main1()
{
    //1.1 题⽬描述：
    //使⽤C语⾔写⼀个程序打印1~100之间的奇数，要求输出的数字中间加上空格

	//方法一
	for (int i = 1; i <= 100; i++) //限制范围
	{
		//取余最小偶数求奇数
		if (i % 2 == 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	
	//方法二
	 //限制范围，累加奇数差值求奇数
	for (int i = 1; i <= 100; i += 2)
	{
		printf("%d ", i);
	}
	printf("\n");

	return 0;
	
}
