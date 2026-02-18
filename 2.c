#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;              
    struct node *next;
};

struct node* createlist(struct node *head){
    struct node *temp=NULL,*newnode=NULL;
    int choice=1;

    while(choice==1){
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("Enter Student ID: ");
        scanf("%d",&newnode->data);

        newnode->next=NULL;

        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("Enter 1 to continue 0 to stop: ");
        scanf("%d",&choice);
    }

    return head;
}

void display(struct node *head){
    struct node *temp=head;

    if (head==NULL){
        printf("List is empty\n");
        return;
    }

    printf("Student IDs are: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

struct node* insertfirst(struct node *head){
    struct node *newnode=NULL;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter new Student ID to insert at first: ");
    scanf("%d",&newnode->data);

    newnode->next=head;   
    head=newnode;         

    return head;
}

int main(){
    struct node *head=NULL;

    head=createlist(head);
    display(head);

    head=insertfirst(head);   // insert at first
    display(head);

    return 0;
}
