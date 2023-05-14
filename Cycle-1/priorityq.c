# include <stdio.h>
# define MAX_SIZE 101

struct {
	int element;
	int priority;
}P_queue[MAX_SIZE];
int front=-1,rear=-1; 

int IsEmpty();
int IsFull();
void Enqueue(int,int);
void Dequeue();
void disp();

void main()
{
    int x,p,choice;
    printf("Priority Queue\n");
    printf("1. Insert an element to priority queue\n");
    printf("2. Delete an element from priority queue\n");
    printf("3. Display elements of priority queue\n");
    printf("4. Exit\n");
    do{
    printf("Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element and priority (in order): ");
            scanf("%d",&x);
            scanf("%d",&p);
            Enqueue(x,p);
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
}

int IsEmpty()
{
    return front==-1;
}

int IsFull()
{
	return (rear+1)%MAX_SIZE==front;
}

void Enqueue(int x,int p)
{
	int flag=0;
    if(IsFull())
    {
        printf("Error : Queue is full\n");
        return;
    }
    if(IsEmpty())
    {
        front=rear=0;
        P_queue[rear].element=x;
    	P_queue[rear].priority=p;
	}
    else
    {
	for(int i=front;i!=rear;i=(i+1)%MAX_SIZE)
		if(p<P_queue[i].priority)
		{
			for(int j=rear;j!=i;--j)
			{
				if(j==-1)
					j=MAX_SIZE-1;
				P_queue[(j+1)%MAX_SIZE]=P_queue[j];
			}
			P_queue[(i+1)%MAX_SIZE]=P_queue[i];
			P_queue[i].element=x;
			P_queue[i].priority=p;
			flag=1;
			break;
		}
	if(flag==0)
	{
		if(p<P_queue[rear].priority)
		{
			P_queue[(rear+1)%MAX_SIZE]=P_queue[rear];
			P_queue[rear].element=x;
			P_queue[rear].priority=p;
		}
		else
		{
			P_queue[rear+1].element=x;
			P_queue[rear+1].priority=p;		
		}
	}
	rear=(rear+1)%MAX_SIZE;
    }
 

}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("Error: No element to delete\n");
        return ;
    }
    printf("Element %d is deleted\n",P_queue[front].element);
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX_SIZE;
}


void disp()
{    if(IsEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (priority in brackets): \n");
    for(int i=front;i!=rear;i=(i+1)%MAX_SIZE)
        printf("%d(%d) ",P_queue[i].element,P_queue[i].priority);
    printf("%d(%d) \n",P_queue[rear].element,P_queue[rear].priority);
}













