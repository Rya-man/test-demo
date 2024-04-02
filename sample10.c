#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // for INT_MIN

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct stack {
    Node* top;
} stack;

Node* CreateNode(int d) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

stack* Createstack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = NULL; // Initialize top to NULL
    return s;
} 

void push(stack* s, int d) {
    if (!s) {
        s = Createstack();
    }
    Node* temp = CreateNode(d);
    temp->next = s->top;
    s->top = temp;
}

int pop(stack* s) {
    if (!s || !s->top) {
        return INT_MIN;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    int res = temp->data;
    free(temp);
    return res;
}

int peek(stack* s) {
    if (s && s->top) {
        return s->top->data;
    }
    return INT_MIN;
}

void display(stack* s) {
    if (s) {
        Node* temp = s->top;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    } else {
        printf("\nStack is empty\n\n");
    }
}

int main() {
    int ch, val;
    stack* s = NULL;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\t");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter element to push: ");
                scanf("%d", &val);
                if (!s) s = Createstack(); // Check if stack is not created yet
                push(s, val);
                break;
            case 2:
                printf("\n");
                if (peek(s) == INT_MIN) {
                    printf("Stack underflow\n");
                } else {
                    printf("%d has been popped\n", pop(s));
                }
                break;
            case 3:
                printf("\n");
                if (peek(s) == INT_MIN) {
                    printf("Stack underflow\n");
                } else {
                    printf("%d is the current top value\n", peek(s));
                }
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
