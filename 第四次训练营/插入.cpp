#include<stdio.h>

void InsertSort(int *a,int n) //��С�������� 
{
	int i=1,temp,j,k; //temp��¼��������֣�j��¼�����λ�ã�k����ѭ���Ƚϣ� 
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
	printf("�����������뼸����\n");
	scanf("%d",&n); 
	printf("������Щ�������ÿո����\n"); 
	
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

