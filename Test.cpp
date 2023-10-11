#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main()
{
    struct
    {
        void operator()(int x)
        {
            cout<<x<<'\n';
        }
    }something;
    int d= 7;
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    cout<<"d value is \t"<<d<<endl;
    for_each(v.begin(),v.end(),[&d](int x)
    {
        if(x%2==0)
        cout<<"even"<<endl;
        else
        cout<<"Odd"<<endl;
        d+=x;
    });

    cout<<"d value is "<<d<<endl;
    return 0;

}