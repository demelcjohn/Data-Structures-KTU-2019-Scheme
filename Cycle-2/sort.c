#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

void display(int [MAX_SIZE],int);
void copy(int [MAX_SIZE],int [MAX_SIZE],int);
void insertionsort(int [MAX_SIZE],int);
void selectionsort(int [MAX_SIZE],int);
void heapsort(int [MAX_SIZE],int);
void mergesort(int [MAX_SIZE],int,int);
void quicksort(int [MAX_SIZE],int,int);
void CreateHeap(int[MAX_SIZE],int);
void RemoveHeap(int[MAX_SIZE],int,int);
void merge(int[MAX_SIZE],int,int,int);
int partition(int[MAX_SIZE],int,int);
void swap(int*,int*);

void main()
{
FILE *p;
int n,size = -1,a[MAX_SIZE],b[MAX_SIZE],choice;
printf("Sorting Techniques\n");
p = fopen("numbers.txt","r");
printf("Numbers coping from file...\n");
printf("File : ");
while(1){
	fscanf(p,"%d\n",&n);
	printf("%d ",n);
	a[++size] = n;
	if(feof(p))
		break;
}
size++;
printf("\n1. Insertion sort\n");
printf("2. Selection sort\n");
printf("3. Heap sort\n");
printf("4. Merge sort\n");
printf("5. Quick sort\n");
do{
copy(a,b,size);
printf("Enter the choice : ");
scanf("%d",&choice);
switch(choice)
{
	case 1:
		printf("Insertion Sort\n");
		insertionsort(b,size);
		break;
	case 2:
		printf("Selection Sort\n");
		selectionsort(b,size);
		break;
	case 3:
		printf("Heap Sort\n");
		heapsort(b,size);
		break;
	case 4:
		printf("Merge Sort\n");
		mergesort(b,0,size-1);
		break;
	case 5:
		printf("Quick Sort\n");
		quicksort(b,0,size-1);
		break;
}
display(b,size);
printf("\n");
}while(choice < 6);
printf("\n");
}

void display(int a[MAX_SIZE],int s)
{
printf("Array : ");
for(int i=0;i<s;++i)
	printf("%d ",a[i]);
printf("\n");
}

void copy(int a[MAX_SIZE],int b[MAX_SIZE],int s)
{
for(int i=0;i<s;++i)
	b[i] = a[i];

}


void insertionsort(int b[MAX_SIZE],int s)
{
int j,pos,temp;;
for(int i=1;i<s;++i)
{
	for(j=i-1;j>=0;--j)
		if(b[i]>b[j])
			break;
	pos = j+1;
	temp = b[i];
	for(j=i;j>pos;--j)
		b[j] = b[j-1];
	b[pos] = temp;
}
}

void selectionsort(int b[MAX_SIZE],int s)
{
for(int i=0;i<s-1;++i)
{
	for(int j=i+1;j<s;++j)
	{
		if(b[i]>b[j])
			swap(&b[i],&b[j]);
	}
}
}


void heapsort(int b[MAX_SIZE],int s)
{
CreateHeap(b,s);
for(int i=0;i<s-1;++i)
{
	swap(&b[0],&b[s-i-1]);
	RemoveHeap(b,s,i);
}
}


void mergesort(int b[MAX_SIZE],int l,int r)
{
if(r<=l)
	return;
int mid = (l+r)/2;
mergesort(b,l,mid);
mergesort(b,mid+1,r);
merge(b,l,mid,r);
}


void quicksort(int b[MAX_SIZE],int low,int high)
{
int left = low,right = high,loc;
if(left<right)
{
loc = partition(b,left,right);
quicksort(b,left,loc-1);
quicksort(b,loc+1,right);
}
}

void CreateHeap(int b[MAX_SIZE],int s)
{
int c[MAX_SIZE],j;
for(int i=0;i<s;++i)
{
c[i] = b[i];
j = i;
while(j>0)
{
	if(c[j]>c[(j-1)/2])
		swap(&c[j],&c[(j-1)/2]);
	else
		break;
	j = (j-1)/2;
}

}
copy(c,b,s);
}

void RemoveHeap(int b[MAX_SIZE],int s,int i)
{
int j=0;
while((j*2+2)<s-i-1)
{
	if((b[j]<b[(j*2)+1])&&(b[(j*2)+1]>=b[(j*2)+2]))
	{
		swap(&b[j],&b[(j*2)+1]);
		j = (j*2)+1;
	}
	else if(b[j]<b[(j*2)+2])
	{
		swap(&b[j],&b[(j*2)+2]);
		j = (j*2)+2;
	}
	else
		break;
}
}

void merge(int b[MAX_SIZE],int l,int mid,int r)
{
int i=l,j = mid+1,c[MAX_SIZE],k = -1;
while(i<=mid && j<=r)
{
	if(b[i]<=b[j])
		c[++k] = b[i++]; 	
	else
		c[++k] = b[j++];
} 
for(;j<=r;++j)
	c[++k] = b[j];
for(;i<=mid;++i)
	c[++k] = b[i];
for(k=0,i=l;i<=r;++k,++i)
	b[i] = c[k];
}

int partition(int b[MAX_SIZE],int left,int right)
{
int loc = left;
while(left<right)
{	
	while((b[loc]<=b[right])&&(loc<right))
		right = right -1;
	if(b[loc]>b[right])
	{
		swap(&b[loc],&b[right]);
		loc = right;
		left = left+1;
	}
	while((b[loc]>=b[left])&&(loc>left))
		left = left + 1;
	if(b[loc]<b[left])
	{
		swap(&b[loc],&b[left]);
		loc = left;
		right = right-1;
	}
}
return loc;
}

void swap(int *x,int *y)
{
int temp;
temp = *x;
*x = *y;
*y = temp;
}





























