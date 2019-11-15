#include<stdio.h>
#include<string.h>
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,op}pre;
int top=-1;
int stack[100];
char expr[100];
pre getToken(char *symbol,int *n)
{
*symbol=expr[(*n)++];
switch(*symbol)
{
case '(':return lparen;
case ')':return rparen;
case '+':return plus;
case '-':return minus;
case '*':return times;
case '/':return divide;
case '%':return mod;
case '\0':return eos;
default:return op;
}
}
void push(int x)
{
stack[++top]=x;
}
int eval()
{
pre token;
char symbol;
int n=0,op1,op2;
token=getToken(&symbol,&n);
while(token!=eos)
{
if(token==op)
push(symbol-'0');
else
{
op2=pop();
op1=pop();
switch(token)
{
case plus:push (op1+op2);
          break;
case minus:push(op1-op2);
           break;
case times:push(op1*op2);
           break;
case divide:push(op1/op2);
           break;
case mod: push(op1%op2);
           break;
}
}
token=getToken(&symbol,&n);

}

return pop();
}
int pop()
{
if(top==-1)
printf("empty");
return (stack[top--]);
}

int main()
{
int n;
printf("enter the expression to be evaluated");
scanf("%s",expr);
n=eval();
printf("the result is %d",n);
return 0;
}