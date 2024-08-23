#include <utilties.h>

// Dijkstra's algorithm function for Shortest Path
void dijkstra(int src, vector<int>& dist, vector<int>& parent, vector<vector<pair<int, int>>>& adj) {
   int n = dist.size();
   priority_queue<pii, vector<pii>, greater<pii>> pq;
   dist[src] = 0;
   parent[src] = -1;
   pq.push({0, src});
  
   while (!pq.empty()) {
       int d = pq.top().first;
       int u = pq.top().second;
       pq.pop();
      
       if (d > dist[u]) continue;
      
       for (auto& edge : adj[u]) {
           int v = edge.first;
           int weight = edge.second;
           if (dist[u] + weight < dist[v]) {
               dist[v] = dist[u] + weight;
               parent[v] = u;
               pq.push({dist[v], v});
           }
       }
   }
}

// Function to insert edges into the adjacency list
void insert_edges(int a, int b, vvii& adj, int c) {
    adj[a].pb({b, c});
    adj[b].pb({a, c});  
}

// Function to print the path from source to a vertex
void print_path(int v, vector<int>& parent) {
    if (v == -1)
        return;
    print_path(parent[v], parent);
    cout << v << " ";
}

// Function to handle the test case
void result() {
   int n;
   cout << "Enter the number of vertices: ";
   cin >> n;
   vvii adj(n);
   int e;
   cout << "\nEnter the number of edges: ";
   cin >> e;
   cout << "\nEnter all edges with weights (format: a b c)\n";
   while (e--) {
       int a, b, c;
       cin >> a >> b >> c;
       insert_edges(a, b, adj, c);
   }
   
   int src;
   cout << "\nEnter source vertex for Dijkstra's Algorithm: ";
   cin >> src;
   
   vector<int> dist_dijkstra(n, INF);
   vector<int> parent(n, -1);
   dijkstra(src, dist_dijkstra, parent, adj);

   cout << "\nShortest distances from vertex " << src << ":\n";
   for (int i = 0; i < n; ++i) {
       cout << "Vertex " << i << ": Distance = " << dist_dijkstra[i] << ", Path = ";
       print_path(i, parent);
       nl
   }
}

int main() {
   int tc;
   cout << "Enter number of test cases: ";
   cin >> tc;
   while (tc--) {
       result();
   }
   return 0;
}
