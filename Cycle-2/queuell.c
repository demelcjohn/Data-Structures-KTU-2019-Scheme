#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *link;
};
struct node *front=NULL,*rear=NULL;

int IsEmpty();
void Enqueue(int );
void Dequeue();
void disp();

int main()
{
    int x,choice;
    printf("Queue using Linked List\n");
    printf("1. Enqueue an element to queue\n");
    printf("2. Dequeue an element from queue\n");
    printf("3. Display elements of queue\n");
    printf("4. Exit\n");
    do{
    printf("Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element : ");
            scanf("%d",&x);
            Enqueue(x);
            break;
        case 2:
            Dequeue();
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
	return front==NULL && rear ==NULL;
}

void Enqueue(int x)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node*));
    temp->data =  x;
    temp->link = NULL;
    if(IsEmpty())
    {
    	front = rear = temp;
    	return;
    }
    rear->link =temp;
    rear = temp;
}

void Dequeue()
{
	struct node* temp;
	if(IsEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	temp = front;
	if(front == rear)
		front=rear=NULL;
	else
		front =front->link;
	free(temp);
	temp = NULL;
}

void disp()
{
	struct node* temp;
    if(IsEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("Queue\n");
    while(temp!=NULL)
    {
    	printf("%d ",temp->data);
    	temp = temp->link;
    }
    printf("\n");
}

