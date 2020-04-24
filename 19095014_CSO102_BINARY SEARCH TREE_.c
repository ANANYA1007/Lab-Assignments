#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char data[2];
struct node *left;
struct node *right;};
struct node *root=NULL;
void preorder(struct node *root)
{if(root!=NULL)
{
printf("%s",root->data);
preorder(root->left);
preorder(root->right);}
};
void inorder(struct node *root)
{if(root!=NULL)
{
inorder(root->left);
printf("%s",root->data);
inorder(root->right);}
};
void postorder(struct node *root)
{if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("%s",root->data);
}
};



void display(struct node *root)
{
if(root==0)
printf("empty tree");
else
{printf("\npreorder:");
preorder(root);
printf("\ninorder:");
inorder(root);
printf("\npostorder:");
postorder(root);
};
};

void declare(char *x)
{
struct node *n;
struct node *par=NULL;
n=(struct node*)malloc(sizeof(struct node));
n->left=NULL;
n->right=NULL;
strcpy(n->data,x);
if(root==NULL)
{root=n;
}
else
{par=root;
while(par!=NULL)
{
int cmp=strcmp(par->data,x);
 if(cmp>0)
{if(par->left==NULL)
{par->left=n;
break;}
par=par->left;}
else if(cmp<0)
{if(par->right==NULL)
{par->right=n;
break;}
par=par->right;
}
else if(cmp==0)
{printf("variable already exists");
break;}
}
}
};
struct node* findmax(struct node *root)
{
    struct node *temp;
    if(root->left==NULL&&root->right==NULL)
        temp=root;
    else if(root->right==NULL)
        temp=findmax(root->left);
    else if(root->right!=NULL)
        temp=findmax(root->right);
    return(temp);
};

struct node* delete(struct node *root,char *x)
{struct node *temp;
if(root==NULL)
    printf("no such element exists");
else{
int cmp;
cmp=strcmp(x,root->data);
 if(cmp<0)
    root->left=delete(root->left,x);
else if(cmp>0)
    root->right=delete(root->right,x);
else
{
    if(root->left&&root->right)
    {
        temp=findmax(root->left);
        strcpy(root->data,temp->data);
        root->left=delete(root->left,root->data);
    }
    else if(root->right==NULL&&root->left==NULL)
    {
         root=NULL;


    }
    else
    {

        temp=root;
        if(root->left==NULL)
            root=root->right;
        else if(root->right==NULL);
        root=root->left;
        free(temp);
        root=NULL;

    }
}

}
return(root);
}
void main()
{int m,choice,i;
char y[2];
struct node *a;
printf("enter the no. of operations");
scanf("%d",&m);
printf("\n1.INSERT");
printf("\n2.DISPLAY");
printf("\n3.DELETE");
for(i=0;i<m;i++)
{printf("\nenter your choice");
scanf("%d",&choice);
switch(choice)
{case 1:printf("\nenter the variable to be inserted");
        scanf("%s",y);
        declare(y);
        break;
case 2:display(root);
        break;
case 3: if(root==NULL)
         printf("nothing there!!");
         else{
         printf("enter the variable to be deleted");
        scanf("%s",y);
         a=delete(root,y);
         if(a==0)
            root=NULL;

         }
         break;
default:printf("invalid choice");
};
}
}
