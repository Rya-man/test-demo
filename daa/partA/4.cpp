#include<utilties.h>
int partition(vi& nums,int l,int h)
{
    int pv = nums[h];
    int i =l-1;
    for(int j= l;j<=h;++j)
        if(nums[j]<pv)
        {
            i++;
            swap(nums[i],nums[j]);
        }
    swap(nums[i+1],nums[h]);
    return i+1;
}
void quicksort(vi& nums,int l,int h)
{
    if(l<h)
    {
        int pi = partition(nums,l,h);
        quicksort(nums,l,pi-1);
        quicksort(nums,pi+1,h);
    }
}
void result(){
    int n;
    cin>>n;
    vi nums(n);
    inp(nums,nums.size());
    quicksort(nums,0,nums.size()-1);
    cout<<'\n';
    show(nums);
} 


int main() {


    int tc;
    cin>>tc;
    while(tc)
    {
        result();
        tc--;
    }


    // Your code here


    return 0;
}
