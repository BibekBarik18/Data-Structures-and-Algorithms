#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
}*root,*new;
void populate(struct node *);
void display(struct node *,char);
void main()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the root value ");
    scanf("%d",&new->val);
    root=new;
    populate(root);
    printf("The tree is :\n");
    display(root,'r');
}
void populate(struct node *node)
{
    int left=0;
    printf("Do you want to insert towards the left of %d ",node->val);
    scanf("%d",&left);
    if(left==1)
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the left value ");
        scanf("%d",&new->val);
        new->left=NULL;
        new->right=NULL;
        node->left=new;
        populate(node->left);
    }

    int right=0;
    printf("Do you want to insert towards the right of %d ",node->val);
    scanf("%d",&right);
    if(right==1)
    {
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the right value ");
        scanf("%d",&new->val);
        new->left=NULL;
        new->right=NULL;
        node->right=new;
        populate(node->right);
    }
}
void display(struct node *node,char c)
{
    if(node==NULL)
    return;
    printf("%c->%d \n",c,node->val);
    display(node->left,'l');
    display(node->right,'r');
}