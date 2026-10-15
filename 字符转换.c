#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main14()
{
	//题⽬描述：
	//输⼊⼀个字符串，将字符串中⼤写字⺟全部转为⼩写字⺟，⼩写字⺟转为⼤写字⺟，
	//其它字符保持不变。注：字符串的⻓度⼩于等于30，其中字符串中包含空格。

	//方法一
	char string[31] = { 0 };
	//限制读入字符串的长度最大为30，遇到\n后停止读入
	scanf("%30[^\n]s", string);
	//遍历字符串依次判断每个字符的执行操作
	for (int i = 0; i < sizeof(string) / sizeof(string[0]); i++)
	{
		//大写字母转小写字母
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			string[i] += 32;
		}
		//小写字母转大写字母
		else if (string[i] >= 'a' && string[i] <= 'z')
		{
			string[i] -= 32;
		}
	}
	printf("%s\n", string);

	//方法二
	char buf[31] = { 0 };
	int i = 0;
	//限制读入字符串的长度最大为30，遇到\n后停止读入
	scanf("%30[^\n]s", buf);
	//遍历字符串依次判断每个字符的执行操作
	while (buf[i])
	{
		//isupper用于判断字符是否为⼤写字⺟
		if (isupper(buf[i]))
		{
			//tolower用于将字符转换为⼩写字⺟
			buf[i] = tolower(buf[i]);
		}
		//islower用于判断字符是否为⼩写字⺟
		else if (islower(buf[i]))
		{
			//toupper用于将字符转换为⼤写字⺟
			buf[i] = toupper(buf[i]);
		}
		i++;
	}
	printf("%s\n", buf);

	return 0;
}
