#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//逆序字符串的函数
char* reverse(char* p)
{
	//定义两个指针变量分别指向字符串的第一个和最后一个字符
	char* left = p;
	char* right = p + strlen(p) - 1;
	//双向遍历到完成字符串逆序
	while (left <= right)
	{
		//交换头指针和尾指针存储的值
		char c = *left;
		*left = *right;
		*right = c;
		left++;
		right--;
	}
	return p;
}

int main18()
{
	//题⽬描述：
	//输⼊⼀个字符串，写⼀个函数将⼀个字符串的内容逆序过来。

	char string[31] = { 0 };
	scanf("%[^\n]s", string);
	printf("%s\n", reverse(string));

	return 0;
}
