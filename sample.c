#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void arraydefinition(int* n, int x)
{
    printf("ENter the array elements ");
    for(int i=0;i<x;i++)
    {
        scanf("%d",&n[i]);        
    }
}
void display(int *n,int x)
{
    for(int i=0; i<x;i++)
    {
        printf("%d\t",n[i]);
    }
    printf("\n");
}
void insertion(int *n,int *x)
{
    int temp =0,pos,ele;
    printf("\nenter the position\t",pos);
    scanf("%d",&pos);
    printf("Enter the element\t",ele);
    scanf("%d",&ele);
    for(int i=0;i<*x+1;i++)
    {
        if(i<pos)
        {
            continue;
        }
        else
        {
            temp= n[i];
            n[i]=ele;
            ele = temp;
        }
    }
    *x+=1;
}
void deletion(int *n,int *x)
{
    int temp = 0,pos;
    printf("\nENter the position to be deleted\t");
    scanf("%d",&pos);
    for(int i=0;i<*x;i++)
    {
        if(i<pos)
        {
            continue;
        }
        else
        {
            temp = n[i+1];
            n[i] = n[i+1];
        }
    }
    *x-=1;
}
int main()
{
    int x;
    int a = -1;
    printf("ENter array size\n");
    scanf("%d",&x);
    int *arr=(int*)malloc(x*sizeof(int));
    arraydefinition(arr,x);
    do
    {
        printf("ENter the operation that you want to perform on your predefined array\n\n1. Display\n2. Insertion\n3. Deletion\n4. Exit");
        scanf("%d",&a);
        switch (a)
        {
            case 1: display(arr,x);break;
            case 2: insertion(arr,&x);break;
            case 3: deletion(arr,&x);break;
            case 4: display(arr,x); free(arr); return 0;
            default: printf("\n\nenter a valid command\n");
        }
    }while(1);
    free(arr);
    return 0;
}