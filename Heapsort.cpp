#include<iostream>
#include<iomanip>
using namespace std;
void heapify(int arr[],int N,int i)
{
    int largest = i;
    int l= 2*i+1;
    int r= 2*i+2;
    if(l<N and arr[l]>arr[largest])
        largest= l;
    if(r<N and arr[r]>arr[largest])
        largest=r;
    }
void heapSort(int *arr,int N)
{
    for(int i=N/2-1;i>=0;i--)
    {
        heapify(arr,N,i);
    }
    for(int i=N-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void Printarray(int arr[],int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<' ';

    }
    cout<<endl;
}
int main()
{
    int a;
    cout<<"enter the number of element in the array"<<endl;cin>>a;
    int *arr = new int[a];
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    heapSort(arr,a);
    cout<<"\n\n\nSorted array is\n";
    Printarray(arr,a);
    delete[] arr;
    return 0;
}