#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int fib(int n,int *ar)
{
    if(n<=1)
    {
        return n;
    }
    if(ar[n]!=-1)
    {
        return ar[n];
    }
    ar[n]=fib(n-1,ar)+fib(n-2,ar);
    return ar[n];
}
int fibi(int n)
{
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return fib(n,ans);
}
int main()
{
    int a;
    cin>>a;
    cout<<"\n\n"<<fibi(a);
    return 0;
}