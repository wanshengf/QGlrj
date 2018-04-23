#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 10

typedef enum
{
    FALSE=0, TRUE=1
} Status;

//循环队列结构
typedef struct Aqueue        	
{
    void *data[MAXQUEUE];  	//数据域
    int front;
    int rear;
	size_t data_size;		//数据域内存大小
} AQueue;

void InitAQueue(AQueue *Q) //初始化操作 
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

void DestoryAQueue(AQueue *Q) //销毁 
{
	free(Q);
}

Status EnAQueue(AQueue *Q, void *data)  //入队函数 
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

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int z)) //遍历+打印 
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

 void APrint(void *q,int z) //打印  其中int z 为判断输出的数据类型 
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
    printf("请输入你想输入的数据类型：int ,double , char ,\n");
    
    char s[10];
    gets(s);
    if(s[0]=='i')  //判断输入的数据类型 
      t->data_size=sizeof(int);
    else if(s[0]=='c')
      t->data_size=sizeof(char);
    else
      t->data_size=sizeof(double);
	printf("已经帮你初始化队列\n"); 	
	InitAQueue(t);   //初始化队列 
	
	void (*w)(void *,int); //使指针指向APrint(void *q,int z)  
	w=APrint;
	int j,k=0;
	if(s[0]=='i')  // 选择输出的数据类型. 
		{
			int l[10];   //入队的数组、 
			printf("请输入你想入队多少个数\n");
			scanf("%d",&j);
			if(j>10||j<=0) printf("输入错误");  //判断输入的数的个数是否在函数实现的范围内 
			else           
			{			
			printf("请输入你要入队的数字\n每个数字用回车键隔开\n");			 
			
			for(;k<j;k++) //输入你想输入的数字 
			{
				scanf("%d",&l[k]);
			}
			int *r=l;
	        printf("入队成功\n"); 
	        for(i=0;i<j;i++)  //入队操作 
	          EnAQueue(t,r++);
	        
			printf("\n");
	        printf("队列中的数字如下：\n");	        
			TraverseAQueue(t,w);  //打印+遍历操作 
		    }
		}
		else if(s[0]=='c')
		{
			char l[11]={'0'};
			printf("请输入你想入队的个数并且再加一位\n");
			scanf("%d",&j);
			printf("请输入你要入队的数字\n");
			if(j>11||j<=1) printf("输入错误");
			else 
			{ 
			  for(k=0;k<j;k++)
			  {
			  	scanf("%c",&l[k]);
			  }
			  char *r=l;
	          printf("入队成功\n"); 
	          for(i=0;i<j;i++)
	            EnAQueue(t,r++);
	          printf("队列中的数字如下：\n");
	          TraverseAQueue(t,w);
	         }
		}
		else
		{
			double l[10];
			printf("请输入你想入队多少个数\n");
			scanf("%d",&j);
			printf("请输入你要入队的数字\n");
			if(j>10||j<=0) printf("输入错误"); 
			for(;k<j;k++)
			{
				scanf("%lf",&l[k]);
			}
			double *r=l;
	        printf("入队成功\n"); 
	        for(i=0;i<j;i++)
	          EnAQueue(t,r++);
	        printf("\n");
	        printf("队列中的数字如下：\n");
	        TraverseAQueue(t,w);
	
		}
	DestoryAQueue(t);	
	return 0;
}
 
