#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x; n->left = n->right = NULL;
    return n;
}
struct Node* insert(struct Node *r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}
struct Node* minNode(struct Node *r) { while (r->left) r = r->left; return r; }

struct Node* del(struct Node *r, int x) {
    if (!r) return NULL;
    if (x < r->data) r->left = del(r->left, x);
    else if (x > r->data) r->right = del(r->right, x);
    else {
        if (!r->left)  { struct Node *t = r->right; free(r); return t; }
        if (!r->right) { struct Node *t = r->left;  free(r); return t; }
        struct Node *m = minNode(r->right);
        r->data = m->data;
        r->right = del(r->right, m->data);
    }
    return r;
}
int search(struct Node *r, int x) {
    if (!r) return 0;
    if (r->data == x) return 1;
    return x < r->data ? search(r->left, x) : search(r->right, x);
}
void inorder(struct Node *r)   { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(struct Node *r)  { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int main() {
    struct Node *root = NULL;
    int ch, x;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Traversals 5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); root = insert(root, x); break;
            case 2: printf("Enter value: "); scanf("%d", &x); root = del(root, x); break;
            case 3: printf("Enter value: "); scanf("%d", &x);
                    printf(search(root, x) ? "Found\n" : "Not found\n"); break;
            case 4: printf("Inorder: ");   inorder(root);
                    printf("\nPreorder: "); preorder(root);
                    printf("\nPostorder: "); postorder(root); printf("\n"); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
