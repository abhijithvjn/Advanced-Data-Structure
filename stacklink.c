#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
int data;
struct node*next;
};
struct node*ptr=NULL;
struct node*top=NULL;
struct node*temp=NULL;
void main()
{
int opt;
do
{
printf("\nEnter your choice \n 1.push \n 2.pop \n 3.display \n 4.exit \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
}
}
while(opt!=4);
}
void push()
{
struct node*new=NULL;
new=(struct node*)malloc(sizeof(struct node*));
printf("Enter the data to be pushed \n");
scanf("\n%d",&new->data);
new->next=top;
top=new;
}
void pop()
{
struct node*ptr;
if(top==NULL)
{
printf("stack is empty\n");
}
else
{
printf("the item to be popped %d \n",top->data);
ptr=top;
top=top->next;
free(ptr);
}
}
void display()
{
struct node*temp;
if(top==NULL)
{
printf("stack is empty\n");
}
else
{
temp=top;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
}
