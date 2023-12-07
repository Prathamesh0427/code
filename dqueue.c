#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void addq(int item)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    if (rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = rear->next;
    }
}

void display()
{
    struct node *temp;
    temp = front;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void removeq()
{
    if (front == NULL)
    {
        printf("\n\nqueue is empty \n");
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("\n\n%d deleted", temp->data);
        free(temp);
    }
}

int main()
{
    int n, ch;
    do
    {
        printf("1. Insert \n2. Delete\n3. Display\n0. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number :");
            scanf("%d", &n);
            addq(n);
            break;
        case 2:
            removeq();
            break;
        case 3:
            display();
            printf("\n1");
            break;
        }
        printf("\n");
    } while (ch != 0);
}
