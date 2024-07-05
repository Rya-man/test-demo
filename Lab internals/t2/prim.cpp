#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Typedefs
#define ll long long
#define nl cout << '\n';
#define vi vector<int>
#define pii pair<int, int>
#define vvpii vector<vector<pair<int,int>>>
#define tiii tuple<int,int,int>
#define pq priority_queue

// Constants
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// Macros
#define show(arr) for (auto i : arr) { cout << i << ' '; } cout << "\n"
#define inp(arr, n) for (int i = 0; i < n; i++) { cin >> arr[i]; }
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F get<0>
#define S get<1>
#define T get<2>
#define yes cout << "YES\n";
#define no cout << "NO\n";

// Debugging
#ifdef LOCAL_DEBUG
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

// Fast I/O
// auto initialize = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();

// Modular arithmetic
ll mod(ll a, ll m) {
   return (a % m + m) % m;
}

// Power function with modulo
ll power(ll x, ll y, ll m) {
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

ll sum_of_array(vi arr, int n) {
   ll sum = 0;
   for (int i = 0; i < n; i++)
       sum += arr[i];
   return sum;
}

inline void insert_edge(int a, int b, int c, vvpii& adj) {
   adj[a].pb(mp(c, b));
   adj[b].pb(mp(c, a));
}

void prim(vector<tiii>& res, pq<tiii, vector<tiii>, greater<tiii>>& heap, unordered_set<int>& vis, int i, int& w, vvpii& adj) {
   vis.insert(i);
   for (auto &[cost, to] : adj[i]) {
       if (!vis.count(to)) {
           heap.push(mt(cost, i, to));
       }
   }

   while (!heap.empty()) {
       auto [cost, from, to] = heap.top();
       heap.pop();
       if (!vis.count(to)) {
           vis.insert(to);
           res.pb(mt(cost, from, to));
           w += cost;
           prim(res, heap, vis, to, w, adj);
       }
   }
}

void result() {
   int V, E;
   cout << "\nEnter the number of vertices ";
   cin >> V;
   cout << "\nEnter the number of edges ";
   cin >> E;
   vvpii adj(V);
   cout << "Enter all the edges in this format \t V1 V2 Weight:\n";
   while (E--) {
       int a, b, c;
       cin >> a >> b >> c;
       insert_edge(a, b, c, adj);
   }

   vector<tiii> res;
   int w = 0;
   pq<tiii, vector<tiii>, greater<tiii>> heap;
   unordered_set<int> vis;
   for (int i = 0; i < V; ++i) {
       if (!vis.count(i)) {
           prim(res, heap, vis, i, w, adj);
       }
   }
   cout << "\nMinimum Spanning Tree edges:\n";
   cout << "V1 -> V2\tWeight\n";
   for (auto &i : res) {
       cout << S(i) << " -> " << T(i) << "\t" << F(i) << '\n';
   }
   cout << "Total weight: " << w << '\n';
}

int main() {
   int tc;
   cin >> tc;
   while (tc--) {
       result();
   }
   return 0;
}

