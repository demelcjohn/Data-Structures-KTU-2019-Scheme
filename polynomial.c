#include<stdio.h>

typedef struct{
    float coef;
    int expon;
}polynomial;
polynomial terms[100];
int avail = 0;

int polynomialZero();
int ReadPolynomial(int);
int PolynomialAdd(int,int,int,int,int);
void DispPolynomial(int,int);

int main()
{
    int t1,t2,startA,startB,finishA,finishB,startC,finishC;
    printf("Polynomial Addition\n");
    printf("Enter the number of terms in polynomial A : ");
    scanf("%d",&t1);
    startA=polynomialZero();
    printf("Enter the coefficients and exponents in polynomial A\n");
    finishA=ReadPolynomial(t1);
    printf("Enter the number of terms in polynomial B : ");
    scanf("%d",&t2);
    startB=polynomialZero();
    printf("Enter the coefficients and exponents in polynomial B\n");
    finishB=ReadPolynomial(t2);
    startC=polynomialZero();
    finishC=PolynomialAdd(startC,startA,finishA,startB,finishB);
    printf("Polynomial A : ");
    DispPolynomial(startA,finishA);
    printf("Polynomial B : ");
    DispPolynomial(startB,finishB);
    printf("Polynomial C\n");
    DispPolynomial(startC,finishC);
    printf("\n");
    return 0;
}


int polynomialZero()
{
    return avail;
}

int ReadPolynomial(int t)
{
    printf("Coefficient Exponent (Dreacresing order)\n");
    for(int i=0;i<t;i++)
    {
        scanf("%f",&terms[avail].coef);
        scanf("%d",&terms[avail].expon);
        avail++;
    }
    return avail-1;
}

int PolynomialAdd(int startC,int startA,int finishA,int startB,int finishB)
{
    int i,j,k;
    for(i=startA,j=startB,k=startC;i<=finishA && j<=finishB;k++)
    {
        if (terms[i].expon==terms[j].expon)
        {
            terms[k].expon = terms[i].expon;
            terms[k].coef = terms[i].coef+terms[j].coef;
            j++ ;  
            i++ ;
        }
        else if(terms[i].expon>terms[j].expon)
        {
            terms[k].expon = terms[i].expon;
            terms[k].coef = terms[i].coef;
            i++;
        }
        else
        {
            terms[k].expon = terms[j].expon;
            terms[k].coef = terms[j].coef;
            j++;
        }
    }
    for(;i<=finishA;i++,k++)
    {
        terms[k].expon = terms[i].expon;
        terms[k].coef = terms[i].coef;
    }
    for(;j<=finishB;j++,k++
    ){
        terms[k].expon = terms[j].expon;
        terms[k].coef = terms[j].coef;
    }
    return k-1;
    avail = k;
}

void DispPolynomial(int st, int fi)
{
    for (int i=st;i<fi;i++)
            printf("%.2fx^%d + ",terms[i].coef,terms[i].expon);
    printf("%.2fx^%d\n",terms[fi].coef,terms[fi].expon);
}

