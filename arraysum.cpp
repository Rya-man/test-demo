#include<iostream>
using namespace std;
class staack
{
    public:
    //int top;
    //int n=10;
    int arr[10];
    int* return_last()
    {
        int *x;
        
        for(*x=arr[0];x!=NULL;x++)
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
        cout<<"\n";

    }
    void display_array()
    {
        int i;
        for(i=0;arr[i]!='\0';i++)
        {
            cout<<" "<<arr[i];
        }

    }
    void getdata()
    {
        int i;
        cout<<"enter array elements"<<endl;
        for(i=0;i<7;i++)
        {
            cin>>arr[i];
        }
    }
};
int main()
{
    staack as;
    as.getdata();
    cout<<"\n\n\n\n";
    as.display_array();
    //cout<<"\n\n\n"<<*(as.return_last());
    //as.pop();
    //as.display_array();
    return 0;
}
