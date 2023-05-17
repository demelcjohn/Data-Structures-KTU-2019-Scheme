#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *link;
};
struct node *top=NULL;

int IsEmpty();
void push(int );
void pop();
void disp();

int main()
{
    int x,choice;
    printf("Stack using Linked List\n");
    printf("1. Push an element to stack\n");
    printf("2. Pop an element from stack\n");
    printf("3. Display elements of stack\n");
    printf("4. Exit\n");
    do{
    printf("Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element : ");
            scanf("%d",&x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
    }
    disp();
    printf("\n");
    }while(choice<4);
    return 0;
}

int IsEmpty(){
	return top==NULL;
}

void push(int x)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node*));
    temp->data =  x;
    temp->link = top;
    top = temp;
}

void pop()
{
	struct node* temp;
	if(IsEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	temp = top;
	top = top->link;
	free(temp);
}

void disp()
{
	struct node* temp;
    if(IsEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    temp = top;
    printf("Stack\n");
    while(temp!=NULL)
    {
    	printf("%d ",temp->data);
    	temp = temp->link;
    }
    printf("\n");
}

