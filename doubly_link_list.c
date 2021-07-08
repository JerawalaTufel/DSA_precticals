#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lptr;
	struct node* rptr;
};
struct node* create(int x)
{
	struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
	  ptr->data=x;
	ptr->lptr=NULL;
	ptr->rptr=NULL;
	return ptr;
}
struct node* insert_first(int x,struct node* head)
{
	struct node *new1;
	new1=create(x);
	if(head==NULL)
	{
		return new1;
	}
else
{
	head->lptr=new1;
	new1->rptr=head;
	head=new1;
	}
	return head;
}
void insert_last(int x,struct node* head)
{
	struct node *ptr1;
	struct node *trav;
	ptr1=create(x);
	trav=head;
	while(trav->rptr!=NULL)
	{
		trav=trav->rptr;
	}
	trav->rptr=ptr1;
	ptr1->lptr=trav;


}
struct node* delete_first(struct node* head)
{
	struct node* new1;
	new1=head->rptr;
	new1->lptr=NULL;
	return head->rptr;

}
void delete_last(struct node* head)
{
	struct node* ptr;
	struct node* trav;
	trav=head;
	while(trav->rptr!=NULL)
	{
	ptr=trav;
		trav=trav->rptr;
	}
	ptr->rptr=NULL;
}
void print(struct node *head)
 {
     struct node *trav;
     trav=head;
     printf("---------------------------------------------------------------------------------------------\n");
     while(trav!=NULL)
     {
         printf(" %u||%d||%u ",trav->lptr,trav->data,trav->rptr);
         trav=trav->rptr;
     }
     printf("\n---------------------------------------------------------------------------------------------\n");
 }
 void insert_middle(int x,int k,struct node*head)
 {
struct node *trav;
    struct node *temp;
    struct node *new;
    new=create(k);
    trav=head;
     while(trav->data!=x)
     {
          trav=trav->rptr;
     }
 	 if(trav->rptr!=NULL)
    {
        temp=trav->rptr;
        trav->rptr=new;
        new->rptr=temp;

        temp->lptr=new;
        new->lptr=trav;
    }
 	 else
     {

          trav->rptr=new;
        new->lptr=trav;
        new->rptr=NULL;
     }
 }
 void delete_middle(struct node *head,int n)
{
    struct node *trav;
    struct node *temp;
    struct node *temp2;
    trav=head;
    while(trav->data!=n)
    {
        temp=trav;
        trav=trav->rptr;
    }
    if(trav->rptr==NULL)
    {
        temp->rptr=NULL;
        return head;
    }
    else if(trav==head)
    {
        temp2=trav->rptr;
        temp2->lptr=NULL;
        return temp2->rptr;
    }
    else
    {
        /*temp2=trav->rptr;
        temp->rptr=temp2;
        temp2->lptr=trav;
        return head;*/
       temp->rptr=trav->rptr;
        trav->rptr->lptr=trav->lptr;
        return head;
    }
}


int main()
{
struct node* head=NULL;
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
            head=insert_first(n, head);
        }
        else if(ans==2)
        {
            printf("Enter your number:");
            scanf("%d",&n);
            insert_last(n, head);
        }
        else if(ans==3)
        {
            head=delete_first( head);
        }
        else if(ans==4)
        {
            delete_last(head);
        }
        else if(ans==5)
        {
            print(head);
        }
        else if(ans==6)
        {
            printf("Enter number after you want to add and what you want to add:");
            scanf("%d%d",&n,&k);
            insert_middle( n,k,head);
        }
        else if(ans==7)
        {
            printf("Enter number you want to delete:");
        scanf("%d",&n);
        delete_middle(head,n);
        }
    }while(ans!=8);
 return 0;
}
