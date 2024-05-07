#include<time.h>
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Typedefs
#define ll long long
#define nl cout<<'\n';
#define vi vector<int>
#define pii pair<int, int>

// Constants
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// Macros
#define show(arr) for (auto i: arr) {cout << i << ' ';} cout << "\n"
#define inp(arr,n) for(int i=0;i<n;i++) {cin>> arr[i];}
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
// Debugging
#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// Fast I/O
auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Modular arithmetic
ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// Power function with modulo
ll power(ll x, ll y, ll m){
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

// Prime number check
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

ll sum_of_array(vi arr,int n)
{
    ll sum =0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}

pair<int,double> linsearch1(vi arr,int n)
{
        clock_t s = clock();
        for(int i =0;i<arr.size();++i)
                if(arr[i]==n)
                {
                        clock_t e = clock();
                        return {i,(e-s)};
                }
        clock_t e =clock();
        return {-1,(e-s)};
}
int helper(vi& arr,int n,int a)
{
        if(a>=arr.size())
                return -1;
        if(arr[a]==n)
                return a;
        return helper(arr,n,a+1);
}
pair<int,double> linsearch2(vi arr,int n)
{
        clock_t s = clock();
        int res =helper(arr,n,0);
        clock_t e = clock();
        return {res,(e-s)};
}

void result(){
        int arrsize;
        cin>>arrsize;
        vi arr(arrsize);
        int num;
        inp(arr,arr.size());
        cin>>num;
        //auto res = linsearch1(arr,num);
        auto res = linsearch2(arr,num);
        cout<<"\nposition of "<<num<<" : \t"<<res.F;
        cout<<"\n time taken : \t"<<res.S;

}

int main() {

    int tc;
    cin>>tc;
    while(tc)
    {
        result();
        tc--;
    }
 return 0;
}


