#include <stdio.h>
#include <stdlib.h>

void accept(int a[],int n)
{
    int i;  
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }
}

void display(int a[], int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void bubble(int a[],int n)
{
    int i,temp,pass,cnt=0;
    for(pass=1 ; pass < n ; pass++)
    {
        for(i = 0 ; i <= n-pass-1 ; i++)
        {
            if(a[i] > a[i+1])
            {
                cnt++;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    printf("Comparision count is %d\n",cnt++);
}

int main()
{
    int key,a[100],n;
    printf("How many elements:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    accept(a,n);
    printf("Array:\n");
    display(a,n);
    bubble(a,n);
    printf("Sorted array:\n");
    display(a,n);
}