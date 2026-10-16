#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//交换两个整数的函数
void Swap(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main15()
{
	//题⽬描述：
	//写⼀个函数Swap，可以交换两个整数的内容。注意必须实现成函数完成。
	//输⼊2个整数，调⽤⾃定义函数Swap，完成2个整数的交换。

	int a = 0;
	int b = 0;
	scanf("%d%*c%d", &a, &b);
	Swap(&a, &b);
	printf("%d %d", a, b);

	return 0;
}
