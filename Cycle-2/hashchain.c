#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node {
int data;
struct node*link;
};

struct node *HEADER[SIZE] = {NULL};

void Insert();
void Search();
void Display();

void main() {
    int choice;
	printf("\nHash Table using Chaining Method\n");
        printf("1. Insert into the table \n");
        printf("2. Search in the table \n");
        printf("3. Display the contents");
        do{
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1: Insert();
            break;
            case 2: Search();
            break;
            case 3: Display();
            break;
        }
    }
    while(choice<=3);
}


void Insert() {
    int i,key;
    struct node *new,*ptr,*ptr1;

    printf("\n Enter the value : ");
    scanf("%d",&key);
    i = key%SIZE;

    ptr = HEADER[i];
    ptr1 = ptr;
    while(ptr != NULL){
        	if(ptr->data==key)
        	{
        		printf("Not possible\n");
        		return;
        	}
        	ptr1 = ptr;
        	ptr = ptr->link;
        }
    new = (struct node*)malloc(sizeof(struct node));
    new->data = key;
    new->link = NULL;
    ptr1->data = key;
}

void Search() {
    int key,index;
    struct node *ptr ;
    printf("\n Enter the element to be searched for: ");
    scanf("%d",&key);
    index = key%SIZE;

    if(HEADER[index] == NULL)
        printf("\n The element searched is not present");

    else {
        for(ptr = HEADER[index];ptr != NULL;ptr = ptr->link) {
            if(ptr->data == key) {
                printf("\n The searched element is found");
                break;
            }
        }
        if(ptr == NULL)
            printf("\n The searched element is not found");
    }    
}

void Display() {
    int i;
    struct node *ptr;
    for(i=0;i<SIZE;i++) {
        printf("\n Entries at index %d: ",i);
        if(HEADER[i] == NULL)
            printf(" No hash entry");

        else {
            for(ptr = HEADER[i];ptr != NULL;ptr = ptr->link)
                printf(" %d-> ",ptr->data);
        }    
    }
}

	
	

