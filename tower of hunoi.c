#include<stdio.h>
int main()
{
int n=3;
t_o_h(n,'A','B','C');

return 0;
}
void t_o_h(int n,char s,char i,char d)
{
    if(n==1)
    {
        printf("move  %d  %c to %c \n",n,s,d);
    }

 else
 {

     t_o_h(n-1,s,d,i);
     printf("move  %d  %c to %c \n",n,s,d);
     t_o_h(n-1,i,s,d);
 }
}
