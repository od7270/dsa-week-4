#include <stdio.h>
#include <ctype.h>
#define MAX 100

char st[MAX]; int top = -1;

int balanced(char *e) {
    top = -1;
    for (int i = 0; e[i]; i++) {
        char c = e[i];
        if (c == '(' || c == '[' || c == '{') st[++top] = c;
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) return 0;
            char o = st[top--];
            if ((c == ')' && o != '(') || (c == ']' && o != '[') || (c == '}' && o != '{'))
                return 0;
        }
    }
    return top == -1;
}

int evalPostfix(char *e) {
    int s[MAX], t = -1;
    for (int i = 0; e[i]; i++) {
        if (isdigit(e[i])) s[++t] = e[i] - '0';
        else {
            int b = s[t--], a = s[t--];
            switch (e[i]) {
                case '+': s[++t] = a + b; break;
                case '-': s[++t] = a - b; break;
                case '*': s[++t] = a * b; break;
                case '/': s[++t] = a / b; break;
            }
        }
    }
    return s[t];
}

void printQueue() {
    char q[5][20]; int f = 0, r, n;
    printf("Number of jobs (max 5): ");
    scanf("%d", &n);
    if (n > 5) n = 5;
    for (r = 0; r < n; r++) { printf("Enter job name: "); scanf("%s", q[r]); }
    while (f < r) printf("Printing %s\n", q[f++]);
}

int main() {
    int ch; char e[MAX];
    do {
        printf("\n1.Balanced Parentheses 2.Postfix Evaluation 3.Print Queue 4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter expression: "); scanf("%s", e);
                    printf(balanced(e) ? "Balanced\n" : "Not Balanced\n"); break;
            case 2: printf("Enter postfix (single digits): "); scanf("%s", e);
                    printf("Result = %d\n", evalPostfix(e)); break;
            case 3: printQueue(); break;
        }
    } while (ch != 4);
    return 0;
}
