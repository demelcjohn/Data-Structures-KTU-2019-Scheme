#include <stdio.h>
#define MAX_SIZE 50

int a[MAX_SIZE],top=-1;

void push(int );
void pop();
void disp();

int main()
{
    int x,choice;
    printf("Stack Operations\n");
    printf("1. Push an element to stack\n");
    printf("2. Pop an element from the stack\n");
    printf("3. Display elements of stack\n");
    printf("4. Exit\n");
    do{
    printf("Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the element : ");
            scanf("%d",&x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
    }
    printf("\n");
    }while(choice<4);
    return 0;
}

void push(int x)
{
    if(top==MAX_SIZE-1)
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    a[++top]=x;
}

void pop()
{
    if(top==-1)
    {
        printf("Error: No element to pop\n");
        return ;
    }
    printf("Element %d popped\n",a[top]);
    top--;
    
}

void disp()
{
    printf("Stack : \n");
    for(int i=0;i<=top;++i)
        printf("%d ",a[i]);
    printf("\n");
}



