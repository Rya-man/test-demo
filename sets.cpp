#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    set<int,greater<int>> a;
    int x;
    for(int i=0;i<10;i++)
    {
        cin>>x;
        a.insert(x);
    }
    cout<<"\n\n\n";
    for(auto it= a.begin();it!=a.end();it++)
    {
        cout<<*it<<' ';
    }
    return 0;
}