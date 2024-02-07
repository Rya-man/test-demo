#include<stdio.h>
#include<stdlib.h>
struct stack{
    char* arr;
    int top;
    int capacity;
};
struct stack* CreateStack(int cap){
    struct stack* S =(struct stack*)malloc(sizeof(struct stack));
    S->top=-1;
    S->capacity=cap;
    S->arr=(char*)malloc(cap* sizeof(char));
}
void push(struct stack *S,char a)
{
    if((S->top)+1==S->capacity)
    return;
    S->arr[++(S->top)]=a;
}
char pop(struct stack *S)
{
    if(S->top!=-1)
    return S->arr[(S->top)--];
}
char peek(struct stack* S)
{
    if(S->top!=-1)
    return S->arr[S->top];
}
int priority(char x)
{
    if(x=='(')
    return 0;
    if(x=='+'||x=='-')
    return 1;
    if(x=='*'||x=='/')
    return 2;
    if(x=='$'||x=='^')
    return 3;
    return 0;
}
int main()
{
    int maxsize;
    char *e;
    char x;
    printf("ENter the max size of the expression\n");
    scanf("%d",&maxsize);
    char *exp =(char*)malloc(maxsize*sizeof(char));
    struct stack* S =CreateStack(maxsize);
    printf("\nEnter the infix expression\n");
    scanf("%s",exp);
    e=exp;
    while(*e!=0)
    {
        if(isalnum(*e))
        printf("%c",*e);
        else if(*e =='(')
        push(S,*e);
        else if(*e==')')
        {
            while((x=pop(S))!='(')
            printf("%d",x);
        }
        else{
            while(priority(peek(S))>=priority(*e))
            printf("%c",pop(S));
            push(S,*e);
        }
        e++;
    }
    while(S->top!=-1)
    {
        printf("%c",pop(S));

    }
    printf("\n\n");
    return 0;
}