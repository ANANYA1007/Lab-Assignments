#include<stdio.h>
#include<stdlib.h>
#define N 52
int deque[N];
int front=-1;
int rear=-1;
void insertfront(int x)
{if((front==rear+1)||(front==0&&rear==N-1))
printf("full space");
else if(front==-1&&rear==-1)
{front=rear=0;
deque[front]=x;}
else if(front==0)
{front=N-1;
deque[front]=x;}
else
{front=front-1;
deque[front]=x;};
};
void insertlast(int x)
{if((front==rear+1)||(front==0&&rear==N-1))
printf("full space");
else if(front==-1&&rear==-1)
{front=rear=0;
deque[rear]=x;}
else if(rear==N-1)
{rear=0;
deque[rear]=x;}
else
{rear=rear+1;
deque[rear]=x;};};
void deletefront()
{if(front==-1&&rear==-1)
printf("nothing left");
else if(front==N-1)
{
printf("deleted element is %d",deque[front]);
front=0;}
else if(front==rear)
{printf("deleted element is %d",deque[front]);
front=rear=-1;}
else
{printf("deleted element is %d",deque[front]);
front=front+1;};};
void deletelast()
{if(front==-1&&rear==-1)
printf("nothing left");
else if(rear==0)
{
printf("deleted element is %d",deque[rear]);
rear=N-1;}
else if(front==rear)
{printf("deleted element is %d",deque[rear]);
front=rear=-1;}
else
{printf("deleted element is %d",deque[rear]);
rear=rear-1;};};
int getfront()
{return(deque[front]);};
int getlast()
{return(deque[rear]);};
int isfull()
{if((front==rear+1)||(front==0&&rear==N-1))
return(1);
else
return(0);};
int isempty()
{if(front==-1&&rear==-1)
return(1);
else
return(0);};
int main()
{int n,i,a,choice,card,front_card,last_card,m,j;
printf("enter the no. of cards you initially want to have");
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("enter a no. between 1 to 52");
scanf("%d",&a);
if(a>=1&&a<=N)
insertfront(a);
else
printf("invalid card no.");};
printf("\n1.add card at front");
printf("\n2.add card at last");
printf("\n3.draw front");
printf("\n4.draw last");
printf("\n5.peek front");
printf("\n6.peek last");
printf("\n7.is full");
printf("\n8.is empty");
printf("\nenter no.of operations");
scanf("%d",&m);
for(j=0;j<m;j++)
{printf("\n enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter card no.");
       scanf("%d",&card);
       if(card>=1&&card<=52)
       insertfront(card);
       else
       printf("invalid card number");
       break;
case 2:printf("enter card no.");
       scanf("%d",&card);
       if(card>=1&&card<=52)
       insertlast(card);
       else
       printf("invalid card number");
       break;
case 3:deletefront();
       break;
case 4:deletelast();
       break;
case 5:front_card=getfront();
       printf("front card is %d",front_card);
       break;
case 6:last_card=getlast();
       printf("last card is %d",last_card);
       break;
case 7:if(isfull())
       printf("yes");
       else
       printf("no");
       break;
case 8:if(isempty())
       printf("yes");
       else
       printf("no");
       break;
default:printf("invalid choice");
};
};

return(0);
}
