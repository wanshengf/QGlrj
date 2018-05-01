#include<stdio.h>
#include<math.h>

int z=0;  //进第z+1位 

void CountSort(int *a,int n)
{
	int b[10]={0},c[10],j=0,x,q;  //x 表示第几位的数字，例如321第二位 x=2; 数组b存储 z+1位的数字，数组c存储数字，q用于循环使用 
	for(int i=0;i<n;i++)
	{
		x=a[i]/(int)(pow(10,z))%10;
		b[x]++;
	}
	
	for(int i=0;i<n;i++)
	{
		while(b[j]==0)
		  j++;
		for(q=0;q<n;q++)
		{
			x=a[q]/(int)(pow(10,z))%10;
			if(j==x)
			{
			  	c[i]=a[q];
			  	a[q]=-32768;
			  	b[j]--;
				break;	
			}
		}
	}
	
	for(j=0;j<n;j++)
	{
		a[j]=c[j];
	}
	z++;
}

main()
{
	int a[10],n,i=0;
	printf("请输入你想输入几个数字\n"); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int max=a[0];
	for(i=1;i<n;i++) //遍历并查找数组中最大的数字 
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	
	int t=0;
	while(max) //得出需要调用几次函数 
	{
		max=max/10;
		t++;
	}
	
	for(i=1;i<=t;i++)
	{
		CountSort(a,n);
	 } 
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}	
}
