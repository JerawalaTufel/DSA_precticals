#include<iostream>
using namespace std;
int size;
int l_probing(int key)
{
    int i;
    i=key%size;
    return i;
}
int li_probing(int key)
{
    int i;
    i=(key+1)%size;
    return i;
}
int main()
{
 int arr[50],hash[50],key,n;
 cout<<"enter the size of table:";
 cin>>size;
    cout<<"enter the number element:";
    cin>>n;
    cout<<"element are:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        hash[i]=-1;
    }
    for(int i=0;i<n;i++)
    {

        key=arr[i];
    int j=l_probing(key);
 while(hash[j]!=-1)
 {
     j=li_probing(j);
 }
 hash[j]=key;
    }
    for(int i=0;i<size;i++)
    {
        cout<<"\nelement at position of :"<<i<<":"<<hash[i]<<endl;
    }
    return 0;
}
