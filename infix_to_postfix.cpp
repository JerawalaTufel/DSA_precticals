#include<iostream>
#include <string.h>
using namespace std;

int top=-1;
void push(char st[],char no)
{
    if(top==49)
    {
        cout<<"your stack is full!"<<endl;
    }
    else
    {
        top=top+1;
        st[top]=no;

    }
}
char pop(char st[])
{
    if(top==-1)
    {
        cout<<"your stack is empty!"<<endl;
    }
    else
    {

        return st[top--];
    }
}
void print(char st[])
{
    int i=0;
    for(i=0;i<50;i++)
    {
        cout<<st[i]<<endl;
    }
}
int presidance(char c)
{
    if(c=='(' || c==')')
    {
        return 0;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='/' || c=='*')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

int main()
{
    char st[50];
    int i=0;
    char temp;
    string  scan,polish;
    cout<<"enter your equation : ";
    cin>>scan;
    scan=scan+'%';
    push(st,'(');
    while(scan[i]!='%')
    {
        if(isalpha(scan[i]))
        {
            push(st,scan[i]);

        }
        else if(scan[i]==')')
        {
            while(st[top]!='(')
            {
                polish=polish+pop(st);
            }
            pop(st);
        }
        else if(scan[i]=='(')
        {
            push(st,scan[i]);
        }
        else
        {
            while(presidance(scan[i]) <= presidance(st[top]))
            {
                temp=pop(st);
                polish=polish+temp;
            }
            push(st,scan[i]);
        }
        i++;
    }
    while(st[top]!='(')
    {
        polish=polish+pop(st);
    }
    cout<<"output: "<<polish;
}
