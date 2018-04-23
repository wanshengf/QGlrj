#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 10

typedef enum
{
    FALSE=0, TRUE=1
} Status;

//ѭ�����нṹ
typedef struct Aqueue        	
{
    void *data[MAXQUEUE];  	//������
    int front;
    int rear;
	size_t data_size;		//�������ڴ��С
} AQueue;

void InitAQueue(AQueue *Q) //��ʼ������ 
{
	int i=0;
	Q->front=0;
	Q->rear=0;
	if(Q->data_size==sizeof(int))
	{
		for(i;i<MAXQUEUE;i++)
	    {
		    Q->data[i]=malloc (sizeof(int));
	      }
	}
	else if(Q->data_size==sizeof(char))
	{
		for(i;i<MAXQUEUE;i++)
	    {
		    Q->data[i]=malloc (sizeof(char));
	      }
	}
	else 
	{
		for(i;i<MAXQUEUE;i++)
	    {
		    Q->data[i]=malloc (sizeof(float));
	      }
	}
}

void DestoryAQueue(AQueue *Q) //���� 
{
	free(Q);
}

Status EnAQueue(AQueue *Q, void *data)  //��Ӻ��� 
{
	
	if(Q->rear+1==Q->front||Q->front==0&&Q->rear==10) 
	{
		Q->rear=0;
		return FALSE;
	}
	
	Q->data[Q->rear]=data;
	if(Q->rear==MAXQUEUE-1) 
	{
		Q->rear=0;
	}
	else
	Q->rear++;
	return TRUE;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int z)) //����+��ӡ 
{
	if(Q->front<Q->rear)  
	{
		for(int i=Q->front;i<=Q->rear-1;i++)
		(*foo)(Q->data[i],Q->data_size);
	}
	else
	{
		for(int i=Q->front;i<=MAXQUEUE-1;i++)
		(*foo)(Q->data[i],Q->data_size);
		if(Q->rear!=Q->front)
		  for(int i=0;i<=Q->rear;i++)
		     (*foo)(Q->data[i],Q->data_size);
		else 
		  for(int i=0;i<Q->rear;i++)
		     (*foo)(Q->data[i],Q->data_size);
	}
	return TRUE;
}

 void APrint(void *q,int z) //��ӡ  ����int z Ϊ�ж�������������� 
 {
 	if(z==4)
 	{
 		printf("%d ",*(int *)q);
	 }
	 else if(z==1)
	 {
		printf("%c",*(char *)q);
	 }
	 else if(z==8)
	 {
	 	printf("%lf ",*(double *)q);
	 }
 }
 
  int main()
 {
    int n,i=0;
    
	Aqueue *t;
    t=(Aqueue *) malloc(sizeof(Aqueue));    
    printf("����������������������ͣ�int ,double , char ,\n");
    
    char s[10];
    gets(s);
    if(s[0]=='i')  //�ж�������������� 
      t->data_size=sizeof(int);
    else if(s[0]=='c')
      t->data_size=sizeof(char);
    else
      t->data_size=sizeof(double);
	printf("�Ѿ������ʼ������\n"); 	
	InitAQueue(t);   //��ʼ������ 
	
	void (*w)(void *,int); //ʹָ��ָ��APrint(void *q,int z)  
	w=APrint;
	int j,k=0;
	if(s[0]=='i')  // ѡ���������������. 
		{
			int l[10];   //��ӵ����顢 
			printf("������������Ӷ��ٸ���\n");
			scanf("%d",&j);
			if(j>10||j<=0) printf("�������");  //�ж���������ĸ����Ƿ��ں���ʵ�ֵķ�Χ�� 
			else           
			{			
			printf("��������Ҫ��ӵ�����\nÿ�������ûس�������\n");			 
			
			for(;k<j;k++) //����������������� 
			{
				scanf("%d",&l[k]);
			}
			int *r=l;
	        printf("��ӳɹ�\n"); 
	        for(i=0;i<j;i++)  //��Ӳ��� 
	          EnAQueue(t,r++);
	        
			printf("\n");
	        printf("�����е��������£�\n");	        
			TraverseAQueue(t,w);  //��ӡ+�������� 
		    }
		}
		else if(s[0]=='c')
		{
			char l[11]={'0'};
			printf("������������ӵĸ��������ټ�һλ\n");
			scanf("%d",&j);
			printf("��������Ҫ��ӵ�����\n");
			if(j>11||j<=1) printf("�������");
			else 
			{ 
			  for(k=0;k<j;k++)
			  {
			  	scanf("%c",&l[k]);
			  }
			  char *r=l;
	          printf("��ӳɹ�\n"); 
	          for(i=0;i<j;i++)
	            EnAQueue(t,r++);
	          printf("�����е��������£�\n");
	          TraverseAQueue(t,w);
	         }
		}
		else
		{
			double l[10];
			printf("������������Ӷ��ٸ���\n");
			scanf("%d",&j);
			printf("��������Ҫ��ӵ�����\n");
			if(j>10||j<=0) printf("�������"); 
			for(;k<j;k++)
			{
				scanf("%lf",&l[k]);
			}
			double *r=l;
	        printf("��ӳɹ�\n"); 
	        for(i=0;i<j;i++)
	          EnAQueue(t,r++);
	        printf("\n");
	        printf("�����е��������£�\n");
	        TraverseAQueue(t,w);
	
		}
	DestoryAQueue(t);	
	return 0;
}
 
