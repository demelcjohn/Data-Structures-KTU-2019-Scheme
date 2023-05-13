#include <stdio.h>
#define MAX_SIZE 3

int a[MAX_SIZE],front=-1,rear=-1;

int IsEmpty();
void Enqueue(int );
void Dequeue();
void disp();

int main()
{
    int x,choice;
    printf("Queue Operations\n");
    printf("1. Insert an element to queue\n");
    printf("2. Delete an element from queue\n");
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

int IsEmpty()
{
    if(front==-1&&rear==-1)
        return 1;
    else 
        return 0;
}

void Enqueue(int x)
{
    if(rear==MAX_SIZE-1)
    {
        printf("Error : Queue is full\n");
        return;
    }
    if(IsEmpty())
        front=rear=0;
    else
        rear=rear+1;
    a[rear]=x;
}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("Error: No element to delete\n");
        return ;
    }
    printf("Element %d is deleted\n",a[front]);
    if(front==rear)
        front=rear=-1;
    else
        front=front+1;
}

void disp()
{
    if(IsEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue : \n");
    for(int i=front;i<=rear;++i)
        printf("%d ",a[i]);
    printf("\n");
}

