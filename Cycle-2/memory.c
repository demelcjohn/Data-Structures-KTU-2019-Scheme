#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int maxd;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
int cur;

struct node* GetNode();
void display();
void allocate();
void deallocate();

int main()
{
    int x,n,choice;
    printf("Memory Allocater\n");
    printf("Enter number of memory blocks available : ");
    scanf("%d", &n);
    cur = n;
    struct node *p = NULL;
    printf("Enter %d memory block sizes\n", n);
    for (int i = 0; i < n; i++)
    {
        struct node *new;
        new = GetNode();
        printf("Enter block size: ");
        scanf("%d", &x);
        new->data = x;
        new->maxd = x;
        new->prev = p;
        if (head == NULL)
            head = new, p = new;
        else
            p->next = new, p = new;
    }
        printf("1. Allocate memory block\n");
        printf("2. Deallocate memory blocks and collect garbage\n");
    do{
        printf("Enter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            allocate();
            break;
        case 2:
            deallocate();
            break;
        }

    } while (choice<3);
}


struct node*GetNode()
{
struct node *ptr;
ptr = (struct node*)malloc(sizeof(struct node));
ptr->prev = NULL;
ptr->next = NULL;
return ptr;
}

void display()
{
    struct node *ptr = head;
    printf("The memory available are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void allocate()
{
int x,flag=0;
struct node *ptr;
printf("Enter the memory to be allocated : ");
scanf("%d",&x);
ptr = head;
while(ptr!=NULL)
{
	if(ptr->data>=x)
	{
		ptr->data = ptr->data-x;
		flag = 1;
		break;
	}
	ptr = ptr->next;
}
if(flag==0)
	printf("Not available memory\n");

else
	printf("Allocated\n");
display();
}

void deallocate()
{
int x,flag=0;
struct node *ptr;
printf("Enter the memory to be deallocated : ");
scanf("%d",&x);
ptr = head;
while(ptr!=NULL)
{
	if(ptr->maxd-ptr->data>=x)
	{
	ptr->data = ptr->data + x;
	flag = 1;
	break;
	}
	ptr = ptr->next;
}
if(flag==0)
	printf("Cannot be deallocated\n");

else
	printf("Successfully deallocated\n");
display();

}

	
	
	

