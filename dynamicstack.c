#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *top;

void instack() {
    top = NULL; // Corrected the typo in 'instack' function
}

int isempty() {
    return top == NULL;
}

void push(int num) {
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = num;
    newnode->next = top;
    top = newnode;
}

int pop() {
    int num = -1; // Default value if stack is empty
    if (!isempty()) {
        NODE *temp = top;
        num = top->data;
        top = top->next;
        free(temp);
    } else {
        printf("Stack is empty\n");
    }
    return num;
}

int peek() {
    int num = -1; // Default value if stack is empty
    if (!isempty()) {
        num = top->data;
    } else {
        printf("Stack is empty\n");
    }
    return num;
}

int main() {
    int n, ch;
    instack();
    do {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                n = pop();
                if (n != -1)
                    printf("Popped element: %d\n", n);
                break;
            case 3:
                n = peek();
                if (n != -1)
                    printf("Top element: %d\n", n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
