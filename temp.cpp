#include<bits/stdc++.h>
using namespace std;
void print(int a[],int n)
{
	for(int i =0;i<n;++i)
		cout<<i[a]<<' ';
	cout<<'\n';
}
int main()
{
	int n;
	cout<<"ENter array size\n";
	cin>>n;
	int *a;
	a =(int*)malloc(n*4);
	cout<<"ENter the array elements\n";
	for(int i =0;i<n;++i)
		cin>>a[i];
	cout<<"\n\n";
	print(a,n);
	return 0;
}
