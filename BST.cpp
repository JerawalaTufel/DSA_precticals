#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* r_child;
    struct node* l_child;
};
struct node* create(int x)
{
struct node *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=x;
ptr->l_child=NULL;
ptr->r_child=NULL;
return ptr;
}
struct node* insert(int x,struct node* head)
{
 if(head==NULL)
    {
        return create(x);
    }
    if(head->data>x)
    {
      head->l_child=insert(x,head->l_child);
    }
    else if(head->data<x)
    {
        head->r_child=insert(x,head->r_child);
    }
return head;
}
void preorder(struct node* head)
{
    if(head!=NULL)
    {
    cout<<"\t"<<head->l_child<<"||"<<head->data<<"||"<<head->r_child;
    preorder(head->l_child);
    preorder(head->r_child);
}
}

void inorder(struct node* head)
{
    if(head!=NULL)
    {
    inorder(head->l_child);
    cout<<"\t"<<head->l_child<<"||"<<head->data<<"||"<<head->r_child;
    inorder(head->r_child);
}
}
void postorder(struct node* head)
{
    if(head!=NULL)
    {
    preorder(head->l_child);
    preorder(head->r_child);
    cout<<"\t"<<head->l_child<<"||"<<head->data<<"||"<<head->r_child;
}
}
struct node* find(int x,struct node* head)
{
    if(head->data==x || head==NULL)
    {
    return head;
    }
    else if(head->data>x)
    {
        return find(x,head->l_child);
    }
    else if(head->data<x)
    {
        return find(x,head->r_child);
    }
    else
    {
        cout<<x<<"is not in tree";
    }

}
void print(struct node* head)
{
    cout<<head->l_child<<"||"<<head->data<<"||"<<head->r_child;

}
int main()
{
struct node* head=NULL;
int n,ans,k;
char value;
   cout<<"1) Insert.\n";
    cout<<"2) find.\n";
    cout<<"3)print tree.\n";
    cout<<"4)print find value.\n";
    cout<<"5)exit.\n";
do
{
    cout<<"enter your choise:";
    cin>>ans;
    if(ans==1)
    {
        cout<<"Enter your number:";
            cin>>n;
            head=insert(n, head);
    }
    if(ans==2)
    {
        cout<<"Enter the number you want to find:";
        cin>>n;
        head=find(n,head);
    }
if(ans==3)
{
    cout<<"A)preorder.\n";
    cout<<"B)inorder.\n";
    cout<<"C)postorder.\n";
    cout<<"D)exit.\n";
    do
    {
     cout<<endl<<"enter your choise to print tree:";
    cin>>value;
    if(value=='A')
    {
        cout<<"Tree print in preorder:"<<endl;
            preorder(head);
    }
    if(value=='B')
    {
        cout<<"Tree print in inorder"<<endl;
        inorder(head);
    }
    if(value=='C')
    {
        cout<<"Tree print in postorder"<<endl;
        inorder(head);
    }
    }while(value!='D');
    }
    if(ans==4)
    {
        cout<<"your find value is:";
        head=find(n,head);
        print(head);
        cout<<endl;
    }
}while(ans!=5);

return 0;
}
