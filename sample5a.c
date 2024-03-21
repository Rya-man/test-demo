#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
  int *arr;
  int top;
  int maxsize;
}Stack;

Stack* Createstack(int ms)
{
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    st->maxsize = ms;
    st->arr = (int*) malloc(sizeof(int)*ms);

}
int peek(Stack* sx)
{
  if(sx->top!=-1)
  return sx->arr[sx->top];
}
void pop(Stack* sx)
{
  if(sx->top!=-1)
  printf("\n%d has been popped",sx->arr[sx->top--]);
}
void push(Stack *sx,int a)
{
  if(sx->top!=sx->maxsize)
  sx->arr[++sx->top] = a;
}