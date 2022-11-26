#include<stdio.h>
#include<stdlib.h>
struct tree{
    struct tree *left;
    int info;
    struct tree *right;
};
void insert(struct tree **,struct tree *temp);
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
struct tree *create(int );
void main()
{
    struct tree *root=NULL;
    struct tree *temp;
    int num,ch;
    while(1)
    {
        printf("\nenter 1 for insert,\n2 for inorder traversal\n3 for preorder traversal\n4for postorder traversal\n5 for exit\n");
        printf("\nEnter your choice:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the number\n");
                scanf("%d",&num);
                temp=create(num);
                insert(&root,temp);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                exit(0);
        }
    }
}
struct tree * create(int num)
{
        struct tree *temp;
        temp=(struct tree *)malloc(sizeof(struct tree));
        if(temp!=NULL)
        {
            temp->left=NULL;
            temp->info=num;
            temp->right=NULL;
        }
        else{
            printf("memory not allocated");
        }
        return temp;
}
void insert(struct tree **rt,struct tree *temp)
{
    if(*rt==NULL)
    {
        *rt=temp;
    }
    else
    {
            if((*rt)->info>temp->info)
            {
                insert(&((*rt)->left),temp);
            }
            else if((*rt)->info<temp->info)
            {
                insert(&((*rt)->right),temp);
            }
    }
}
void inorder(struct tree *rt)
{
    if(rt==NULL)
    {
        printf(" ");
    }
    else
    {
            inorder(rt->left);
            printf("%d",rt->info);
            inorder(rt->right);
    }
}
void preorder(struct tree *rt)
{
    if(rt==NULL)
    {
        printf(" ");
    }
    else
    {
            printf("%d",rt->info);
            inorder(rt->left);
            inorder(rt->right);
    }
}
void postorder(struct tree *rt)
{
    if(rt==NULL)
    {
        printf(" ");
    }
    else
    {
            inorder(rt->left);
            inorder(rt->right);
            printf("%d",rt->info);
    }
}



