

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
 struct node *front=NULL;
struct node *rear=NULL;

struct node * push(int d){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    if(front==NULL&&rear==NULL){
        rear=temp;
        front=temp;
    }
    else
    {
        printf("testing");
        rear->next=temp;
        rear=temp;

    }
    return rear;
}
struct node * deletenode(){
    struct node *p,*q;
    if(front==NULL){
        printf("no node is present\n");
    }
    else{
        p=front;
        q=front->next;
        printf("deleted value= %d\n",p->data);
        front=q;
        free(p);
    }
    return front;
}


void display()
{
    struct node *p=front;
    while(p!=NULL){
        printf(" %d ,",p->data);
        p=p->next;
    }
}

void main(){
    int ch;
    while(1){
        printf("\nEnter 1 for insert\n2 for delete\n3 for display\n4 to exit\n ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("enter the data\n");
            int data;
            scanf("%d",&data);
            front=push(data);
            break;
        case 2:
            front=deletenode();
                break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }

    }
}
