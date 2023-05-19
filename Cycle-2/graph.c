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
int data;
struct visit *link;
};

struct node*GetNode();
struct node*InsertGraph(int,struct node*);
struct Edge*GetEdge();
void addAdjVe();
void adjMat();
void displaygraph();
void DFS();
void BFS();

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
displaygraph();
addAdjVe();
adjMat();
displaygraph();
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

}

void BFS()
{

}












