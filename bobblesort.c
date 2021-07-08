#include<stdio.h>
int ex=0;
void boublesort(int a[],int n)
{
int i,j,last,temp;
 //last=n;
    for(i=0;i<n-1;i++)
    {
for(j=0;j<n-i-1;j++) // for(j=i+1;j<n;j++)
        {

            if(a[j]>a[j+1])  // if(a[i]>a[j])
                {
            temp=a[j];       // temp=a[i];
            a[j]=a[j+1];     //  a[i]=a[j];
            a[j+1]=temp;     //  a[j]=temp;

            }
        ex++;

}
    if(ex==0)
    {

    }
    else
    {
         n=n-1;

    }
/*if(ex!=0)
{
    n=n-1;

}*/
    }
}
int main()
{
    int a[]={9,6,10,3,2,5,1,4,7,8};
    int i;
     boublesort(a,10);
    for(i=0;i<10;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}

