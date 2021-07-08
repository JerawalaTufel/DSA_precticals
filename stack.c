#include<stdio.h>
#define z 100
static int a[z];
static int top=-1;
int x;
int main()
{
 push(10);
  push(20);
 push(30);
 push(40);
 push(50);
 pop();
 pop();
pop();
pop();
pop();
return 0;
}
void push( x)
{
if(top>=z-1)
{
    printf("stack overflow");
}
else{
a[top++]=x;


printf("%d is push \n",x);

}
}
void pop()
{
if(top<0)
{
    printf("stack is empty");
}
else{
    printf("%d is pop \n",a[--top]);
}
}
