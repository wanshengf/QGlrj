#include<stdio.h>
#include<math.h>

int z=0;  //����z+1λ 

void CountSort(int *a,int n)
{
	int b[10]={0},c[10],j=0,x,q;  //x ��ʾ�ڼ�λ�����֣�����321�ڶ�λ x=2; ����b�洢 z+1λ�����֣�����c�洢���֣�q����ѭ��ʹ�� 
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
	printf("�������������뼸������\n"); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int max=a[0];
	for(i=1;i<n;i++) //������������������������ 
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	
	int t=0;
	while(max) //�ó���Ҫ���ü��κ��� 
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
