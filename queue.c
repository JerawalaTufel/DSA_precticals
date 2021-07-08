#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int F=-1;
int R=-1;
int size=5;
void enqueue(int x,int arr[])
{
if(F==-1)
{
F=0;
R=0;
}
if(R<=size-1)
{
arr[R]=x;
R++;
}
else
{
cout<<"Queue Overflow!\n";
}
}
void dequeue()
{
if(F==size)
{
cout<<"\nQueue is Empty!\n";
}
else if(F==-1)
{
cout<<"\nQueue underflow!\n";
}
else if(F<R)
{
F++;
}
else if(F>=R)
{
cout<<"\nQueue is empty!\n";
}
}
void arrayPrint(int a[])
{
for(int i=F;i<R;i++)
{

cout<<a[i]<<" ";
}
cout<<"\n";
}
int main()
{
int arr[size];
int choice;
int n;
cout<<"1. enqueue\n";
cout<<"2. dequeue\n";
cout<<"3. Exit\n";
do
{
cout<<"Enter the choice:";
cin>>choice;
if(choice==1)
{
cout<<"Enter the Number in Queue : ";
cin>>n;
enqueue(n,arr);
}
else if(choice==2)
{
dequeue();
}
cout<<"Queue List ";arrayPrint(arr);
}while(choice!=3);
return 0;
}

