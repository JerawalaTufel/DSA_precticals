#include<stdio.h>
int main()
{
    int n;
printf("enter the size of array ");
scanf("%d",&n);
    int a[n];
    int i,j;
    printf("enter the element : ");
for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
}
    printf("sorted array : ");
  for(i=0;i<n;i++)
  {
   for(j=i+1;j<n;j++)
   {
    if(a[i]>a[j])
    {
        int z;
        z=a[i];
        a[i]=a[j];
        a[j]=z;
    }
  }
  printf("%d\n",a[i]);
  }


int b;
printf("enter the element which you want to find ");
scanf("%d",&b);
    int min=0,max=n-1;
    int mid;
int ex=0;
    while(min<=max){
    mid=(max+min)/2;
    if(a[mid]==b){
      {
printf("\nyour item is at index of %d",mid);
printf("\n your element of order:%d",a[mid]);
   ex++;
      }
    break;
    }
    else if(a[mid]<b)
    {
min=mid+1;
printf("\norder is:%d\n",min);
ex++;
}
    else
    {
        max=mid-1;
        printf("\norder is:%d\n",max);
    ex++;
    }
    }
    printf("\nnumber of comparisons:%d",ex);
    if(min>max)
printf("it is not in your  array");
    return 0;
}
