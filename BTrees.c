#include <stdio.h>
#include <stdlib.h>
#define T 2

struct BNode {
    int keys[2*T - 1];
    struct BNode *c[2*T];
    int n, leaf;
};
struct BNode *root = NULL;

struct BNode* newNode(int leaf) {
    struct BNode *x = malloc(sizeof(struct BNode));
    x->leaf = leaf; x->n = 0;
    for (int i = 0; i < 2*T; i++) x->c[i] = NULL;
    return x;
}
void splitChild(struct BNode *x, int i) {
    struct BNode *y = x->c[i], *z = newNode(y->leaf);
    z->n = T - 1;
    for (int j = 0; j < T - 1; j++) z->keys[j] = y->keys[j + T];
    if (!y->leaf) for (int j = 0; j < T; j++) z->c[j] = y->c[j + T];
    y->n = T - 1;
    for (int j = x->n; j >= i + 1; j--) x->c[j + 1] = x->c[j];
    x->c[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) x->keys[j + 1] = x->keys[j];
    x->keys[i] = y->keys[T - 1];
    x->n++;
}
void insertNonFull(struct BNode *x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) { x->keys[i + 1] = x->keys[i]; i--; }
        x->keys[i + 1] = k; x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k) i--;
        i++;
        if (x->c[i]->n == 2*T - 1) {
            splitChild(x, i);
            if (x->keys[i] < k) i++;
        }
        insertNonFull(x->c[i], k);
    }
}
void insert(int k) {
    if (!root) { root = newNode(1); root->keys[0] = k; root->n = 1; return; }
    if (root->n == 2*T - 1) {
        struct BNode *s = newNode(0);
        s->c[0] = root; root = s;
        splitChild(s, 0);
        int i = (s->keys[0] < k) ? 1 : 0;
        insertNonFull(s->c[i], k);
    } else insertNonFull(root, k);
}
void traverse(struct BNode *x) {
    if (!x) return;
    int i;
    for (i = 0; i < x->n; i++) {
        if (!x->leaf) traverse(x->c[i]);
        printf("%d ", x->keys[i]);
    }
    if (!x->leaf) traverse(x->c[i]);
}
int search(struct BNode *x, int k) {
    int i = 0;
    while (i < x->n && k > x->keys[i]) i++;
    if (i < x->n && x->keys[i] == k) return 1;
    if (x->leaf) return 0;
    return search(x->c[i], k);
}
int main() {
    int vals[] = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int i = 0; i < 8; i++) insert(vals[i]);
    printf("B-Tree traversal: ");
    traverse(root);
    printf("\n");
    printf("Search 6: %s\n",  search(root, 6)  ? "Found" : "Not found");
    printf("Search 15: %s\n", search(root, 15) ? "Found" : "Not found");
    return 0;
}
