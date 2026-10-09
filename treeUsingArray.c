#include <stdio.h>
#define MAX 15

int tree[MAX], n = 0;

void insert(int x) {
    if (n == MAX) { printf("Tree full\n"); return; }
    tree[n++] = x;
}
void inorder(int i)   { if (i >= n) return; inorder(2*i+1);  printf("%d ", tree[i]); inorder(2*i+2); }
void preorder(int i)  { if (i >= n) return; printf("%d ", tree[i]); preorder(2*i+1); preorder(2*i+2); }
void postorder(int i) { if (i >= n) return; postorder(2*i+1); postorder(2*i+2); printf("%d ", tree[i]); }

int main() {
    int vals[] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < 6; i++) insert(vals[i]);

    for (int i = 0; i < n; i++) {
        printf("Node %d: left = ", tree[i]);
        (2*i+1 < n) ? printf("%d", tree[2*i+1]) : printf("NULL");
        printf(", right = ");
        (2*i+2 < n) ? printf("%d\n", tree[2*i+2]) : printf("NULL\n");
    }
    printf("Inorder: ");   inorder(0);
    printf("\nPreorder: "); preorder(0);
    printf("\nPostorder: "); postorder(0);
    printf("\n");
    return 0;
}
