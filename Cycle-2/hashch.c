#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Node{
    int data;
    struct Node* link;
};


struct Node* getNode();
void Insert(struct Node* [],int,int);
void Display(struct Node* []);

void main(){
    struct Node* H[SIZE];
    for(int i=0;i<SIZE;i++)
          H[i] = NULL;

    int choice,index,key;
    printf("\nHash Table using Chaining Method\n");
    printf("1. Add element to HashTable\n");
    printf("2. Display the HashTable\n");
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&key);
                index = (key%SIZE);
                Insert(H,index,key);
                break;
            case 2:
                Display(H);
                break;
        }
    }while(choice<3);
}



struct Node* getNode(){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        printf("Memory overflow\n");
        return NULL;
    }
    p->link = NULL;
    p->data = -1;
    return p;
}

void Insert(struct Node* H[],int index , int key){

    if(H[index]==NULL){
            struct Node* new = getNode();
            H[index]=getNode();
            H[index]->link = new;
            new->data = key;
            return;
    }
    struct Node* ptr = H[index]->link;
    struct Node* temp = getNode();

    while(ptr !=NULL){
        if(ptr->data==key){
            printf("Element exists\n");
            return;
        }
        temp = ptr;
        ptr = ptr->link;
    }
    struct Node* new = getNode();
    temp->link = new;
    new->data = key;
}

void Display(struct Node* H[]){
    printf("Value   Linked\n");
    struct Node* ptr;
    for(int i=0;i<SIZE;i++){
        printf("%d  => ",i);
        if(H[i]==NULL){
            printf("\n");
            continue;
        }
        ptr = H[i]->link;
        while(ptr !=NULL){
            printf("%d=> ",ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}





