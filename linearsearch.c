#include <stdio.h>
#include <stdlib.h>

void accept(int a[],int n)
{
    int i;
    for(i = 0 ; i <n ; i++)
    {
        a[i]=rand()%100;
    }
}

void display(int a[],int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void search(int a[], int n, int key)
{
    int i,pos,flag=0;
    for(i = 0 ; i < n ; i++)
    {
        if(a[i] == key)
        {
            flag = 1;
            pos = i;
            break;
        }
    }
    if(flag = 1)
    {
        printf("Element %d found at %d\n",key,pos+1);
    }
    else
    {
        printf("Element not found\n");
    }
}

int main()
{
    int a[100],n,key;
    printf("Enter how many elements:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    accept(a,n);
    printf("The array elements:\n");
    display(a,n);
    printf("Enter the element you want to search:\n");
    scanf("%d",&key);
    search(a,n,key);
}