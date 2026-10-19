#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//求字符串长度的函数
size_t Strlen(const char* p)
{
	//递到p指向\0
	if (*p == '\0')
	{
		return 0;
	}
	//每次递入时都将p加1(递入字符串长度从头减1)
	//每次递入时都记录p被加的次数(即为字符串长度)
	return 1 + Strlen(p + 1);
}

int main()
{
	//题⽬描述：
	//写⼀个函数Strlen，可以求字符串⻓度，除了函数的形参，函数中不能使⽤多余的变量。
	//输⼊⼀个字符串(字符串⻓度⼩于等于30，中间包含空格)，使⽤Strlen函数求字符串的⻓度

	char string[31] = { 0 };
	scanf("%[^\n]s", string);
	printf("%zu\n", Strlen(string));
	
	return 0;
}
