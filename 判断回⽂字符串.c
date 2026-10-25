#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main20()
{
	//题⽬描述：
	//输⼊⼀个字符串，判断这个字符串是否是回⽂字符串(字符串的⻓度⼩于等于30，
	//字符串不包含空格)，如果是回⽂字符串输出Yes，如果不是回⽂字符串输出No。

	char string[31] = { 0 };
	//假设输入字符串是回文字符串
	int flag = 1;
	scanf("%s", string);
	//定义两个指针变量分别指向第一个和最后一个字符
	char* left = string;
	char* right = string + strlen(string) - 1;
	//双向遍历到完成对应字符比较
	while (left <= right)
	{
		//对应字符不同修改标志
		if (*left != *right)
		{
			flag = 0;
		}
		left++;
		right--;
	}
	if (flag)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}

	return 0;
}
