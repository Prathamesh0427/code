#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    
}NODE;

void create (NODE *head)
{
    int i ,n;
    NODE *newnode , *last;
    printf("How many elements:\n");
    scanf("%d",&n);
    last = head;
    for(i = 0 ; i < n ; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = NULL;
        printf("Enter the data in node:\n");
        scanf("%d",&newnode->data);
        last->next = newnode;
        last = newnode;
    }
}

void display (NODE *head)
{
    NODE *temp;
    printf("The singly linked list is:\n");
    for(temp = head->next ; temp != NULL ; temp = temp->next)
    {
        printf("%d\t",temp->data);
    }
    printf("\n");
}

void insert (NODE *head)
{
    NODE *temp,*newnode;
    int i ,pos;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the pos of newnode:\n");
    scanf("%d",&pos);
    for(temp = head , i =0 ; temp != NULL && i < pos - 1 ; i++)
    {
        temp = temp->next;
    }
    printf("Enter the data to insert:\n");
    scanf("%d",&newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_first (NODE *head)
{
    NODE *temp , *newnode;
    temp = head;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data in node:\n");
    scanf("%d",&newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_last (NODE *head)
{
    NODE *temp, *newnode;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data in node:\n");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp->next = newnode;
}

/*void reverse(NODE** head) {
    NODE* prev = NULL;
    NODE* current = *head;
    NODE* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev; // Update the head to point to the new first node (formerly the last node).
}*/

void reverse(NODE *head)
{
    NODE *temp = NULL;
    NODE *temp1 = NULL;
    while (head != NULL)
    {
        temp1 = head->next;
        head->next = temp;
        temp = head;
        head = temp1;
    }
    head = temp;
    //return head;
}

void delete (NODE *head)
{
    NODE *temp , *temp1;
    int i ,pos;
    printf("Enter the pos of node want to delete:\n");
    scanf("%d",&pos);
    for(temp = head , i = 0 ; temp != NULL && i < pos-1 ; i++)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

int main()
{
    NODE *head;
    int choice;
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    printf("Linked list operation:\n");
    do
    {
        printf("1. Create Link list\n");
        printf("2. Display link list\n");
        printf("3. Insert Node\n");
        printf("4. Insert node at begining\n");
        printf("5. Insert node at end\n");
        printf("6. Delete node\n");
        printf("7. Reverse Linked list:\n");
        //printf("8. Delete node at end\n");
        printf("8. Exit\n");

        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                create(head);
                display(head);
                break;

            case 2:
                display(head);
                break;
            
            case 3:
                insert(head);
                display(head);
                break;
            
            case 4:
                insert_first(head);
                display(head);
                break;

            case 5:
                insert_last(head);
                display(head);
                break;

            case 6:
                delete(head);
                display(head);
                break;

            case 7:
                reverse(head);
                display(head);
                break;
                //exit(0);

            case 8:
                exit(0);
        }
    }
    while (choice != 8);
}