#include<stdio.h>

int b[100]={0};

void paixu(int *a,int sta,int mid,int end1) //排序 
{
	int i=sta,j=mid+1,k=sta;
	while(i<mid+1&&j<end1+1)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
		
		}
		
			while(j!=end1+1)
			{
				b[k++]=a[j++];
			}
			while(i!=mid+1)
			{
				b[k++]=a[i++];
			}
			
			for(i=sta;i<=end1;i++)
			  a[i]=b[i];
	}


void MergeSort(int *a,int start,int end) //递归 
{
	if(start<end)
	{
		MergeSort(a,start,(start+end)/2);
		MergeSort(a,(start+end)/2+1,end);
		paixu(a,start,(start+end)/2,end);
	}
}


main()
{
	int a[100],n,i;
	printf("输入你想输入数字的个数\n") 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	MergeSort(a,0,n-1);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
