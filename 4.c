#include <stdio.h>
#include <stdlib.h>

struct node {
    int student_id;
    struct node *next;
};


struct node* create(struct node *head) {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter Student ID: ");
        scanf("%d", &newnode->student_id);

        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Add another student? (1/0): ");
        scanf("%d", &choice);
    }

    return head;
}


void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Student IDs in list:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->student_id);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct node* delete_by_id(struct node *head, int id) {
    struct node *temp = head, *prev = NULL;

    
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    
    if (head->student_id == id) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student ID %d deleted successfully\n", id);
        return head;
    }

    
    while (temp != NULL && temp->student_id != id) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Student ID not found\n");
        return head;
    }

    
    prev->next = temp->next;
    free(temp);
    printf("Student ID %d deleted successfully\n", id);

    return head;
}


int main() {
    struct node *head = NULL;
    int id;

    head = create(head);
    display(head);

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    head = delete_by_id(head, id);
    display(head);

    return 0;
}