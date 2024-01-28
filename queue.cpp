#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
    int *arr;
    int front;
    int rear;
    unsigned capacity;
    int size;
};
Queue* Createqueue(unsigned cap)
{
    Queue* queue = new Queue();
    queue->capacity=cap;
    queue->front=queue->size=0;
    queue->rear=cap-1;
    queue->arr= new int[cap];
    return queue;
}


bool isempty(Queue* queue)
{
    return (queue->size==0);
}
bool isfull(Queue* queue){
    return (queue->size==queue->capacity);
}
int Size(Queue* queue)
{
    return queue->size;
}

void enqueue(int n, Queue* queue)
{
    if(isfull(queue))
    {
        cout<<"queue overflow";
        return;
    }
    queue->rear= (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=n;
    (queue->size)+=1;
    cout<<"\n"<<n<<" inserted\n";
}
int dequeue(Queue *queue)
{
    if (isempty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1)% queue->capacity;
    queue->size = queue->size - 1;
    return item;    
}
int frontval(Queue *queue)
{
    if(isempty(queue))
    return INT_MIN;
    return queue->arr[queue->front];
}
int rearval(Queue* queue)
{
    if (isempty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}
void displayqueue(Queue* queue) {
    Queue temp = *queue;
    while (!isempty(&temp)) {
        cout << ' ' << dequeue(&temp);
    }
}
int main()
{
    Queue *queue;
    int size,ch,val;
    cout<<"\nmax Size of the queue\t";
    cin>>size;
    queue= Createqueue(size);
    while(1)
    {
        cout<<"Perform Function on queue"<<"\n1. Enqueue\n2. Dequeue\n3. Display\n4. check status\n5. Front value\n6. Rear value\n7. Exit\t";
        cin>>ch;
        if(ch==1)
        {
            cout<<"\nEnter element to enqueue\t";cin>>val;
            enqueue(val,queue);
        }
        else if(ch==2)
        {
            int temp = dequeue(queue);
            temp!=INT_MIN?cout<<"\nElement dequeued is "<<temp<<"\n\n":cout<<"Queue empty"<<"\n\n";
        }
        else if(ch==3)
        {
            cout<<'\n';
            displayqueue(queue);
            cout<<"\n\n";
        }
        else if(ch==4)
        {
            if(isfull(queue))
            {
                cout<<"\nQueue is full";
            }
            if(isempty(queue))
            {
                cout<<"\nQueue is empty";
            }
            cout<<"\nQueue size is "<<Size(queue)<<"\n\n";
        }
        else if(ch==5)
        {
            cout<<"\nQueue front value is "<<frontval(queue)<<"\n\n";
        }
        else if(ch==6)
        {
            cout<<"\nQueue rear value is "<<rearval(queue)<<"\n\n";
        }
        else if(ch==7)
        {
            delete(queue);
            return 0;
        }
        else{
            cout<<"\nInvalid choice\n\n";
        }
    }
    return 0;
}