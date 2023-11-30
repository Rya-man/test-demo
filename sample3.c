#include<limits.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
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
bool palindrome(int a,int maxsize)
{
    int temp = a;
    struct Stack *S = CreateStack(maxsize);

    while (temp != 0) {
        push(S, temp % 10);
        temp /= 10;
    }

    temp = a;
    int reversed = 0;
    int placeValue = 1;

    while (!isempty(S)) {
        reversed += pop(S) * placeValue;
        placeValue *= 10;
    }

    return reversed == a;   
}
void StackStatus(struct Stack *s)
{
    printf("\nThe stack has %d elements\nThe stack capacity is %d\n",s->top +1,s->capacity);
}
int main()
{
    int maxsize,n;
    printf("ENter the max size of the stack\n");
    scanf("%d",&maxsize);
    int parameter;
    struct Stack *S=CreateStack(maxsize);
    do{
        printf("\nSelect the Function to be performed:\n1. Push element on top of the stack\n2. Pop the element from the top of the stack\n3. Check if the number is a palindrome\n4. Overflow\n5. Underflow\n6. Stack status\n7. Exit\n\n");
        scanf("%d",&parameter);
        switch(parameter)
        {
            case 1: printf("ENter the number to be pushed\t");scanf("%d",&n);push(S,n);break;
            case 2: printf("\n%d\n",pop(S));break;
            case 3: printf("ENter the number check palindrome ");scanf("%d",&n);if(palindrome(n,maxsize)){printf("\n\nThe number is a palindrome\n\n");}else{printf("\n\nThe number is not a palindrome\n\n");}break;
            case 4: isfull(S)?printf("\nSTack Overflow condition satisfied\n"):printf("\nStack Overflow condition not satisfied\n");break;
            case 5: isempty(S)?printf("\nSTack Underflow condition satisfied\n"):printf("\nStack Underflow condition not satisfied\n");break;
            case 6: StackStatus(S);break;
            case 7: free(S->arr);
                    free(S);
                    printf("Exiting...\n"); return;
            default: printf("\nWrong option\n");
        }
    }while(true);
    free(S->arr);
    free(S);
    return 0;
}