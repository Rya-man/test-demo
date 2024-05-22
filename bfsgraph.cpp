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
/*auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();*/

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
vector<int> res;
void dfs(vector<vector<int>>& adjm, int c, um<int,bool>& visited)
{
    res.pb(c);
    visited[c]=true;
    for(auto&i:adjm[c])
    {
        if(!visited[i])
            dfs(adjm,i,visited);
    }
}

void result() {
    queue<int> q;
    int n, ab;
    unordered_set<int> vis;
    vector<int> res;
    cout << "\nEnter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n);

    cout << "\nEnter the number of edges: ";
    cin >> ab;

    cout << "\nAdd edges to the graph:\n";
    for (int i = 0; i < ab; ++i) {
        int a1, a2;
        cin >> a1 >> a2;
        adj[a1].pb(a2);
        adj[a2].pb(a1);
    }

    q.push(0);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (!vis.count(curr)) {
            vis.insert(curr);
            res.push_back(curr);
            for (int i : adj[curr]) {
                if (!vis.count(i)) {
                    q.push(i);
                }
            }
        }
    }
    cout<<"\n\n";
    show(res);

}




int main() {

    int tc;
    cout<<"\nEnter the number of testcases: ";
    cin>>tc;
    while(tc)
    {
        result();
        tc--;
    }

    // Your code here

    return 0;
}
