#include<bits/stdc++.h>
using namespace std;
class heap
{
private:
    int data;
    heap* left;
    heap* right;
public:
    heap()
    {
        data=-1;
        left=NULL;
        right=NULL;
    }
    heap(int d)
    {
        heap();
        data =d;
    }
    void heaptraversal(heap* h,int v)
    {
        int c = v^1;
        cout<<h->data;
        if(c!=1)
            heaptraversal(h->left,c);
    }
};