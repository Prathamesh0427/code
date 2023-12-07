#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
    int data[MAX];
    int top;
}STACK;

void instack(STACK *ps){
    ps->top = -1;
}

void push(STACK *ps,int num){
    ps->top++;
    ps->data[ps->top] = num;
}

int pop(STACK *ps){
    int pop =  ps->data[ps->top];
    ps->top--;
    return pop;
}

int isempty(STACK *ps){
    return ps->top=-1;
}

int isfull(STACK *ps){
    return ps->top == MAX - 1;
}

int peek(STACK *ps){
    return ps->data[ps->top];
}

int main() {
    int n, ch;
    STACK s;
    instack(&s);
    do {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &n);
                push(&s,n);
                break;
            case 2:
                n = pop(&s);
                if (n != -1)
                    printf("Popped element: %d\n", n);
                break;
            case 3:
                n = peek(&s);
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
