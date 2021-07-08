#include<stdio.h>
int main()
{
int a[]={10,3,6,5,7,9};
int i;
int b=9;
int c=6,ex=0;
for(i=0;i<c;i++)
{

if(a[i]==b)
{
printf("your element is on index of: %d",i);
break;
}
else
{

    ex++;
}
}
if(ex==c)
{
printf("your element is not in array");
}
return 0;
}
