#include<stdio.h>
void push(int *n,int a,int l)
{
    int temp =n[0];
    n[0]=a;
    for(int i=1;i<l+1;i++)
    {
        int x = temp;
        temp= n[i];
        n[i]=x;
    }
}
void push