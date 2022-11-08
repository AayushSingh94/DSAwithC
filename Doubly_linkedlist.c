#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node * insert(struct node *head,int d){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    if(head==NULL){
        temp->prev=NULL;
        head=temp;
    }
    else
    {
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;

    }
    return head;
}
struct node * deletenode(struct node *head){
    struct node *p,*q;
    if(head==NULL){
        printf("no node is present\n");
    }
    else{
        p=head;
        q=head->next;
        while(q->next!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=NULL;
        free(q);
    }
    return head;
}


void display(struct node *head)
{
    struct node *p=head;
    while(p!=NULL){
        printf(" %d ",p->data);
        p=p->next;
    }
}

void main(){
    struct node *head=NULL;
    int ch;
    while(1){
        printf("\nEnter 1 for insert\n2 for delete\n3 for display\n4 to exit\n ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("enter the data\n");
            int data;
            scanf("%d",&data);
            head=insert(head,data);
            break;
        case 2:
            head=deletenode(head);
                break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        }

    }
}

