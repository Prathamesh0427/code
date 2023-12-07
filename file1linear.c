#include <stdio.h>
#include <string.h>


typedef struct employee
{
    int age;
    char name[20];
} emp;

emp e[10];

int readfile(emp a[])
{
    int i = 0;
    FILE *fp;
    fp = fopen("e.txt", "r");
    if (fp == NULL)
    {
        printf("File is not found\n");
    }
    else
    {
        while (fscanf(fp, "%d %s", &a[i].age, a[i].name) == 2)
        {
            i++;
        }
        fclose(fp); // Close the file after reading.
    }
    return i;
}

void writefile(emp a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\n", a[i].age, a[i].name);
    }
}

void search(emp a[],int n, emp key)
{
    int i,pos;
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i].age == key.age)
        {
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag==1)
    printf("Age %d is found at %d Its Name is %s\n",key.age,(pos+1),a[i].name);
    else
    printf("Age %d is not Found \n",key.age);
    
}
int main()
{
    int n;
    emp key;
    printf("The contents of file are:\n");
    n=readfile(e);
    writefile(e,n);
    printf("Enter Age To Search \n");
    scanf("%d",&key.age);
    search(e,n,key);  

    return 0;  
}
