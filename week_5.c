#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    if (!head || !second || !third) return 1;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    void printList(struct node *element) {
        struct node *temp = element;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }

    void insertAtBeginning(int data) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        newNode->head;


    }

    printList(head);


    return 0;
}