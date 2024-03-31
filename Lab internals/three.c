#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
typedef struct stack
{
    int *arr;
    unsigned max_size;
    int top;
    /* data */
}stack;

stack* CreateStack(unsigned size)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->arr = (int*)malloc(sizeof(int)*size);
    s->top = -1;
    s->max_size= size;
    return s;
}

bool isempty(stack* s)
{
    return s->top==-1;
}

bool isfull(stack *s)
{
    return (s->top + 1) == s->max_size;
}

void push(int val,stack* s)
{
    if(isfull(s))
    {
        printf("\n stack is full \ncan not insert\n");
        return;
    }
    s->arr[++s->top] = val;
}

void pop(stack* s)
{
    if(isempty(s))
    {
        printf("\n stack is empty \ncan not pop\n");
        return;
    }
    s->top--;
}

int peek(stack* s)
{
    if(isempty(s))
    {
        return INT_MIN;
    }
    return s->arr[s->top];
}

bool checkPalindrome(stack* s)
{
    stack* s2=NULL;
    int a = (s->top)+1;
    s2= CreateStack(s->max_size);
    for(int i=0;i<=(s->top)/2;i++){
        push(peek(s),s2);
        pop(s);
    }
    if(a&1)
        pop(s2);
    while(!isempty(s))
    {
        if(peek(s)!=peek(s2))
        return false;
        pop(s);
        pop(s2);
    }
    return true;
}

void displayStatus(stack* s)
{
    if(isempty(s))
    printf("\nstack is empty\n");
    if(isfull(s))
    printf("\n stack is full\n");
}


