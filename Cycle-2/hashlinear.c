#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node{
int data;
int flag;
}h[SIZE];

void Insert();
void Search();
void Display();

void main()
{
    int choice;
    for(int i=0;i<SIZE;++i)
    	h[i].flag = 0;
 	printf("Hash Table using Linear Probing for collision resolution\n");
        printf("1. Insert into the table \n");
        printf("2. Display the contents \n");
        printf("3. Search any element\n");
        do{
        printf("\n Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Insert();
                break;
            case 2:
                Display();
                break;
            case 3:
                Search();
                break;
        }
    }
    while(choice<=3);
}

void Insert()
{
    int key,index,i,hkey;
    printf("\nEnter a value : ");
    scanf("%d",&key);
    hkey=key%SIZE;
    for(i=0;i<SIZE;i++) 
    {
        index=(hkey+i)%SIZE;
        if(h[index].data == key){
        printf("Not possible\n");
        break;}
        if(h[index].flag == 0)
        {
            h[index].data=key;
            h[index].flag=1;
            break;
        }

    }

    if(i == SIZE)
        printf("\nElement cannot be inserted\n");
}

void Search()
{

 int key,index,i,hkey;
 printf("\nEnter the element to be searched : ");
 scanf("%d",&key);
 hkey=key%SIZE;
 for(i=0;i<SIZE; i++)
 {
    index=(hkey+i)%SIZE;
    if(h[index].data==key)
    {
      printf("value is found at index %d",index);
      break;
    }
  }
  if(i == SIZE)
    printf("\n value is not found\n");
}

void Display()
{

  int i;
  printf("\nelements in the hash table are \n");
  for(i=0;i< SIZE; i++)
  {
  printf("\n Index %d ,",i);
  if(h[i].flag ==1) 
  	printf("Value =  %d",h[i].data);
  else
  	printf("Value = empty");
}
}
	
	
	

