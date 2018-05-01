#include<stdio.h>

void QSort_Recursion(int *a,int start,int end) //��С�������� 
{
	int t=*(a+start),i=start,j=end;
	
	if(start>=end) return ;//��ֹ���� 
	
		while(i<j)    //����˼�� 
		{
			while(i<j&&a[j]>=t)
			{
				j--;
			}
			a[i]=a[j];
			
			while(i<j&&a[i]<=t)
			{
				i++; 
			}
			a[j]=a[i];
		}
		a[i]=t;
	

	QSort_Recursion(a,start,i-1);
	QSort_Recursion(a,i+1,end);
 } 
 
 main()
 {
 	int a[100],n,i;
 	printf("�����������������ֵĸ���\n"); 
 	scanf("%d",&n);
 	printf("�������֣��ÿո����"); 
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	 }
	QSort_Recursion(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
 	
 }
