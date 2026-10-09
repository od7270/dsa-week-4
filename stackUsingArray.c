#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) { printf("Queue Overflow\n"); return; }
    if (front == -1) front = 0;
    q[++rear] = x;
    printf("%d enqueued\n", x);
}
void dequeue() {
    if (front == -1 || front > rear) { printf("Queue Underflow\n"); return; }
    printf("%d dequeued\n", q[front++]);
}
void display() {
    if (front == -1 || front > rear) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
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
