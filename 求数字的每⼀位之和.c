#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//题⽬描述：
	//输⼊⼀个整数m，求这个整数m的每⼀位之和，并打印。

	int m = 0;
	//存储m每一位的和
	int sum = 0;
	scanf("%d", &m);
	while (m)
	{
		sum += m % 10;
		m /= 10;
	}
	printf("%d\n", sum);

	return 0;
}
