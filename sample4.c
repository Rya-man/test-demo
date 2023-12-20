#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
struct Stack{
    char *arr;
    int top;
    int capacity;
};
struct Stack* CreateStack(unsigned capacity){
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    S->capacity= capacity;
    S->top=-1;
    S->arr= (char*)malloc(S->capacity*sizeof(char));
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
void push(struct Stack *S,char a)
{
    if(isfull(S))
    {
        printf("Stack Overflow");
        return;
    }
    S->arr[++S->top] =a;
    printf("\n%d Pushed to the stack\n",a);
}
char pop(struct Stack *S)
{
    int a= S->arr[S->top];
    if(isempty(S))
    {
        return '\0';
    }
    S->top--;
    return a;
}
int priority(char x,struct Stack *S)
{

}
int main()
{
    int maxsize;
    char *e;
    printf("Enter the max size of the expression\n");
    scanf("%d",&maxsize);
    char *exp = (char*)malloc(sizeof(char)*maxsize);
    struct Stack *S=CreateStack(maxsize);
    printf("enter the infix expression\n");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf(" %c ",*e);
        else if(*e=='(' || *e=='{' || *e=='[' )
        {
            push(S,*e);
        }
    }
}