#include <utilties.h>
#define tiii tuple<int,int,int>
#define mt make_tuple
#define F get<0>
#define S get<1>
#define T get<2>
inline void insert_edge(int a, int b, int c, vvii& adj) {
   adj[a].pb(mp(c, b));
   adj[b].pb(mp(c, a));
}

void prim(vector<tiii>& res, pq<tiii, vector<tiii>, greater<tiii>>& heap, unordered_set<int>& vis, int i, int& w, vvii& adj) {
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
   vvii adj(V);
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
    TC(tc) {
        result();
    }
    return 0;
}
