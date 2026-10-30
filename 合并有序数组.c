#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//将有序数组nums2合并到有序数组nums1中，结果保持数组nums1升序排序

//void mergy(数组1, 数组1大小, 数组1有效数字, 数组2, 数组2大小, 数组2有效数字)
void mergy(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	//方法一
	 //目标数组有效数字的最后一个下标
	int sum = m + n - 1;
	//nums1有效数字的最后一个下标
	int p1 = m - 1;
	//nums2有效数字的最后一个下标
	int p2 = n - 1;
	//依次从后比较nums1和nums2的最大值，并依次从后给目标数组赋值
	//当某一数组的有效数字被完全拷贝后结束
	while (p1 >= 0 && p2 >= 0)
	{
		if (nums1[p1] > nums2[p2])
			nums1[sum--] = nums1[p1--];
		else
			nums1[sum--] = nums2[p2--];
	}
	//将未被完全拷贝的数组依次从后给目标数组赋值
	//因为nums1为合并后的目标数组，当nums1未被完全拷贝时，目标数组中已存在nums1的未拷贝值，
	//且已是升序顺序，所以只额外处理nums2未完全拷贝的情况
	while (p2 >= 0)
	{
		nums1[sum--] = nums2[p2--];
	}

	//方法二
	sum = m + n - 1;
	p1 = m - 1;
	p2 = n - 1;
	//从后向前遍历目标数组的有效数字
	while (sum >= 0)
	{
		//每次判断nums1和nums2被遍历到的位置，数组未完成遍历时，根据下标查找对应值
		//当某一数组完成遍历时，每次将代表该数组值的变量赋值为目标数组中不存在的最小值
		int numA = p1 < 0 ? INT_MIN : nums1[p1];
		int numB = p2 < 0 ? INT_MIN : nums2[p2];
		//比较对应值并依次从后给目标数组赋值其较大值
		//当某一数组完成遍历时，代表该数组值的变量将比另一数组中未赋值的值都小
		if (numA > numB)
			nums1[sum--] = nums1[p1--];
		else
			nums1[sum--] = nums2[p2--];
	}
}

int main()
{
	//题⽬描述：
	//输⼊两个升序排列的序列，将两个序列合并为⼀个升序序列并输出。输⼊包含三⾏，
	//第⼀⾏包含两个正整数n, m，⽤空格分隔。n表⽰第⼆⾏第⼀个升序序列中数字的个数，
	//m表⽰第三⾏第⼆个升序序列中数字的个数。其中1 <= n <= 30, 1 <= m <= 30
	//第⼆⾏包含n个整数，⽤空格分隔。第三⾏包含m个整数，⽤空格分隔。
	//输出为⼀⾏，输出⻓度为n + m的升序序列，
	//即⻓度为n的升序序列和⻓度为m的升序序列中的元素重新进⾏升序序列排列合并。

	int arr1[30] = { 0 };
	int arr2[30] = { 0 };
	//arr1和arr2合并后的数组
	int arr3[60] = { 0 };
	//arr1数组的元素个数
	int n = 0;
	//arr2数组的元素个数
	int m = 0;
	//接收n, m并判断有效输入
	while (1)
	{
		scanf("%d%*c%d", &n, &m);
		if (1 <= n && n <= 30 && 1 <= m && m <= 30)
			break;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr2[i]);
	}
	//记录arr3被遍历到的位置
	int i = 0;
	//记录arr1和arr2被拷贝到的位置
	int p1 = 0;
	int p2 = 0;
	//将arr1和arr2中的元素升序拷贝到arr3
	//arr1或arr2完全拷贝到arr3后结束
	while (p1 < n && p2 < m)
	{
		//比较arr1和arr2中的元素，先拷贝较小值
		if (arr1[p1] < arr2[p2])
			//拷贝并将拷贝到的数组指向的位置加1
			arr3[i++] = arr1[p1++];
		else
			arr3[i++] = arr2[p2++];
	}
	//arr1中的元素已全部完成拷贝，拷贝arr2中未拷贝的较大值
	if (p1 == n)
	{
		//arr2完全拷贝到arr3后结束
		while (p2 < m)
		{
			arr3[i++] = arr2[p2++];
		}
	}
	//arr2中的元素已全部完成拷贝，拷贝arr1中未拷贝的较大值
	if (p2 == m)
	{
		//arr1完全拷贝到arr3后结束
		while (p1 < n)
		{
			arr3[i++] = arr1[p1++];
		}
	}
	for (int j = 0; j < n + m; j++)
	{
		printf("%d ", arr3[j]);
	}
	printf("\n");

	return 0;
}

