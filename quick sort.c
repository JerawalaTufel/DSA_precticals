#include<stdio.h>
 void quicksort(int a[],int lb,int ub)
 {
     int flag=1,temp,ttemp,i,j;

    if(lb<ub)
        {
        i=lb;
         j=ub+1;
         int key=a[lb];
    while(flag){
        i=i+1;
        while(a[i]<key)
        {
            i=i+1;
        }
        j=j-1;

while(a[j]>key)
{

    j=j-1;
}

    if(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
   // printf(" %d",a[i]);

    }
    else
    {


        flag=0;

  //  printf(" %d",a[lb]);


    }
    }
    ttemp=a[lb];
        a[lb]=a[j];
        a[j]=ttemp;

    quicksort(a,lb,j-1);
    quicksort(a,j+1,ub);

        }
 }
int main()
{
int a[]={5,4,3,2,1},i;

quicksort(a,0,5);
printf("Sorted array\n");
for(i=0;i<5;i++)
{
     printf("%d",a[i]);
}

return 0;
}
