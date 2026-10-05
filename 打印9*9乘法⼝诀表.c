#include <stdio.h>

int main2()
{
	//题⽬描述：
	//使⽤C语⾔写⼀个程序打印9 * 9乘法⼝诀表

	//外层循环控制行数
	for (int i = 1; i < 10; i++)
	{
		//内层循环控制每行的列数
		for (int j = 1; j <= i; j++)
		{
			//打印乘法口诀表的格式
			printf("%d*%d=%2d ", i, j, i * j);
		}
		//每打印一轮换行
		printf("\n");
	}

	return 0;

}
