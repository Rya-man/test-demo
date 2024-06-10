#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Typedefs
#define ll long long
#define nl cout<<'\n';
#define vi vector<int>
#define vvi vector<vector<int>>
#define us unordered_set
#define um unordered_map
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

void bfs(vector<vector<int>>& adjm,vector<int>&res)
{
    deque<int> q;
    unordered_set<int> vis;
    for(int i =0;i<adjm.size();++i)
    {
        if(!vis.count(i))
        {
            q.push_front(i);
            vis.insert(i);
        }
        while(!q.empty())
        {
            for(auto&i: adjm[q.front()])
            {
                if(!vis.count(i)){
                    q.push_back(i);
                    vis.insert(i);
                }
            }
            res.push_back(q.front());
            q.pop_front();

        }
    }
}

void addedgeundirected(vector<vector<int>>&adjm,int a,int b)
// void addedgedirected(vector<vector<int>>&adjm,int a,int b)
{
    adjm[a].pb(b);
    adjm[b].pb(a);
}
void result(){
    int ver;
    cin>>ver;
    vector<vector<int>> adjm(ver);
    int ed;
    cin>>ed;
    while(ed--)
    {
        int a,b;
        cin>>a>>b;
        addedgeundirected(adjm,a,b);
        // addedgedirected(adjm,a,b);
    }
    unordered_set<int> st;
    vector<int> res;
    bfs(adjm,res);
    show(res);     
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
