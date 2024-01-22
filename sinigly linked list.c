#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*new,*temp,*temp1;
void beginning_insert();
void middle_insert();
void end_insert();
void beginning_delete();
void middle_delete();
void end_delete(); 
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
            case 4:
                beginning_delete();
                break;
            case 5:
                middle_delete();
                break;
            case 6:
                end_delete();
                break;
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
    int val;
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
        for(int i=2;i<loc;i++)
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
void beginning_delete()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        printf("The deleted data = %d",temp->data);
        head=head->next;
        free(temp);
    }
}
void middle_delete()
{
    int loc,i;
    printf("Enter the location to delete");
    scanf("%d",&loc);
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        for(i=1;i<loc;i++)
        {
            if(temp->next==NULL)
            {
                printf("Reached the end of the list");
            }
            temp1=temp;
            temp=temp->next;
        }
        printf("The deleted data = %d",temp->data);
        temp1->next=temp->next;
        free(temp);
    }
}
void end_delete()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        printf("The deleted data = %d",temp->data);
        temp1->next=NULL;
        free(temp);
    }
}
void traversal()
{
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