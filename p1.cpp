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


pair<li,double>  euclidgcd1(li a,li b)
{
        clock_t s,e;
        s = clock();
        li temp = a%b;
        li prev=0;
        if(!temp)
        {
                e=clock();
                return {b,double((e-s)/(CLOCKS_PER_SEC*1000))};
        }
        while(temp!= 0)
        {
                prev = temp;
                temp = b%temp;
                b= prev;
        }
        e=clock();
        return {prev,double((e-s)/(CLOCKS_PER_SEC*1000))};

}
li helper(li a, li b)
{

        li temp = a%b;

        if(!temp)
                return b;
        return helper(b,temp);
}


pair<li,double> euclidgcd2(li a,li b)
{
        clock_t s = clock();
        li ab = helper(a,b);
        clock_t e = clock();
        return {ab,double((e-s)/(CLOCKS_PER_SEC*1000))};
}

pair<li,double> euclid3(li a,li b)
{
        clock_t s = clock();
        int t = b;
        if(!(a%t))
                return t;

        for(int i = t;i>0;--i)
        {
                if(!(a%i) and !(b%i))
                {
                        clock_t e = clock();
                        return {i,double((e-s)/(CLOCKS_PER_SEC*1000))};
                }
        }
        clock_t e = clock();
        return {1,double((e-s)/(CLOCKS_PER_SEC*1000))};
}

void result(){
        li a;
        li b;
        cin>>a>>b;
        if(b>a)
        {
                auto temp = a;
                a=b;
                b=temp;
        }
        //auto ab = euclidgcd1(a,b);
        //auto ab = euclidgcd2(a,b);
        //auto ab = euclid3(a,b);
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
