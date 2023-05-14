#include <stdio.h>
#define MAX_SIZE 101

int Dequeue[MAX_SIZE];
int front = -1;
int rear = -1;
int no_ele = 0;

int IsEmpty();
int IsFull();
void Frt_Enqueue(int);
void Rr_Enqueue(int);
void Frt_Dequeue();
void Rr_Dequeue();
void disp();


void main()
{
	int x,choice;
	printf("Dequeue\n");
	printf("1. Insert element to the Front of the queue\n");
	printf("2. Insert element to the Rear of the queue\n");
	printf("3. Delete element from the Front of the queue\n");
	printf("4. Delete element from the Rear of the queue\n");
	printf("5. Display the dequeue\n");
	do{
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
		case 1:
			printf("Enter the element: ");
                	scanf("%d",&x);
                	Frt_Enqueue(x);
                	break;
            	case 2:
               	 printf("Enter the element: ");
               	 scanf("%d",&x);
               	 Rr_Enqueue(x);
               	 break;
          	case 3:
               	 Frt_Dequeue();
               	 break;
           	case 4:
               	 Rr_Dequeue();
               	 break;
            	case 5:
               	 disp();
               	 break;
        }
        disp();
        printf("\n");
    }while(choice<6);
}


int IsEmpty()
{
    if(front==-1&&rear==-1)
        return 1;
    else 
        return 0;
}

int IsFull()
{
    if(no_ele==MAX_SIZE)
        return 1;
    else 
        return 0;
}

void Frt_Enqueue(int x)
{
	if (IsFull())
	{
	        printf("Error! Queue is full\n");
	        return;
        }
        no_ele++;
    	if (IsEmpty())
    	{
        	front = rear = MAX_SIZE/2;
        	Dequeue[front] = x;
    	}
    	else
    	{
    		if (front == 0)
         	  	front = MAX_SIZE-1;
        	else
         		front--;
        	Dequeue[front] = x;
    	}
}

void Rr_Enqueue(int x)
{
	if (IsFull())
	{
	        printf("Error! Queue is full\n");
        	return;
    	}
    	no_ele++;
   	if (IsEmpty())
   	{
   		front = rear = MAX_SIZE/2;
        	Dequeue[rear] = x;
    	}
    	else
    	{
	        rear = (rear+1)%MAX_SIZE;
        	Dequeue[rear] = x;
    	}
}

void Frt_Dequeue()
{
	int ele;
	if (IsEmpty())
	{
        	printf("The queue is empty\n");
        	return;
    	}
    	ele=Dequeue[front];
    	if (front == rear)
        	front = rear = -1;
    	else
        	front = (front+1)%MAX_SIZE;
    	printf("The element %d is deleted\n",ele);
    	no_ele--;
}

void Rr_Dequeue()
{
	int ele;
    	if (IsEmpty())
    	{
        	printf("The queue is empty\n");
        	return;
    	}
     	ele = Dequeue[rear];
    	if (front == rear)
        	front = rear = -1;
    	else
    	{
        	if (rear==0)
        		rear = MAX_SIZE-1;
        	else
            		rear--;
    	}
    	printf("The element %d is deleted\n",ele);
    	no_ele--;
}

void disp()
{
	if(IsEmpty())
	{
		printf("The queue is empty\n");
		return;
	}
	printf("Dequeue : \n");
	for(int i=front;i!=rear;i=(i+1)%MAX_SIZE)
		printf("%d ",Dequeue[i]);
	printf("%d\n",Dequeue[rear]);
}













