#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL,*new,*temp;
void enqueue();
void dequeue();
void peek();
void display();
void main()
{
    int c=0;
    
    while(c!=5)
    {
        printf("\nEnter \n1:Enqueue\n2:Dequeue\n3:Peek\n4:Display\n5:Exit");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit;
                break;
        }
    }
    free(new);
    free(front);
    free(rear);
}
void enqueue()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the  value");
    scanf("%d",&new->data);
    if(front==NULL&&rear==NULL)
    {
        front=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
    printf("\nNode Inserted");
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
    }
}
void peek()
{
    printf("Front - %d",front->data);
}
void display()
{
    if(front==NULL)
    printf("\nQueue is empty");
    temp=front;
    while(temp!=NULL)
    {
        printf("%d - ",temp->data);
        temp=temp->next;
    }
}