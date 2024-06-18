#include <bits/stdc++.h>
#include <time.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Typedefs
#define ll long long
#define nl cout << '\n';
#define vi vector<int>
#define pii pair<int, int>

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
#define F first
#define S second
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

inline void insert_edges(int a, int b, vector<vector<pair<int, int>>>& adj, int c) {
    adj[a].pb(mp(b, c));
    adj[b].pb(mp(a, c));
}

void prim(vector<pii>& res, unordered_set<int>& vis, int i, vector<vector<pii>>& adj, int& weight, priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>& pq) {
    vis.insert(i);
    for (auto [to, cost] : adj[i]) {
        if (!vis.count(to)) {
            pq.push(make_tuple(cost, i, to));
        }
    }

    while (!pq.empty()) {
        auto [cost, from, to] = pq.top();
        pq.pop();
        if (!vis.count(to)) {
            vis.insert(to);
            res.pb(mp(from, to));
            weight += cost;
            for (auto [next, next_cost] : adj[to]) {
                if (!vis.count(next)) {
                    pq.push(make_tuple(next_cost, to, next));
                }
            }
        }
    }
}

void result() {
    int n;
    cout << "Enter the number of vertices\t";
    cin >> n;
    vector<vector<pii>> adj(n);
    int e;
    cout << "\nEnter the number of edges\t";
    cin >> e;
    cout << "\nEnter all edges with weights (format: a b c)\n";
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        insert_edges(a, b, adj, c);
    }

    vector<pii> res;
    int weight = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    unordered_set<int> vis;

    for (int i = 0; i < n; ++i) {
        if (!vis.count(i)) {
            prim(res, vis, i, adj, weight, pq);
        }
    }

    cout << "\nMinimum Spanning Tree edges:\n";
    for (auto i : res) {
        cout << i.F << " -> " << i.S << '\n';
    }

    cout << "\nTotal weight = " << weight << "\n\n";
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        result();
    }
    return 0;
}
