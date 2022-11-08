#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * insert(struct node *head,int d){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=d;

    if(head==NULL){
        head=temp;
        temp->next=head;
    }
    else
    {
        p=head;
        while(p->next!=head){
            p=p->next;
        }
        p->next=temp;
        temp->next=head;

    }
    return head;
}

void display(struct node *head)
{
    struct node *p=head;
    do{
        printf(" %d ,",p->data);
        p=p->next;
    }while(p!=head);
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
            //head=deletenode(head);
                //break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        }

    }
}

