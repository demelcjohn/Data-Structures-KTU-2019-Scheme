#include <stdio.h>

#define MAX_TERMS 101

typedef struct
{
  int col;
  int row;
  int value;
} term;

void push (int, int, int, term *);
void display (term *);
void Transpose (term[]);
void Sum (term[], term[]);

int main ()
{
  term A[MAX_TERMS], B[MAX_TERMS], S[MAX_TERMS];
  int r1, r2, c1, c2, i, j, ele;
  printf ("Sparse Matrix\n");
  printf ("Enter the number of rows and columns of matrix A : ");
  scanf ("%d", &r1);
  scanf ("%d", &c1);
  printf ("Enter the number of rows and columns of matrix B : ");
  scanf ("%d", &r2);
  scanf ("%d", &c2);
  printf ("Enter the elements of matrix A :\n");
  A[0].row = r1;
  A[0].col = c1;
  A[0].value = 0;
  for (i = 0; i < r1; ++i)
    for (j = 0; j < c1; ++j)
      {
	scanf ("%d", &ele);
	if (ele != 0)
	  push (i, j, ele, A);
      }
  printf ("Enter the elements of matrix B :\n");
  B[0].row = r2;
  B[0].col = c2;
  B[0].value = 0;
  for (i = 0; i < r2; ++i)
    for (j = 0; j < c2; ++j)
      {
	scanf ("%d", &ele);
	if (ele != 0)
	  push (i, j, ele, B);
      }
  printf ("Matrix A in Tuple form\n");
  display (A);
  printf ("Matrix B in Tuple form\n");
  display (B);
  printf ("Matrix A Transpose\n");
  Transpose (A);
  printf ("Matrix B Transpose\n");
  Transpose (B);
  printf ("SUM(A+B)\n");
  Sum(A,B);
  return 0;
}

void push (int r, int c, int v, term * Mat)
{
  int i;
  i = Mat->value = Mat->value + 1;
  (Mat + i)->row = r;
  (Mat + i)->col = c;
  (Mat + i)->value = v;
}

void display (term * Mat)
{
  for (int i = 0; i < (Mat->value) + 1; ++i)
    printf ("%3d  %3d  %3d\n", (Mat + i)->row, (Mat + i)->col,
	    (Mat + i)->value);
}

void Transpose (term Mat[MAX_TERMS])
{
  term Tra[MAX_TERMS];
  int t, current;
  t = Mat[0].value;
  Tra[0].row = Mat[0].col;
  Tra[0].col = Mat[0].row;
  Tra[0].value = t;
  if (t > 0)
    {
      current = 1;
      for (int i = 0; i < Mat[0].col; ++i)
	for (int j = 1; j <= t; ++j)
	  if (Mat[j].col == i)
	    {
	      Tra[current].row = Mat[j].col;
	      Tra[current].col = Mat[j].row;
	      Tra[current].value = Mat[j].value;
	      current++;
	    }
    }
  display (Tra);
}

void Sum (term A[MAX_TERMS], term B[MAX_TERMS])
{
    int i,j;
  term S[MAX_TERMS];
  if (A[0].row != B[0].row || A[0].col != B[0].col)
    printf ("Not Possible\n");
  else
    {
      S[0].row = A[0].row;
      S[0].col = A[0].col;
      S[0].value = 0;
      for (i=1,j=1;i<=A[0].value&&j<=B[0].value;)
	  {
	    if (A[i].row == B[j].row && A[i].col == B[j].col)
	    {
	        S[++S[0].value].value = A[i].value + B[j].value;
	        S[S[0].value].row=A[i].row;
	        S[S[0].value].col=A[i].col;
	        ++i;
	        ++j;
	    }
	    else if (A[i].row<B[j].row||(A[i].row==B[j].row&&A[i].col<B[j].col))
	    {
	        S[++S[0].value].value=A[i].value;
	        S[S[0].value].row=A[i].row;
	        S[S[0].value].col=A[i].col;
	        ++i;
	    }
	    else
	    {
	        S[++S[0].value].value=B[j].value;
	        S[S[0].value].row=B[j].row;
	        S[S[0].value].col=B[j].col;
	        ++j;
	    }
	  }
	  while(i>A[0].value &&j<=B[0].value)
	  {
	     S[++S[0].value].value=B[j].value;
	     S[S[0].value].row=B[j].row;
	     S[S[0].value].col=B[j].col;
	     ++j;  
	  }
	  while(j>B[0].value &&i<=A[0].value)
	  {
	      S[++S[0].value].value=A[i].value;
	      S[S[0].value].row=A[i].row;
	      S[S[0].value].col=A[i].col;
	      ++i;   
	  }
	  display(S);
	}
}



