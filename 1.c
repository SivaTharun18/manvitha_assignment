#include <stdio.h>
#include <stdlib.h>

struct node{
    int student_id;
    struct node *next;
};

struct node* createlist(struct node *head){
    struct node *temp=NULL, *newnode=NULL;
    int choice=1;

    while(choice==1){
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("Enter Student ID: ");
        scanf("%d",&newnode->student_id);

        newnode->next=NULL;

        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

        printf("Enter 1 to continue, 0 to stop: ");
        scanf("%d",&choice);
    }

    return head;
}

void traverse(struct node *head){
    struct node *temp = head;

    if(head == NULL){
        printf("No student records found.\n");
        return;
    }

    printf("Student IDs are:\n");

    while(temp != NULL){
        printf("%d\n", temp->student_id);
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;

    head = createlist(head);
    traverse(head);

    return 0;
}
