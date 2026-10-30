//LeetCode    88.合并两个有序数组

//方法一：两次遍历
void mergy(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
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
}

//方法二：一次遍历
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
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
