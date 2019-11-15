#include<stdio.h>
#include<string.h>
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}pre;
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
pre stack[100];
char expr[100];
int top=-1;
pre gettoken(char *symbol,int *n)
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
   default:return operand;
}}

void printtoken(pre token)
{
   switch(token)
{
   case lparen:printf("(");
  break;
  case rparen:printf(")");
    break;
   case plus:printf("+");
     break;
    case minus:printf("-");
      break;
   case times:printf("*");
      break;
   case divide:printf("/");
      break;
    case mod:printf("%%");
      break;
     case eos:printf(" ");
      break;
      default:break;
}
}
     void push(pre token)
{
   stack[++top]=token;
}

int pop()
{
   return(stack[top--]);
}

void postfix(void)
{
   char symbol;
   pre token;
   int n=0;
    top=0;
   stack[0]=eos;
for(token=gettoken(&symbol,&n);token!=eos;token=gettoken(&symbol,&n))
{
  if(token==operand)
    printf("%c",symbol);
  else if(token==rparen)
  {
    while(stack[top]!=lparen)
    printtoken(pop());
    pop();
   }
  else
 {
   while(isp[stack[top]]>=icp[token])
     printtoken(pop());
   push(token);
}
}
while((token=pop())!=eos)
 printtoken(token);
  printf("\n");
}
int main()
{
printf("enter expr\n");
scanf("%s",expr);
postfix();
}