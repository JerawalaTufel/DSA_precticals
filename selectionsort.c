#include<stdio.h>
void selectionSort(int arr[], int n)
{
    int i,j,min_indx,temp;

    for (i = 0; i < n-1; i++)
    {
        min_indx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_indx])
          {
           min_indx = j;
          }

        temp=arr[i];
            arr[i]=arr[min_indx];
            arr[min_indx]=temp;
    }
}



int main()
{
    int a[]={5,1,2,4,3};
    int i;
     selectionSort(a,5);
    for(i=0;i<5;i++)
    {

        printf("%d ",a[i]);
    }
    return 0;
}
