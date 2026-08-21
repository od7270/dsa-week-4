#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBegin(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n -> data = x;
    n -> next = head;
    head = n;
}

void insertEnd(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n -> data = x;
    n -> next = NULL;
    if (!head) {
        head = n;
        return;
    }
    struct Node *t = head;
    while (t -> next) {
        t = t -> next;
    }
    t -> next = n;
}

void insertPos(int x, int pos) {
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
    n -> data = x;
    n -> next = t -> next;
    t -> next = n;
}

void deleteBegin() {
    if (!head) {
        printf("List is empty.");
        return;
    }
    struct Node *t = head;
    head = head -> next;
    free(t);
}

void deleteEnd() {
    if (!head) {
        printf("List is empty.");
        return;
    }
    if (!head -> next) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *t = head;
    while (t -> next -> next) {
        t = t->next;
    }
    free(t -> next);
    t -> next = NULL;
}

void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node *t = head;
    for (int i = 1; i < pos - 1 && t; i++) {
        t = t -> next;
    }
    if (!t || !t->next) {
        printf("Invalid Position\n");
        return;
    }
    struct Node *d = t -> next;
    t -> next = d -> next;
    free(d);
}

void display() {
    struct Node *t = head;
    while (t) {
        printf("%d ", t -> data);
        t = t -> next;
    }
    printf("\n");
}

int main() {
        int choice; 
    int temp, pos; 

    while (1) {
        printf("\n=====================================\n");
        printf("LinkedList Operations:\n"); 
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
                printf("\nCurrent: "); 
                display(); 
                printf("\n"); 
                printf("Enter Value: "); 
                scanf("%d", &temp); 
                insertEnd(temp); 
                printf("\nAfter: "); 
                display(); 
                printf("\n"); 
                break; 
                
            case 2: 
                printf("\nCurrent: "); 
                display(); 
                printf("\n"); 
                printf("Enter Value: "); 
                scanf("%d", &temp); 
                insertBegin(temp); 
                printf("\nAfter: "); 
                display(); 
                printf("\n"); 
                break; 
                
            case 3: 
                printf("\nCurrent: "); 
                display(); 
                printf("\n"); 
                printf("Enter Value: "); 
                scanf("%d", &temp); 
                printf("Enter position (not index): "); 
                scanf("%d", &pos); 
                insertPos(temp, pos); 
                printf("\nAfter: "); 
                display(); 
                printf("\n"); 
                break; 
                
            case 4: 
                printf("\nCurrent: "); 
                display(); 
                printf("\n"); 
                deleteEnd(); 
                printf("\nAfter: "); 
                display(); 
                printf("\n"); 
                break; 
                
            case 5: 
                printf("\nCurrent: "); 
                display(); 
                printf("\n"); 
                deleteBegin(); 
                printf("\nAfter: "); 
                display(); 
                printf("\n"); 
                break; 
                
            case 6: 
                printf("\nCurrent: "); 
                display(); 
                printf("\n"); 
                printf("Enter position (not index): "); 
                scanf("%d", &pos); 
                deletePos(pos); 
                printf("\nAfter: "); 
                display(); 
                printf("\n"); 
                break; 
                
            case 7: 
                printf("\nCurrent List: ");
                display(); 
                printf("\n");
                break; 
                
            case 8:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default: 
                printf("Invalid Choice, Try again!\n"); 
                break; 
        } 
    }
   return 0;
}