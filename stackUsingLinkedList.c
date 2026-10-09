#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x; n->next = NULL;
    if (rear == NULL) front = rear = n;
    else { rear->next = n; rear = n; }
    printf("%d enqueued\n", x);
}
void dequeue() {
    if (front == NULL) { printf("Queue Underflow\n"); return; }
    struct Node *t = front;
    printf("%d dequeued\n", t->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
}
void display() {
    if (front == NULL) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (struct Node *p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}
int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
