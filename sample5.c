#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
//This program was made by Aryaman Prakash
struct Stack{
    int top;
    int capacity;
    int *arr;
};
//This program was made by Aryaman Prakash                                                                                                                                                         
struct Stack* CreateStack(unsigned capacity){
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    S->capacity= capacity;
    S->top=-1;
    S->arr= (int*)malloc(S->capacity*sizeof(int));
    return S;
};
//This program was made by Aryaman Prakash
bool isfull(struct Stack *s)
{
    if(s->top==s->capacity)
    return true;
    else return false;
}
//This program was made by Aryaman Prakash
bool isempty(struct Stack*s)
{
    if(s->top==-1)
    return true;
    else return false;
}
//This program was made by Aryaman Prakash
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
int main()
{
        int maxlength;
        printf("\nMax lenght = ");
        scanf("%d",&maxlength);
        char *exp = (char*)malloc(maxlength*sizeof(char));
        printf("\nEnter the expression ");
        scanf("%s",exp);
        struct Stack *s = CreateStack(maxlength);
        char *e;
        e=exp;
        int n1,n2,n3,num;
        while(*e!='\0')
        {
                if(isdigit(*e))
                {
                        num= *e-48;
                        push(s,num);
                }
                else
                {
                        n1=pop(s);
                        n2=pop(s);
                        switch(*e){
                                case '+':
                                        n3=n1+n2;break;
                                case '-':
                                        n3=n1-n2;break;
                                case '*':
                                        n3=n1*n2;break;
                                case '/':
                                        n3=n1/n2;break;
                                case '%':
                                        n3=n1%n2;break;
                        }
                        push(s,n3);
                }
                e++;
        }
        printf("\n\nThe result of the expression %s is %d \n\n",exp,pop(s));
        return 0;
}

