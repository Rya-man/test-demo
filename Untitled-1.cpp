#include<iostream>
using namespace std;
class staack
{
    public:
    //int top;
    int n=10;
    int arr[n];
    int* return_last()
    {
        int *x;
        
        for(x=arr[0];x!=NULL;x++)
        {
            if(x+1==NULL)
            return x;
        }

    }
    void push(int a)
    {
        int *x;
        x=return_last();
        *(x+1) = a;
    }
    void pop()
    {
        int *x;
        x=return_last();
        delete x;
    }
    void display_array()
    {
        for(int *i=arr[0];i!=NULL;i++)
        {
            cout<< *i;
        }

    }
    void getdata()
    {
        cout<<"enter array elements"<<endl;
        for(int *i=arr[0];i!=NULL;i++)
        {
            cin>>i;
        }
    }
};
int main()
{
    staack as;
    as.getdata();
}
