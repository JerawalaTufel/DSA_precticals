#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
  struct  node* link;
};
struct node* head;
struct node* insert(int x)
{
    struct node* temp;
    temp=(struct node*)malloc (sizeof(struct node));

(*temp).data=x;
 temp->link=NULL;
return temp;
  }
  struct node* first_insert(int x)
  {
      struct node* first;
      first=insert(x);
      if(head==NULL)
      {
          return first;
      }
      else
        {
        first->link=head;
      head=first;
        }
  return first;
  }
void last_insert(int x)
  {
      struct node *last;
      struct node *trav;
last=insert(x);
trav=head;
      while(trav->link!=NULL)
      {
          trav=trav->link;

      }
trav->link=last;
  }
  struct node* first_delete(struct node*head)
 {
     return head->link;

 }
  void last_delete(struct node *head)
{
    struct node *trav;
    struct node *temp;
    trav=head;
    while(trav->link!=NULL)
    {
        temp=trav;
        trav=trav->link;
    }
    temp->link=NULL;
}
void insertafter(int x,int k,struct linklist *head)
{
    struct node *trav;
    struct node *temp;
    struct node *new;
    new=insert(k);
    trav=head;
    while(trav->data!=x)
    {
        trav=trav->link;
    }
    if(trav->link!=NULL)
    {
        temp=trav->link;
        trav->link=new;
        new->link=temp;
    }
    else
    {
        trav->link=new;
        new->link=NULL;
    }
}

  void print(head)
 {
     struct node *trav;
     trav=head;
     printf("---------------------------------------------------------------------------------------------\n");
     while(trav!=NULL)
     {
         printf(" %d||%u ",trav->data,trav->link);
         trav=trav->link;
     }
     printf("\n---------------------------------------------------------------------------------------------\n");
 }
 void deleteMiddleNode(int position,struct node* head)
{
    int i;
    struct node *toDelete, *prevNode;
struct node* trav;
trav=head;
    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->link;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->link;

            prevNode->link = toDelete->link;
            toDelete->link = NULL;

            /* Delete nth node */
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}


 int main()
{
head=NULL;
 int n,ans,k;
    printf("1) first add.\n");
    printf("2) last add.\n");
    printf("3) first delete.\n");
    printf("4) last delete.\n");
    printf("5) print.\n");
    printf("6) insert into\n");
   printf("7) delete into\n");
    printf("8) exit.\n");


    do
    {
        printf("Enter your choise:");
        scanf("%d",&ans);
        if(ans==1)
        {
            printf("Enter your number:");
            scanf("%d",&n);
            head=first_insert(n);
        }
        else if(ans==2)
        {
            printf("Enter your number:");
            scanf("%d",&n);
            last_insert(n);
        }
        else if(ans==3)
        {
            head=first_delete(head);
        }
        else if(ans==4)
        {
            last_delete(head);
        }
        else if(ans==5)
        {
            print(head);
        }
        else if(ans==6)
        {
            printf("Enter number after you want to add and what you want to add:");
            scanf("%d%d",&n,&k);
            insertafter(n,k,head);
        }
        else if(ans==7)
        {
            printf("Enter index number of element  you want to delete:");
        scanf("%d",&n);
        deleteMiddleNode(n,head);
        }
    }while(ans!=8);
}


