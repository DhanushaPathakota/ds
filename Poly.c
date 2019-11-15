#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(a,b) ((a)>(b)?1:(a)<(b)?-1:0)
typedef struct
{
float coeff;
int exp;
}polynomial;
polynomial terms[100];
int avail=0;
void attach(float coefficient,int exponent)
{
if(avail>=100)
{exit(1);}
else
terms[avail].coeff=coefficient;
terms[avail].exp=exponent;
avail++;
}
void padd(int starta,int finisha,int startb,int finishb,int *startd,int *finishd)
{
float sum;
*startd=avail;
while((starta<=finisha)&&(startb<=finishb))
switch(COMPARE(terms[starta].exp,terms[startb].exp))
{
case 1:attach(terms[starta].coeff,terms[starta].exp);
        starta++;
        break;
case -1:attach(terms[startb].coeff,terms[startb].exp);
        startb++;
        break;
case 0:sum=terms[starta].coeff+terms[startb].coeff;
       if(sum)
      {
       attach(sum,terms[starta].exp);
      }
       starta++;startb++;
       break;
    
}
for(;starta<=finisha;starta++)
{
attach(terms[starta].coeff,terms[starta].exp);
}
for(;startb<=finishb;startb++)
{
attach(terms[startb].coeff,terms[startb].exp);
}
*finishd=avail-1;
}
void takepol(int start,int end)
{
int i;
printf("\n");
for(i=start;i<=end;i++)
{
if(i==end)
{
printf("%.2fX^%d",terms[i].coeff,terms[i].exp);
}
else
printf("%.2fX^%d+",terms[i].coeff,terms[i].exp);
}
printf("\n");
}
int main()
{
int starta=0,finisha=0,startb=0,finishb=0,startd=0,finishd=0;
float coeff;
int expon;
int count=0;
int n,i;
starta=avail;
while(count!=2)
{
printf("enter the no.of terms");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the coeff");
scanf("%f",&coeff);
printf("enter the exponent");
scanf("%d",&expon);
attach(coeff,expon);
}
if(count==0)
{
finisha=avail-1;
startb=avail;
}
if(count==1)
{
finishb=avail-1;
}
count++;
}
takepol(starta,finisha);
takepol(startb,finishb);
padd(starta,finisha,startb,finishb,&startd,&finishd);
takepol(startd,finishd);
}