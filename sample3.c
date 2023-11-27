#include<limits.h>
#include<stdio.h>
#include<stdbool.h>
struct Stack{
    int top;
    int capacity;
    int *arr;
};
struct Stack* CreateStack(unsigned capacity){
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    S->capacity= capacity;
    S->top=-1;
    S->arr= (int*)mallac(S->capacity*sizeof(int));
    return S;
};
bool isfull(struct Stack *s)
{
    if(s->top==s->capacity)
    return true;
    else return false;
}
bool isempty(struct Stack*s)
{
    if(s->top==-1)
    return true;
    else return false;
}
void push(struct Stack *S,int a)
{
    if(isfull(S))
    {
        printf("Stack Overflow");
        return;
    }
    S->arr[++S->top] =a;
    printf("\n%d Pushed to the stack\n",a);
}
int pop(struct Stack *S)
{
    int a= S->arr[S->top];
    if(isempty(S))
    {
        return INT_MIN;
    }
    S->top--;
    return a;
}