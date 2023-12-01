#include<limits.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Stack{
    int top;
    int capacity;
    int *arr;
};
struct Stack* CreateStack(unsigned capacity){
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    S->capacity= capacity;
    S->top=-1;
    S->arr= (int*)malloc(S->capacity*sizeof(int));
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
void displaystack(struct Stack *S)
{
    if(isempty(S))
    {
        return;
    }
    printf("%d ",pop(S));
    displaystack(S);
    
}
int main()
{
    int maxsize,n;
    printf("ENter the max size of the stack\n");
    scanf("%d",&maxsize);
    int parameter;
    struct Stack *S=CreateStack(maxsize);
    do{
        printf("\nSelect the Function to be performed:\n1. Push element on top of the stack\n2. Pop the element from the top of the stack\n3. Overflow\n4. Underflow\n5. DIsplay Stack\n6. Exit\n\n\n");
        scanf("%d",&parameter);
        switch(parameter)
        {
            case 1: printf("ENter the number to be pushed\t");scanf("%d",&n);push(S,n);break;
            case 2: printf("\n%d\n",pop(S));break;
            case 3: isfull(S)?printf("\nSTack Overflow condition satisfied\n"):printf("\nStack Overflow condition not satisfied\n");break;
            case 4: isempty(S)?printf("\nSTack Underflow condition satisfied\n"):printf("\nStack Underflow condition not satisfied\n");break;
            case 5: displaystack(S);break;
            case 6: free(S->arr);
                    free(S);
                    printf("Exiting...\n"); return 0;
            default: printf("\nWrong option\n");
        }
    }while(true);
    free(S->arr);
    free(S);
    return 0;
}