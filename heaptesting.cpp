#include<utilties.h>

class Heap{
public:
    vi arr;

    Heap(int n=0)
    {
        this->arr.resize(n);
    }
    Heap(vi nums,int n)
    {
        Heap(n);
        this->arr = nums;
    }

    int lchild(int& n)
    {
        return 2*n+1;
    }
    int rchild(int& n)
    {
        return 2*n+2;
    }
    int parent(int& n)
    {
        return (n-1)/2;
    }
    void heapify(int i)
    {
        int largest = i;

        if(lchild(largest)<arr.size() and arr[lchild(largest)] > arr[largest] )
            largest = lchild(largest);
        if(rchild(largest)<arr.size() and arr[rchild(largest)] > arr[largest] )
            largest = rchild(largest);

        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(largest);
        }
    }


    void heapify(int arr[], int n, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0) { 
        if (arr[i] > arr[parent]) { 
            swap(arr[i], arr[parent]); 
            heapify(arr, n, parent); 
        } 
    } 
}


};