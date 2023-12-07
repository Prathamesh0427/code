#include <stdio.h>
#include<stdlib.h>

void accept(int a[],int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&a[i]);
    }
}

void display(int a[],int n)
{
    int i;
    for ( i = 0; i < n ; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void binarysearch(int a[], int n, int key)
{
    int low,high,mid,pos,flag=0;
    mid = (low+high)/2;
    while(low <= high)
    {
        if(mid < key)
        {
            low = mid+1;
        }
        else if(mid >key)
        {
            high = mid=1;
        }
        else
        {
            flag = 1;
            pos = mid;
            break;
        }
    }
    if(flag == 1)
    {
        printf("element %d found at %d\n",key , pos);
    }
    else
    {
        printf("Element not found\n");
    }
}

int main()
{
    int key,a[100],n;
    printf("Enter how many elements:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    accept(a,n);
    printf("The array elements:\n");
    display(a,n);
    printf("Enter the element you want to search:\n");
    scanf("%d",&key);
    binarysearch(a,n,key);
}