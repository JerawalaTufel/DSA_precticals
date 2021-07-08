#include <stdio.h>
#include<stdlib.h>

void enQueue();
void deQueue();
void display();
int queue[5];
int r = - 1;
int f = - 1;
int main()
{
    int choice;
    while (1)
    {
        printf("1.enQueue element:\n");
        printf("2.deQueue element: \n");
        printf("3.Display\n");
        printf("4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            enQueue();
            break;
            case 2:
            deQueue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Enter valid case\n");
        }
    }
return 0;
}

void enQueue()
{
    int add_item;


    if((r==4 && f==0) || (r==f-1) )
        printf("OverFlow\n");

    else if((f!=0 && r==4) ){
        if(r==4)
            r=-1;

        printf("Inset the element in queue: ");
        scanf("%d", &add_item);
        r=r+1;
        queue[r]=add_item;
    }
    else if (f==-1){
        f=0;
        printf("Inset the element in queue: ");
        scanf("%d", &add_item);
        r=r+1;
        queue[r]=add_item;
    }
    else{
         printf("Inset the element in queue: ");
        scanf("%d", &add_item);
        r=r+1;
        queue[r]=add_item;
    }
}
void deQueue()
{
    if(f==-1){
        printf("UnderFlow");
        return;
    }
    if(f==r){
        f=-1;
        r=-1;
    }else{
        printf("Element deQueued from queue is : %d\n", queue[f]);
        f=f+1;
        return;
    }
    if(f==4)
        f=0;
    else{
        printf("Element deQueued from queue is : %d\n", queue[f]);
        f=f+1;
    }


}

void display()
{
    int i;
        printf("Queue is : \n");
        if(r>=f){
        for (i = f; i <= r; i++)
            printf("%d ", queue[i]);
        }else if(r<f){
            for (i = f; i <= 4; i++)
            printf("%d ", queue[i]);
            for (i = 0; i <= r; i++)
            printf("%d ", queue[i]);
        }
        printf("\n");
}
