#include <stdio.h>
#include <math.h>
#define MAX_SIZE 50

int stack[MAX_SIZE];
int top=-1;

void in_to_post();
void eval_post();
void push(int);
int pop();
int tops();

int main()
{
    int choice;
    printf("Infix <--> Postfix\n");
    printf("1. Convert an infix expression to a postfix expression\n");
    printf("2. Evaluate the postfix expression\n");
    printf("3. Exit\n");
    do{
    printf("Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            in_to_post();
            break;
        case 2:
            eval_post();
            break;
    }
    }while(choice<3);
    return 0;
}

void in_to_post()
{
    char in[50],post[50];
    int exptop=-1;
    printf("Enter the infix expression (Include '()'):");
    scanf("%s",in);
    for(int i=0;in[i]!='\0';++i)
    {
        if(in[i]=='(')
            push(in[i]);
        else if((in[i]>='A'&&in[i]<='Z')||(in[i]>='a'&&in[i]<='z'))
        {
            post[++exptop]=in[i];
        }
        else if(in[i]=='^')
            push(in[i]);
        else if(in[i]=='*'||in[i]=='/')
        {
            while(tops()=='*'||tops()=='/'||tops()=='^')
            {
                post[++exptop]=pop();
            }
            push(in[i]);
        }
        else if(in[i]=='+'||in[i]=='-')
        {
            while(tops()=='+'||tops()=='-'||tops()=='*'||tops()=='/'||tops()=='^')
            {
                post[++exptop]=pop();
            }
            push(in[i]);
        }
        else if(in[i]==')')
        {
            while(tops()!='(')
            {
                post[++exptop]=pop();    
            }
            --top;
        }
    }
    post[++exptop]='\0';
    printf("The required postfix expression : %s\n",post);
}

void eval_post()
{
    char post[50];
    int i,j,rev,num=0,n1,n2;
    printf("Enter the postfix expression (include spaces between) : ");
    scanf(" %[^\n]",post);
    for(i=0;post[i]!='\0';++i)
    {
        if(post[i]>='0'&&post[i]<='9')
        {
            rev=num=0;
            for(j=0;post[i]!=' ';++i,++j)
                rev=rev+(post[i]-48)*pow(10,j);
            for(;rev!=0;rev=rev/10)
            {
                num=num*10;
                num=num+rev%10;
            }
            push(num);
        }
        else if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/'||post[i]=='^')
        {
            n2=pop();
            n1=pop();
            if(post[i]=='+')
                num=n1+n2;
            else if(post[i]=='-')
                num=n1-n2;
            else if(post[i]=='*')
                num=n1*n2;
            else if(post[i]=='/')
                num=n1/n2;
            else if(post[i]=='^')
                num=pow(n1,n2);
            push(num);
        }
    }
    printf("The value is %d\n",tops());
}

void push(int x)
{
    if(top==MAX_SIZE-1)
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    stack[++top]=x;
}

int pop()
{
    top--;
    return stack[top+1];
}

int tops()
{
    return stack[top];
}




