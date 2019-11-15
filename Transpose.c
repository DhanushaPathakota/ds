#include<stdio.h>
#define MAX_TERMS 101
#define MAX_COL 101
typedef struct
{
int row;
int col;
int val;
}term;
void input(term a[])
{
int i,j,A[100][100],m,n,current;
printf("enter the no.of rows");
scanf("%d",&m);
printf("enter the no.of columns");
scanf("%d",&n);
printf("enter the elements of matrix");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&A[i][j]);
current=1;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(A[i][j]!=0)
{
a[current].row=i;
a[current].col=j;
a[current].val=A[i][j];
current++;
}
}
}
a[0].row=m;
a[0].col=n;
a[0].val=current-1;
}
void transpose(term a[],term b[])
{
int n,i,j,currentb;
n=a[0].val;
b[0].row=a[0].col;
b[0].col=a[0].row;
b[0].val=n;
if(n>0)
{
currentb=1;
for(i=0;i<a[0].col;i++)
{
for(j=1;j<=n;j++)
{
if(a[j].col==i)
{
b[currentb].row=a[j].col;
b[currentb].col=a[j].row;
b[currentb].val=a[j].val;
currentb++;
}
}
}
}
}
void output(term k[])
{
int num_terms,i;
num_terms=k[0].val;
printf("row\tcol\tval\n");
for(i=0;i<num_terms;i++)
{
printf("%d\t%d\t%d\n",k[i].row,k[i].col,k[i].val);
}
}
int main()
{
term a[MAX_TERMS],b[MAX_TERMS];
printf("enter the marix\n");
input(a);
output(a);
transpose(a,b);
output(b);
}