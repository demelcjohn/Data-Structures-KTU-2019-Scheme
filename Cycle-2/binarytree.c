#include <stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *LLink;
struct node *RLink;
};
struct node *Root = NULL,*temp = NULL;
int flag; 

struct node*GetNode();
void InsertNode(int);
struct node*SearchNode(struct node*,int);
void InorderTrav(struct node *);
void PredoderTrav(struct node*);
void PostorderTrav(struct node*);
struct node *DeleteNode(struct node*,int);
void ReturnNode(struct node*);

void main(){

int choice,x;
printf("\nBinary Tree using Linked List\n");
l:
printf("1. Insert a new node\n");
printf("2. Inorder traversal\n");
printf("3. Preorder traversal\n");
printf("4. Post order traversal\n");
printf("5. Delete a node\n");
do{
printf("(6 to reprint menu||other to exit)\n");
printf("Enter the choice : ");
scanf("%d",&choice);
switch(choice){
	case 1:
		printf("Enter the element : ");
		scanf("%d",&x);
		InsertNode(x);
		break;
	case 2:
		printf("Inorder Traversal\n");
		InorderTrav(Root);
		break;
	case 3:
		printf("Preorder Traversal\n");
		PredoderTrav(Root);
		break;
	case 4:
		printf("Postorder Traversal\n");
		PostorderTrav(Root);
		break;
	case 5:
		printf("Enter the element to be deleted : ");
		scanf("%d",&x);
		flag = 0;
		DeleteNode(Root,x);
		if(flag)
			printf("Successfully deleted\n");
		else
			printf("Not possible\n");
		break;
	case 6:
		goto l;
	default:
		printf("\n.....\n");
}
printf("\n\n");
}while(choice<=6);
printf("Thank You\n\n");
}


struct node*GetNode()
{
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Memory overflow!!!\nProgram crashed\n");
		exit(0);
	}
	ptr->LLink = NULL;
	ptr->RLink = NULL;
	return ptr;
}

void InsertNode(int x)
{
	if(Root==NULL){
		Root = GetNode();
		Root->data = x;
		return;
	}
	struct node *ptr,*new;
	int key;
	printf("Enter the parent : ");
	scanf("%d",&key);
	ptr = SearchNode(Root,key);
	if(ptr==NULL){
		printf("key not present\n");
		return;
	}
	if(ptr->LLink==NULL){
		new = GetNode();
		ptr->LLink = new;
		new->data = x;
	}
	else if(ptr->RLink==NULL){
		new = GetNode();
		ptr->RLink = new;
		new->data = x;
	}
	else
		printf("Not possible\n");
}

struct node*SearchNode(struct node *p,int key)
{
	struct node *ptr=NULL;
	if(p->data!=key){
		if(p->LLink!=NULL){
			ptr = SearchNode(p->LLink,key);
			if(ptr!=NULL)
				return ptr;
			}
		else 
			return NULL;
		if(p->RLink!=NULL){
			ptr = SearchNode(p->RLink,key);
			if(ptr!=NULL)
				return ptr;
			}
		else 
			return NULL;
	}
	else
	{
		return p;
	}
}

void InorderTrav(struct node* ptr)
{
	if(ptr!=NULL)
	{
		InorderTrav(ptr->LLink);
		printf("%d ",ptr->data);
		InorderTrav(ptr->RLink);
	}
}

void PredoderTrav(struct node* ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		PredoderTrav(ptr->LLink);
		PredoderTrav(ptr->RLink);
	}
}

void PostorderTrav(struct node* ptr)
{
	if(ptr!=NULL)
	{
		PostorderTrav(ptr->LLink);
		PostorderTrav(ptr->RLink);
		printf("%d ",ptr->data);
	}
}

struct node* DeleteNode(struct node* ptr,int x)
{
	if(ptr!=NULL)
	{
		ptr->LLink = DeleteNode(ptr->LLink,x);
		ptr->RLink = DeleteNode(ptr->RLink,x);
		if(ptr->LLink==NULL&&ptr->RLink==NULL&&ptr->data==x){
			temp = ptr;
			ReturnNode(temp);		
			ptr = NULL;
			flag = 1;
			return NULL;
		}
		return ptr;
	}
	else
		return NULL;

}

void ReturnNode(struct node *ptr)
{
	free(ptr);
	ptr=NULL;
}
























