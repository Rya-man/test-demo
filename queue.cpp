#include<iostream>
#include<bits/stdc++.h>
using namespace std;   

struct Queue{
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
};
Queue* CreateQueue(unsigned max)
{
    Queue* queue = new Queue();
    queue->capacity= max;
    queue->arr= new int[queue->capacity];
    queue->front=queue->size=0;
    queue->rear=queue->capacity-1;
    return queue;
}
bool isfull(Queue* queue)
{
    return (queue->size==queue->capacity);
}
bool isempty(Queue* queue)
{
    return (queue->size==0);
}
void enqueue(Queue* queue,int data)
{
    queue->rear= ((queue->rear)+1)%queue->capacity;
    for(int i = queue->rear;;);
}