#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*new,*temp;
void beginning_insert();
void middle_insert();
void end_insert();
void traversal();
void main()
{
    int c=0;
    
    while(c!=5)
    {
        printf("\nEnter \n1:Inserion at the beginning\n2:Insertion at the middle\n3:Insertion at end\n4:Displaying the list\n5:Exit");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                beginning_insert();
                break;
            case 2:
                middle_insert();
                break;
            case 3:
                end_insert();
                break;
            case 4:
                traversal();
                break;
            case 5:
                exit;
                break;
        }
    }
}
void beginning_insert()
{
    int val;
    // struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted");
    scanf("%d",&val);
    new->data=val;
    if(head==NULL)
    {
        new->next=NULL;
        head=new;
    }
    else
    {
        new->next=head;
        head=new;
    }
    printf("\nNode inserted");
}
void middle_insert()
{
    int val,loc;
    // struct node *new,*temp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted");
    scanf("%d",&val);
    new->data=val;
    printf("Enter the location to be inserted");
    scanf("%d",&loc);
    if(head==NULL)
    {
        new->next=NULL;
        head=new;
    }
    else
    {
        temp=head;
        for(int i=1;i<loc;i++)
        {
            if(temp->next==NULL)
            {
                printf("Reached the end of the list");
                break;
            }
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    printf("\nNode inserted");
}
void end_insert()
{
    int val;
    // struct node *new,*temp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted");
    scanf("%d",&val);
    new->data=val;
    if(head==NULL)
    {
        new->next=NULL;
        head=new;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new->next=NULL;
        temp->next=new;
    }
    printf("\nNode inserted");
}
void traversal()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}