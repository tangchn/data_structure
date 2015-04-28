#include <stdio.h>

#define MAXSIZE 13
void fibonacci(int *f)
{
	int i;
	f[0] = 1;
	f[1] = 1;
    printf("%d %d ", f[0],f[1]);
	for(i = 2;i < MAXSIZE;++i)
    {
		f[i] = f[i - 2] + f[i - 1];
		printf("%d ", f[i]);
    }
    printf("\n");
}
int fibonacci_search(int *a,int key,int n)
{
	int i;
	int low = 0,high = n - 1;
	int mid = 0;
	int k = 0;
	int F[MAXSIZE];
	printf("斐波拉契数列为：");
	fibonacci(F);
	while(n > F[k] - 1) //计算出n在斐波那契中的数列
		++k;
	for(i = n;i < F[k] - 1;++i) //把数组补全
		a[i] = a[high];
	while(low <= high)
	{
		mid = low + F[k-1] - 1;  //根据斐波那契数列进行黄金分割
		if(a[mid] > key)
		{
			high = mid - 1;
			k = k - 1;
		}
		else if(a[mid] < key)
		{
			low = mid + 1;
			k = k - 2;
		}
		else{
			if(mid <= high) //如果为真则找到相应的位置
				return mid;
			else
				return -1;
		}
	}
	return -1;
}
int main()
{

	int a[MAXSIZE] = {5,15,19,20,25,31,38,41,45,49,52,55,57};
	int k;
	printf("请输入要查找的数字:\n");
	scanf("%d",&k);
	int pos = fibonacci_search(a,k,13);
	if(pos != -1)
		printf("在数组的第%d个位置找到元素:%d\n",pos + 1,k);
	else
		printf("未在数组中找到元素:%d\n",k);
	return 0;
}
