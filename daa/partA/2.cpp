#include <utilties.h>

int linsearch_iterative(vi& nums,int find)
{
    FOR(i,0,nums.size())
    {
        if(nums[i]==find)
            return i;
    }
    return -1;
}
int linsearch_recursive(vi&nums,int& find,int i)
{
    if(i>=nums.size())
    return -1;

    if(nums[i]==find)
    return i;

    return linsearch_recursive(nums,find,i+1);

}
int binsearch_iterative(vi&nums,int find)
{
    int l = 0;
    int r = nums.size()-1;
    int m = l + ((r-l)>>1);
    while(l<=r)
    {
        int m = l + ((r-l)>>1);
        if(nums[m]==find)
        return m;
        if(nums[m]>find)
            r = m-1;
        else
            l=m+1;
    }
    return -1;
}
int binsearch_recursive(vi&nums,int find,int& l,int& r)
{
    if(l>r)
        return -1;
    if(nums[(l + ((r-l)>>1))]==find)
        return l + ((r-l)>>1);

    if(nums[(l + ((r-l)>>1))]>find)
        r = (l + ((r-l)>>1))-1;
    else
        l = (l + ((r-l)>>1))+1;

    return binsearch_recursive(nums,find,l,r);    
}
void result() {
    // Placeholder for result processing function
    int n;
    cout<<"Enter the size of the array \t";
    cin>>n;
    vi nums(n);
    inp(nums,n);

    int searchelement;
    cin>>searchelement;
    int a,b;
    cout<<"1. Linear search Iterative\n2. Linear Search recursive\n3.Binary Search iterative\n4.Binary Search recursive\t";cin>>a;nl
    int l = 0;
    int r =nums.size()-1;
    switch (a)
    {
    case 1:
        b=linsearch_iterative(nums,searchelement);
        break;
    case 2:
        b=linsearch_recursive(nums,searchelement,0);
        break;
    case 3:
        SORT(nums);
        b=binsearch_iterative(nums,searchelement);
        break;
    case 4:
        SORT(nums);
        b=binsearch_recursive(nums,searchelement,l,r);
        break;

    default:
        break;
    }
    cout<<"\n\nResult = "<<b;nl;
}

int main() {
    int tc;
    cin >> tc;
    TC(tc){
        result();
    }
    return 0;
}
