#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertBegin(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    if (!n) {
        printf("Memory allocation failed.\n");
        return;
    }
    n -> data = x;
    n -> prev = NULL;
    n -> next = head;

    if (head != NULL) {
        head -> prev = n;
    }
    head = n;
}

void insertEnd(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    if (!n) {
        printf("Memory allocation failed.\n");
        return;
    }
    n -> data = x;
    n -> next = NULL;

    if (!head) {
        n -> prev = NULL;
        head = n;
        return;
    }

    struct Node *t = head;
    while (t -> next) {
        t = t -> next;
    }
    t -> next = n;
    n -> prev = t;
}

void insertPos(int x, int pos) {
    if (pos < 1) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1) {
        insertBegin(x);
        return;
    }

    struct Node *t = head;
    for (int i = 1; i < pos - 1 && t; i++) {
        t = t -> next;
    }

    if (!t) {
        printf("Invalid Position\n");
        return;
    }

    struct Node *n = malloc(sizeof(struct Node));
    if (!n) {
        printf("Memory allocation failed.\n");
        return;
    }
    n -> data = x;
    
    n -> next = t -> next;
    n -> prev = t;
    
    if (t -> next != NULL) {
        t -> next -> prev = n;
    }
    t -> next = n;
}

void deleteBegin() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node *t = head;
    head = head -> next;
    
    if (head != NULL) {
        head -> prev = NULL;
    }
    free(t);
}

void deleteEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    if (!head -> next) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *t = head;
    while (t -> next) {
        t = t -> next;
    }
    
    t -> prev -> next = NULL;
    free(t);
}

void deletePos(int pos) {
    if (pos < 1 || !head) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1) {
        deleteBegin();
        return;
    }

    struct Node *t = head;
    for (int i = 1; i < pos && t; i++) {
        t = t -> next;
    }

    if (!t) {
        printf("Invalid Position\n");
        return;
    }

    if (t -> next != NULL) {
        t -> next -> prev = t -> prev;
    }
    if (t -> prev != NULL) {
        t -> prev -> next = t -> next;
    }
    
    free(t);
}

void display() {
    struct Node *t = head;
    if (!t) {
        printf("Empty\n");
        return;
    }
    printf("> ");
    struct Node *last = NULL;
    while (t) {
        printf("%d ", t -> data);
        last = t;
        t = t -> next;
    }
    printf("\n");
}

int main() {
    int choice, temp, pos;
    
    while (1) {
        printf("\n=====================================\n");
        printf("Doubly LinkedList Operations:\n");
        printf("1. Insert at End.\n");
        printf("2. Insert at Beginning.\n");
        printf("3. Insert at Position.\n");
        printf("4. Delete at End.\n");
        printf("5. Delete at Beginning.\n");
        printf("6. Delete at Position.\n");
        printf("7. Display List.\n");
        printf("8. Exit Program.\n");
        printf("-------------------------------------\n");
        printf("Enter Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Exiting program.\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("\nCurrent:\n"); display();
                printf("Enter Value: "); scanf("%d", &temp);
                insertEnd(temp);
                printf("\nAfter:\n"); display();
                break;
            case 2:
                printf("\nCurrent:\n"); display();
                printf("Enter Value: "); scanf("%d", &temp);
                insertBegin(temp);
                printf("\nAfter:\n"); display();
                break;
            case 3:
                printf("\nCurrent:\n"); display();
                printf("Enter Value: "); scanf("%d", &temp);
                printf("Enter position: "); scanf("%d", &pos);
                insertPos(temp, pos);
                printf("\nAfter:\n"); display();
                break;
            case 4:
                printf("\nCurrent:\n"); display();
                deleteEnd();
                printf("\nAfter:\n"); display();
                break;
            case 5:
                printf("\nCurrent:\n"); display();
                deleteBegin();
                printf("\nAfter:\n"); display();
                break;
            case 6:
                printf("\nCurrent:\n"); display();
                printf("Enter position: "); scanf("%d", &pos);
                deletePos(pos);
                printf("\nAfter:\n"); display();
                break;
            case 7:
                printf("\nCurrent List:\n");
                display();
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                while(head) {
                    deleteBegin();
                }
                exit(0);
            default:
                printf("Invalid Choice, Try again!\n");
                break;
        }
    }
    return 0;
}
