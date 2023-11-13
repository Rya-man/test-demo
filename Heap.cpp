#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class MaxHeap{
    int* arr;
    int maxsize;
    int heapsize;
    public:
    MaxHeap(int maxSize);
    void MaxHeapify(int);
    int parent(int i){return (i-1)/2;}
    int lchild(int i){return (2*i +1);}
    int rchild(int i){return (2*i + 2);}
    int removeMax();
    void increasekey(int i,int val);
    int getmax()
    {
        return arr[0];
    }    
    int cursize()
    {
        return heapsize;
    }
    void deletekey(int i);
    void insertkey(int i);
};
MaxHeap::MaxHeap(int a)
{
    heapsize=0;
    maxsize=a;
    arr= new int[a];
}
void MaxHeap::MaxHeapify(int a)
{
    int l=lchild(a);
    int r=rchild(a);
    int largest = a;
    if(l<heapsize&&arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<heapsize&&arr[r]>arr[largest])
    {
        largest= r;
    }
    if(largest!=a)
    {
        swap(arr[largest],arr[a]);
        MaxHeapify(largest);
    }
}
void MaxHeap::insertkey(int x)
{
    if(heapsize==maxsize)
    {
        cout<<"\nOverflow Can't insert key\n";
        return;
    }
    heapsize++;
    int i= heapsize-1;
    arr[i]=x;
    while(i!=0&& arr[parent(i)]<arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }


}
