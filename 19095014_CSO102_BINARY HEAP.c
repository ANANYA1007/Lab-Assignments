#include<stdio.h>
#include<math.h>



void exchange(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;

};


 void main()
{int n,k,i=0,m,b,j,s,max,z;
printf("enter the maximum no. of elements");
scanf("%d",&n);
if(n>=1&&n<=100000)
{
int a[n];
int heap[n];
int queue[n];
for(k=0;k<n;k++)
{printf("\nenter a positive no.  ");
scanf("%d",&m);
if(m>0&&m<=100000)
{
a[i]=m;
j=i;

while(j>0)
{if(a[j]>a[(j-1)/2])
exchange(&a[j],&a[(j-1)/2]);
j=(j-1)/2;
};
printf("heap array:");
for(b=0;b<=i;b++)
{printf("\t%d",a[b]);
heap[b]=a[b];
};
int rear=0;
int l;
int x=i;
for(z=0;z<=i;z++)
{

  if(i<=1)
  {
       max=heap[0];
         heap[0]=heap[i];
         queue[rear]=max;
        rear=rear+1;

  }
   int j=0;

   if(i>1)
   {max=heap[0];
   heap[0]=heap[x];
    x=x-1;
   queue[rear]=max;
    rear=rear+1;

   while(2*j+1<=x&&2*j+2<=x)
   {
    if(heap[2*j+1]>heap[2*j+2])
   {
       exchange(&heap[0],&heap[2*j+1]);
       j=2*j+1;
   }
   else if(heap[2*j+1]==heap[2*j+2])
   {
      heap[0]=heap[2*j+1];
       break;
   }
   else
   {
       exchange(&heap[0],&heap[2*j+2]);
       j=2*j+2;
   }

   };
   }
   if(z==i)
   { int product=1;
     int top=0;
     if(i<=1)
        printf("\nproduct=-1");
        else
        {
            for(l=0;l<=2;l++)
            {
              product=product*queue[top];
              top=top+1;
            }
             printf("\nproduct of top 3 no.=%d",product);
        }


   };


}
i=i+1;
}

else
    printf("\nenter a positive no. less than 100000");
}
}
else
    printf("\ntoo many no. of operations");

}


