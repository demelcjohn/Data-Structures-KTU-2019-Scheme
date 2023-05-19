#include <stdio.h>
#include <stdlib.h>

struct node{
float coef;
int exp;
struct node *link;
};
struct node *p1,*p2,*psum,*ppro;

struct node* GetNode();
void InputTerms(struct node*,int);
struct node* Multiply(struct node*,struct node*);
struct node* Add(struct node*,struct node*);
void display(struct node*);

void main()
{
int no_terms;
printf("Polynomial Operations using Linked List\n");
printf("Enter the 2 polynomials\n");
printf("Polynomial 1\n");
printf("Enter the number of terms of polynomial 1 : ");
scanf("%d",&no_terms);
p1 = GetNode();
InputTerms(p1,no_terms);
display(p1);
printf("Polynomial 2\n");
printf("Enter the number of terms of polynomial 2 : ");
scanf("%d",&no_terms);
p2 = GetNode();
InputTerms(p2,no_terms);
display(p2);
printf("Product of polynomials\n");
ppro = Multiply(p1,p2);
display(ppro);
printf("Sum of polynomials\n");
psum = Add(p1,p2);
display(psum);
}

struct node* GetNode(){
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	if(p==NULL){
	printf("Memory Overflow\n");
	exit(0);
	}
	p->link=NULL;
	return p;
}

void InputTerms(struct node *p,int n){
	struct node *new,*ptr;
	int e;
	float c;
	printf("Enter the terms\n(Coefficient Exponent)\n");
	ptr = p;
	for(int i=0;i<n;++i){
		scanf("%f",&c);
		scanf("%d",&e);
		new=GetNode();
		ptr->link = new;
		new->coef = c;
		new->exp = e;
		ptr = ptr->link;
	}	
}

struct node* Multiply(struct node *p1,struct node *p2){
	struct node *ptr1,*ptr2,*new1,*new2;
	ppro = GetNode();
	ptr1 = p1->link;
	while(ptr1!=NULL)
	{
		ptr2 = p2->link;
		while(ptr2!=NULL)
		{
			new1 = GetNode();
			new2 = GetNode();
			new2->coef = ptr1->coef*ptr2->coef;
			new2->exp = ptr1->exp+ptr2->exp;
			new1->link= new2; 
			ppro=Add(ppro,new1);
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
	return ppro;
}

struct node* Add(struct node *p1,struct node *p2){
	struct node *p1ptr,*p2ptr,*psum,*psumptr,*new;
	p1ptr = p1->link;
	p2ptr = p2->link;
	psum = GetNode();
	psumptr = psum;
	while((p1ptr!=NULL)&&(p2ptr != NULL)){
		if( p1ptr->exp==p2ptr->exp){
			new = GetNode();
			psumptr->link = new;
			psumptr = psumptr->link;
			psumptr->coef = p1ptr->coef+p2ptr->coef;
			psumptr->exp = p1ptr->exp;
			p1ptr = p1ptr->link;
			p2ptr = p2ptr->link;
		}
		else if(p1ptr->exp>p2ptr->exp){
			new = GetNode();
			psumptr->link = new;
			psumptr = psumptr->link;
			psumptr->coef = p1ptr->coef;
			psumptr->exp = p1ptr->exp;
			p1ptr = p1ptr->link;
		}
		else{
			new = GetNode();
			psumptr->link = new;
			psumptr = psumptr->link;
			psumptr->coef = p2ptr->coef;
			psumptr->exp = p2ptr->exp;
			p2ptr = p2ptr->link;
		}
	}
	while(p1ptr!=NULL){
			new = GetNode();
			psumptr->link = new;
			psumptr = psumptr->link;
			psumptr->coef = p1ptr->coef;
			psumptr->exp = p1ptr->exp;
			p1ptr = p1ptr->link;

	}
	while(p2ptr!=NULL){
			new = GetNode();
			psumptr->link = new;
			psumptr = psumptr->link;
			psumptr->coef = p2ptr->coef;
			psumptr->exp = p2ptr->exp;
			p2ptr = p2ptr->link;
	}
	return psum;
}

void display(struct node* ptr){
	while(ptr->link!=NULL){
		ptr = ptr->link;
		printf(" %.2fx^%d ",ptr->coef,ptr->exp);
		if(ptr->link!=NULL)
		printf("+");
	}
	printf("\n");
}


























