#include<bits/stdc++.h>
#include<time.h>
#define li long int
using namespace std;


auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


pair<li,clock_t>  euclidgcd1(li a,li b)
{
        clock_t s,e;
        s = clock();
        li temp = a%b;
        li prev=0;
        if(!temp)
        {
                e=clock();
                return {b,e-s};
        }
        while(temp!= 0)
        {
                prev = temp;
                temp = b%temp;
                b= prev;
        }
        e=clock();
        return {prev,(e-s)};

}
li helper(li a, li b)
{

        li temp = a%b;

        if(!temp)
                return b;
        return helper(b,temp);
}


pair<li,clock_t> euclidgcd2(li a,li b)
{
        clock_t s = clock();
        li ab = helper(a,b);
        clock_t e = clock();
        return {ab,(e-s)};
}



void result(){
        li a;
        li b;
        cin>>a>>b;

        auto ab = euclidgcd2(a,b);

        cout<<"\n\nGCD = "<<ab.first;
        cout<<"\ntime taken = "<<ab.second;
}
int main()
{
        int tc;
    cin>>tc;
    while(tc)
    {
        result();
        tc--;
    }

return 0;
}
