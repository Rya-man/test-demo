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
    void mydeletekey(int i);
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
    while(i!=0 && arr[parent(i)]<arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }
}
void MaxHeap::increasekey(int i,int val)
{
    arr[i]=val;
    while(i>0 && arr[parent(i)]<arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i); 
    }
}
int MaxHeap::removeMax()
{
    if(heapsize<=0)
    {
        return INT_MIN;
    }
    if(heapsize==1)
    {
        heapsize--;
        return arr[0];
    }
    int root = arr[0];
    arr[0]=arr[heapsize-1];
    heapsize--;
    MaxHeapify(0);
    return root;
}
void MaxHeap::mydeletekey(int i)
{
    
    arr[i]=arr[lchild(i)]>arr[rchild(i)]?arr[lchild(i)]:arr[rchild(i)];
    if(arr[lchild(i)]==arr[i])
    {
        mydeletekey(lchild(i));
    }
    if(arr[rchild(i)]==arr[i])
    {
        mydeletekey(rchild(i));
    }
    
}
void MaxHeap::deletekey(int i)
{
    increasekey(i,INT_MAX);
    removeMax();
}
int main()
{
    MaxHeap h(15);
    int k,i,n=6,ARR[10];
    h.insertkey(3);
    h.insertkey(6);
    h.insertkey(10);
    h.insertkey(12); 
    h.insertkey(8); 
    h.insertkey(2); 
    return 0;
}
