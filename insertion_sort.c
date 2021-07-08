void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n; i++) {
        key = arr[i];
        j = i ;

        while (j > 0 && arr[j-1] > key) {
            arr[j] = arr[j-1];
            j = j - 1;
        }
        arr[j] = key;
    }
}

int main()
{

int a[]={4,3,6,2,1,609,7,44,7,22,105,11};
    int i;
insertionSort(a, 12);
    for(i=0;i<12;i++)
    {

        printf("%d ",a[i]);
    }
    return 0;
}
