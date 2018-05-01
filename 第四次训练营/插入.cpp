#include<stdio.h>

void InsertSort(int *a,int n) //由小到大排序 
{
	int i=1,temp,j,k; //temp记录插入的数字，j记录插入的位置，k用于循环比较； 
	for(i;i<n;i++) 
	{
		if(*(a+i-1)>*(a+i))
		  {
		  	
		  	temp=*(a+i);
		  	*(a+i)=*(a+i-1);
		  	
		  	
		  	j=0;            
		  	while(*(a+j)<temp)
		  	{
		  		j++;
			  }
			  
			  
			k=i-1;
			for(k;k>j;k--)
			{
				*(a+k)=*(a+k-1);
			}
			*(a+k)=temp;
			
		  }
	}
}

main()
{
	int a[100],n,i=0;
	printf("输入你想输入几个数\n");
	scanf("%d",&n); 
	printf("输入这些个数，用空格隔开\n"); 
	
	for(i;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	InsertSort(a,n);
	
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	scanf("%d",&n); 
}

