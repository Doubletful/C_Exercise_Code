#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//题⽬描述：
	//已知1瓶汽⽔1元，2个空瓶能换1瓶汽⽔，输⼊一个整数n元钱(n >= 0)，计算能喝多少汽⽔

	//方法一
	int n = 0;
	//记录共喝汽水数
	int total = 0;
	//记录空瓶数
	int empty = 0;
	scanf("%d", &n);
	//第一次喝的汽水数
	total += n;
	//第一次产出的空瓶数
	empty += n;
	//剩余空瓶数不能兑换汽水
	while (empty >= 2)
	{
		//每次喝的汽水数
		total += empty / 2;
		//每次产出的空瓶数
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);

	//方法二
	int m = 0;
	//记录共喝汽水数
	int sum = 0;
	scanf("%d", &m);
	//钱为0的情况
	if (m == 0)
		sum = 0;
	else
		//当有两个空瓶时，一个空瓶能换一瓶汽水
		sum = 2 * m - 1;
	printf("%d\n", sum);

	return 0;
}
