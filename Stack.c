#include<stdio.h>
#include<stdlib.h>
#define max_stack 30
typedef struct {
int key;
}element;
struct stack{
element data;
struct stack* link;
};
typedef struct stack* stackptr;
stackptr top[max_stack];
void push(int i, element data) {
        stackptr t;
        t=(stackptr)malloc(sizeof(stackptr));
        t->data=data;
        t->link=top[i];
        top[i]=t;
}
void stackEmpty() {
printf("\nStack underflow \n");
exit(0);
}
element pop(int i) {
if(top[i]==NULL)
stackEmpty();
else {
                element x;
                stackptr t;
                t=top[i];
                x=t->data;
                top[i]=top[i]->link;
                free(t);
                return x;
        }
}
void display(int i) {
stackptr t;
t=top[i];
printf("\nCurrent stack : ");
while(t!=NULL) {
printf("\n%d",t->data.key);
t=t->link;
        }
}
int main() {
        int i;
        int m, n;
        element c;
        while(1) {
        printf("\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&m);
        switch(m) {
                 case 1: {
                 printf("\nEnter the stack number and then element ");
                 scanf("%d%d",&n,&c.key);
                 push(n,c);
                         }
                    break;
                 case 2: {
                 printf("\nEnter the stack number to be popped from ");
                 scanf("%d",&n);
                 c=pop(n);
                 printf("\nElement popped is : %d",c.key);
                         }
                    break;
                 case 3: {
                 printf("\nEnter the stack number to be displayed ");
                 scanf("%d",&n);
                 display(n);
                 printf("\n");
                          }
                    break;
                 case 4: exit(0);
                }
        }
        return 0;
}


