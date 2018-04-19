#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;//��¼��ջ����
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStack;

Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top=(StackNode*) malloc(sizeof(StackNode));
	s->top->next=NULL;
	s->top->data=-1;
	s->count=0;
	return OK;
}

Status LStackLength(LinkStack *s,int *length)    //���������
{
	if(s==NULL||s->top==NULL)
	return ERROR;
	*length=s->count;
	return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
{
	if(s==NULL||s->top==NULL)
	return ERROR;
	LinkStackPtr p1;
	p1=(LinkStackPtr) malloc(sizeof(StackNode));
	p1->next=s->top;
	p1->data=datas;
	s->top=p1;
	s->count++;
	return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //��ջ
{
	if(NULL==s||s->top==NULL)
	return ERROR;
	StackNode *p1;
	p1=(StackNode*) malloc(sizeof(StackNode));
	p1=s->top->next;
	*datas=s->top->data;
	s->top=p1;
	s->count--;
	return OK;
}

int main()
{
	printf("��������������������#������\n");
	printf("���磺9+8#\n"); 
	Status initLStack(LinkStack *s);  //��ʼջ 
	Status pushLStack(LinkStack *s,ElemType datas); //��ջ 
	Status popLStack(LinkStack *s,ElemType *datas);//��ջ
	Status LStackLength(LinkStack *s,int *length);
	LinkStack *t;
	t=(LinkStack*) malloc(sizeof(LinkStack));
	initLStack(t);
	char a[50],b[50];
	gets(a);    
	int i=0,j=0; //ѭ��ʹ��
	int len,e;   
	
	for(i=0;a[i]!='#';i++)  //��׺ת��׺���ʽ 
	{
		if(a[i]>='0'&&a[i]<='9')    
		{
			b[j]=a[i];
			j++;
		}
		else if(a[i]=='*'||a[i]=='/'||a[i]=='(')
		     {
		     	pushLStack(t,a[i]);
			 }
			 else if(a[i]=='+'||a[i]=='-')
			      {
			      	LStackLength(t,&len);
			      	if(len==0) 
			      	{
			      		pushLStack(t,a[i]);
			      		continue;
					  }
					popLStack(t,&e);
					if(e=='+'||e=='-')
					{
						pushLStack(t,e);
						pushLStack(t,a[i]);
						continue;
					}
					if(e=='*'||e=='/')
					{
						b[j]=e;
						j++;
						LStackLength(t,&len);
						while(len)
						{
							popLStack(t,&e);
							b[j]=e;
							j++;
							LStackLength(t,&len);
						}
						pushLStack(t,a[i]);
						continue;
					}
					while(e!='(')
					{
						b[j]=e;
						j++;
						LStackLength(t,&len);
						if(len!=0) popLStack(t,&e);
					}
					if(e=='(')
					{
						pushLStack(t,e);
						pushLStack(t,a[i]);
					}
				  }
				  else if (a[i]==')')
				        {
				        	LStackLength(t,&len);
							popLStack(t,&e);
				        	while(e!='(')
				        	{
				        		b[j]=e;
				        		j++;
				        		LStackLength(t,&len);
								popLStack(t,&e);
							}
							if(len==0)
							{
								printf("ERROR");
								break; 
							}
							
						}
						else {
							printf("ERROR");
						
						}
						
	 } 
	 LStackLength(t,&len);
	 while(len)
	 {
	 	popLStack(t,&e);
	 	b[j]=e;
	 	j++;
	 	len--;
	 }
	b[j]='\0';
	
	int c1=0,c2=0; //���ּ��� 
	int sum=0;
	for(i=0;i<j;i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		  {
		  	pushLStack(t,b[i]);
		  }
		  else if(b[i]=='+'||b[i]=='-')
		       {
		       	  popLStack(t,&c1);
		       	  popLStack(t,&c2);
		       	  c1=c1-'0';
		       	  c2=c2-'0';
		       	  if(b[i]=='+')
		       	    sum=c2+c1;
		       	  else 
		       	      sum=c2-c1;
		       	    sum=sum+'0';
		       	  pushLStack(t,sum);
			   }
			   else if(b[i]=='*'||b[i]=='/')
			        {
			        	popLStack(t,&c1);
		       	        popLStack(t,&c2);
		       	        c1=c1-'0';
		       	        c2=c2-'0';
		       	        if(b[i]=='*')
		       	            sum=c1*c2;
		       	            else sum=c2*1.0/c1*1.0;
		       	        sum=sum+'0';
		       	        pushLStack(t,sum);
					}
	 } 
	
	popLStack(t,&sum);
	sum=sum-'0';
	printf("%d",sum);
	return 0;
	
}
