#include<stdio.h>
#include<stdlib.h>
#define N 52
struct node
{struct node* prev;
struct node* next;
int card;};
struct node* front=NULL;
struct node* rear=NULL;

void insertfront(int x)
{struct node* newcard;
newcard=(struct node*)malloc(sizeof(struct node));
newcard->card=x;
newcard->next=NULL;
newcard->prev=NULL;
if(isfull())
 printf("full space");
 else if(front==NULL&&rear==NULL)
 {front=rear=newcard;}
 else
 {front->prev=newcard;
 newcard->next=front;
 front=newcard;}
 };
 void insertlast(int x)
{struct node* newcard;
newcard=(struct node*)malloc(sizeof(struct node));
newcard->card=x;
newcard->next=NULL;
newcard->prev=NULL;
if(isfull())
 printf("full space");
 else if(front==NULL&&rear==NULL)
 {front=rear=newcard;}
 else
 {rear->next=newcard;
 newcard->prev=rear;
 rear=newcard;}
 };
 void deletefront()
 {if(front==NULL&&rear==NULL)
 printf("nothing left");
 else
 {struct node* temp;
 temp=front;
 printf("\ndeleted card is %d",front->card);
 front=front->next;
 front->prev=NULL;
 free(temp);};
 };
 void deletelast()
 {if(front==NULL&&rear==NULL)
 printf("nothing left");
 else
 {struct node* temp;
 temp=rear;
 printf("\ndeleted card is %d",rear->card);
 rear=rear->prev;
 rear->next=NULL;
 free(temp);};
 };
 void getfront()
 {if(front==NULL)
 printf("totally empty");
 else
 {printf("\n%d",front->card);}
 };
 void getlast()
 {if(rear==NULL)
 printf("totally empty");
 else
 {printf("\n%d",rear->card);}
 };
 int isempty()
 {if(front==NULL&&rear==NULL)
 return(1);
 else
 return(0);};
 int isfull()
 {struct node* temp;
 temp=front;
 int count=0;
 while(temp!=NULL)
 {temp=temp->next;
  count=count+1;};
  if(count==N)
  return(1);
  else
  return(0);
  };
int main()
{struct node* front=NULL;
struct node* rear=NULL;
int n,i,a,m,j,choice,c;
printf("enter the no. of cards you have initially");
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("\nenter the card no.");
scanf("%d",&a);
if(a<=N&&a>=1)
insertfront(a);
else
printf("\ninvalid card no.");
};
printf("\n1.insert card at front");
printf("\n2.insert card at last");
printf("\n3.draw front");
printf("\n4.draw last");
printf("\n5.peek front");
printf("\n6.peek last");
printf("\n7.is full");
printf("\n8.is empty");
printf("\nenter the no. of operations");
scanf("%d",&m);
for(j=0;j<m;j++)
{printf("\nenter your choice");
scanf("%d",&choice);
switch(choice)
{case 1:printf("enter the card no.");
        scanf("%d",&c);
        if(c<=N&&c>=1)
        insertfront(c);
        else
        printf("invalid card no.");
        break;
case 2:printf("enter the card no.");
        scanf("%d",&c);
        if(c<=N&&c>=1)
        insertlast(c);
        else
        printf("invalid card no.");
        break;
case 3:deletefront();
       break;
case 4:deletelast();
       break;
case 5:getfront();
        break;
case 6:getlast();
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


