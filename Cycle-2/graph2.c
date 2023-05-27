#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *Dlink;
struct Edge *Rlink;
}*Head = NULL;

struct Edge{
struct node *vlink;
struct Edge *RL;
};

struct visit{
int ele;
struct visit *next;
}*Vhead;

struct stack{
struct node *addr;
struct stack *link;
}*top = NULL;

struct queue{
struct node *addr;
struct queue *link;
}*front = NULL ,*rear = NULL;

struct node*GetNode();
struct node*InsertGraph(int,struct node*);
struct Edge*GetEdge();
void addAdjVe();
void adjMat();
void displaygraph();
void DFS();
void BFS();
void InsertEnd_SL(int);
int Search_SL(int);
void push(struct node *);
struct node*pop();
struct stack*Istop();
void enqueue(struct node *);
struct node*dequeue();
struct queue*qstatus();

void main()
{
char c='y';
int x;
struct node *ptr;
printf("\nGraph\n");
Head = GetNode();
ptr = Head;
do{
printf("Enter vertex : ");
scanf("%d",&x);
ptr = InsertGraph(x,ptr);
printf("Do you want to continue : ");
scanf("\n%c",&c);
}while(c!='n');
addAdjVe();
printf("Adjacency Matrix\n");
adjMat();
printf("Adjacency list\n");
displaygraph();
Vhead = (struct visit*)malloc(sizeof(struct visit));
Vhead->next = NULL;
DFS();
free(Vhead);
Vhead = NULL;
Vhead = (struct visit*)malloc(sizeof(struct visit));
Vhead->next = NULL;
BFS();
printf("\n");
}

struct node*GetNode()
{
struct node *ptr = (struct node *)malloc(sizeof(struct node));
ptr->Dlink = NULL;
ptr->Rlink = NULL;
return ptr;
}

struct node* InsertGraph(int x,struct node *ptr)
{
int n,y;
struct node *new;
new = GetNode();
ptr->Dlink = new;
new->data = x;
return new;
}

struct Edge*GetEdge()
{
struct Edge *ptr = (struct Edge *)malloc(sizeof(struct Edge));
ptr->vlink = NULL;
ptr->RL = NULL;
return ptr;
}

void addAdjVe()
{
char c;
int n;
struct node *ptr,*ptr1;
struct Edge *ptr2,*new,*temp;
ptr = Head->Dlink;
while(ptr!=NULL)
{
ptr2 = GetEdge();
temp = ptr2;
printf("Vertex %d\n",ptr->data);
printf("Do the vertex has edges pointing : ");
scanf("\n%c",&c);
while(c!='n'){
	printf("Elements pointed : ");
	scanf("%d",&n);
	ptr1 = Head->Dlink;
	while(ptr1!=NULL)
	{
		if(ptr1->data==n)
		{
			new = GetEdge();
			new->vlink = ptr1;
			ptr2->RL = new;
			ptr2 = ptr2->RL;
			break;
		}	
		ptr1 = ptr1->Dlink;	
	}
	printf("Do you want to continue : ");
	scanf("\n%c",&c);
}
ptr->Rlink = temp->RL;
free(temp);
temp = NULL;
ptr = ptr->Dlink;
}

}

void adjMat()
{
struct node *ptr,*ptr1;
struct Edge *ptr2;
int n;
ptr = Head->Dlink;
while(ptr!=NULL)
{
	ptr1 = Head->Dlink;
	while(ptr1!=NULL)
	{
		ptr2 = ptr->Rlink;
		n = 0;
		while(ptr2!=NULL)
		{
			if(ptr2->vlink->data == ptr1->data)
			{
				n =1;
				break;
			}
			ptr2 = ptr2->RL;
		}
		printf("%d ",n);
		ptr1 = ptr1->Dlink;
	}
	ptr = ptr->Dlink;
	printf("\n");
}
}

void displaygraph()
{
struct node *ptr = Head->Dlink;
struct Edge *ptr1 = NULL;
while(ptr!=NULL)
{
	printf("%d -> ",ptr->data);
	ptr1 = ptr->Rlink;
	while(ptr1!=NULL)
	{
		printf("%d ",ptr1->vlink->data);
		ptr1 = ptr1->RL;
	}
	printf("\n");
	ptr = ptr->Dlink;
}
printf("\n");
}

void DFS()
{
struct node *ptr = Head->Dlink;
struct Edge *ptr1 = NULL;
printf("Depth First Search\n");
push(ptr);
while(Istop()!=NULL)
{
	ptr = pop();
	if(Search_SL(ptr->data)==0)
	{
		InsertEnd_SL(ptr->data);
		printf("%d ",ptr->data);
		ptr1 = ptr->Rlink;
		while(ptr1!=NULL)
		{
			push(ptr1->vlink);
			ptr1 = ptr1->RL;
		}
	}
}
printf("\n");
}

void BFS()
{
struct node *ptr = Head->Dlink;
struct Edge *ptr1 = NULL;
printf("Breadth First Search\n");
enqueue(ptr);
while(qstatus()!=NULL)
{
	ptr = dequeue();
	if(Search_SL(ptr->data)==0)
	{
		InsertEnd_SL(ptr->data);
		printf("%d ",ptr->data);
		ptr1 = ptr->Rlink;
		while(ptr1!=NULL)
		{
			enqueue(ptr1->vlink);
			ptr1 = ptr1->RL;
		}
	}
}
printf("\n");
}

void InsertEnd_SL(int x)
{
struct visit *new,*ptr = Vhead;
while(ptr->next!=NULL)
	ptr = ptr->next;
new = (struct visit*)malloc(sizeof(struct visit));
new->ele = x;
ptr->next = new;
new->next =NULL;
}

int Search_SL(int x)
{
struct visit *ptr = Vhead->next;
while(ptr!=NULL)
{
if(ptr->ele==x)
	return 1;
ptr = ptr->next;
}
return 0;
}

void push(struct node *ptr)
{
struct stack * temp = (struct stack *)malloc(sizeof(struct stack*));
temp->addr =  ptr;
temp->link = top;
top = temp;
}

struct node*pop()
{
	struct stack* temp;
	temp = top;
	top = top->link;
	return temp->addr;
	
}


struct stack* Istop()
{
return top;
}

void enqueue(struct node *ptr)
{
	struct queue * temp = (struct queue *)malloc(sizeof(struct queue*));
	temp->addr =  ptr;
	temp->link = NULL;
	if(rear==NULL)
	{
	    	front = rear = temp;
	    	return;
	}
	rear->link =temp;
	rear = temp;
}

struct node*dequeue()
{
	struct queue* temp;
	temp = front;
	if(front == rear)
		front=rear=NULL;
	else
		front =front->link;
	return temp->addr;
}

struct queue*qstatus()
{
	return rear;
}







