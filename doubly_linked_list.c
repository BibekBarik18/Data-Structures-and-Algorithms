#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*new,*temp;
void beginning_insert();
void middle_insert();
void end_insert();
// void beginning_delete();
// void middle_delete();
// void end_delete(); 
void traversal();
void main()
{
    int c=0;
    
    while(c!=8)
    {
        printf("\nEnter \n1:Inserion at the beginning\n2:Insertion at the middle\n3:Insertion at end\n4:Deletion in the beginning\n5:Deletion in the middle\n6:Deletion in the end\n7:Displaying the list\n8:Exit");
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
            // case 4:
            //     beginning_delete();
            //     break;
            // case 5:
            //     middle_delete();
            //     break;
            // case 6:
            //     end_delete();
            //     break;
            case 7:
                traversal();
                break;
            case 8:
                exit;
                break;
        }
    }
}
void beginning_insert()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value");
    scanf("%d",&new->data);
    new->prev=NULL;
    new->next=NULL;
    if(head==NULL)
    {    
        head=new;
    }
    else
    {
        new->next=head;
        new->prev=NULL;
        head->prev=new;
        head=new;
    }
    printf("\nNode inserted");
}
void middle_insert()
{
    int n;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value");
    scanf("%d",&new->data);
    printf("Enter the location to be inserted");
    scanf("%d",&n);
    if(head==NULL)
    {
        new->next=NULL;
        new->prev=NULL;
        head=new;
    }
    else
    {
        temp=head;
        for(int i=1;i<n;i++)
        {
            if(temp->next==NULL)
            {
                printf("Reached the end of the list");
                break;
            }
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next->prev=new;
        temp->next=new;
        new->prev=temp;
    }
    printf("\nNode Inserted");
}
void end_insert()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value");
    scanf("%d",&new->data);
    if(head==NULL)
    {
        new->next=NULL;
        new->prev=NULL;
        head=new;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new->prev=temp;
        temp->next=new;
    }
    printf("\nNode Inserted");
}
void traversal()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d - ",temp->data);
        temp=temp->next;
    }
}