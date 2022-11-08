
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * push(struct node *top,int d){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=d;
    if(top==NULL){
        temp->next=NULL;
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;

    }
    return top;
}
struct node * pop(struct node *top){
    struct node *p,*q;
    if(top==NULL){
        printf("no node is present\n");
    }
    else{
        p=top;
        q=top->next;
        printf("deleted value= %d\n",p->data);
        top=q;
        free(p);
    }
    return top;
}


void display(struct node *head)
{
    struct node *p=head;
    while(p!=NULL){
        printf(" %d ,",p->data);
        p=p->next;
    }
}

void main(){
    struct node *top=NULL;
    int ch;
    while(1){
        printf("\nEnter 1 for insert\n2 for delete\n3 for display\n4 to exit\n ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("enter the data\n");
            int data;
            scanf("%d",&data);
            top=push(top,data);
            break;
        case 2:
            top=pop(top);
                break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
        }

    }
}
