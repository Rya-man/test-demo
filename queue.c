#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
struct Circularqueue {
    int *data;
    int front;
    int rear;
    int maxsize;
};

struct Circularqueue* createqueue(int n) {
    struct Circularqueue* queue = (struct Circularqueue*)malloc(sizeof(struct Circularqueue));
    queue->data = (int*)malloc(n * sizeof(int));
    queue->maxsize = n;
    queue->rear = -1;
    queue->front = -1;
    
    return queue;
}

void insert(int value, struct Circularqueue* queue) {
    if ((queue->front == 0 && (queue->rear + 1) % queue->maxsize == 0) || ((queue->rear + 1) % queue->maxsize == queue->front)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->maxsize;
    }
    queue->data[queue->rear] = value;
}

void insert_at_front(int value,struct Circularqueue* queue)
{
    if((queue->rear+1)%queue->maxsize == queue->front)
    {
        printf("Queue is full ");
        return;
    }
    if(queue->front== 0)
    {
        
    }
}


int delete(struct Circularqueue* queue) {
    int val;
    if (queue->front == -1) {
        // printf("Queue underflow\n");
        return INT_MIN;
    }
    val = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->maxsize;
    }
    return val;
}

void display(struct Circularqueue* queue) {
    struct Circularqueue temp =*queue;
    if (queue->front == -1)
    {
        printf("\nEmpty queue\n");
        return;
    }
    printf("\nFront = %d\nItems:\t", queue->front);
    do
    {
        printf(" %d",delete(&temp));
    }while(temp.rear-temp.front!=0);
    int val = delete(&temp);
    if(val==INT_MIN){}
    else
        printf(" %d",val);
    printf("\nRear = %d\n\n", queue->rear);
    // int i;
    // if (queue->front == -1)
    //     printf("\nEmpty queue\n");
    // else {
    //     printf("\nFront = %d\n", queue->front);
    //     printf("Items:\t");
    //     for (i = queue->front; i != (queue->rear + 1) % queue->maxsize; i = (i + 1) % queue->maxsize) {
    //         printf("%d ", queue->data[i]);
    //     }
    //     printf("\nRear = %d\n\n", queue->rear);
    // }
}

int main() {
    int n;
    printf("enter maxisze\n");
    scanf("%d", &n);
    struct Circularqueue* queue;
    queue = createqueue(n);
    int choice, value;
    while (1) {
        printf("\n1.Insert element\n2.Delete\n3.Display\n4.Quit\n\nenter choice:\t");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert\t");
            scanf("%d", &value);
            insert(value, queue);
        } else if (choice == 2) {
            value = delete(queue);
            if (value != INT_MIN)
                printf("\ndeleted value = %d\n", value);
            else
                printf("\nQueue Underflow\n");
        } else if (choice ==3) {
            display(queue);
        } else if (choice == 4) {
            free(queue->data);
            free(queue);
            exit(0);
        } else
            printf("Invalid choice\n");
    }
    return 0;
}