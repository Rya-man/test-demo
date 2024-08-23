#include <utilties.h>

void dijkstra(vvii& adj,vi& dist,int src){
    pq<pii,vii,greater<pii>> p;
    p.push({dist[src],src});

    while(!p.empty())
    {
        int current_weight = p.top().F;
        int current_vertex = p.top().S;
        p.pop();

        if(current_weight > dist[current_vertex])
        continue;

        for(auto it = adj[current_vertex].begin();it!=adj[current_vertex].end();++it)
        {
            int next_vertex = it->second;
            int next_weight = it->first;

            if(next_weight + dist[current_vertex] < dist[next_vertex]){
                dist[next_vertex] = next_weight + dist[current_vertex];
                p.push({dist[next_vertex],next_vertex});
            }
        }
    }
}
void result() {
    int V,E;
    cin>>V>>E;
    cout<<"Enter E edges in this format (a b w)\n";
    vvii adj(V);
    while(E)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({c,b});
        adj[b].pb({c,a});
        E--;
    }
    vector<int> dist(V,INF);
    int a;
    cout<<"Enter the source vertex\t";
    cin>>a;
    dist[a]=0;

    dijkstra(adj,dist,a);

    cout << "\nShortest distances from vertex " << a << ":\n";
       for (int i = 0; i < V; ++i) {
           cout << "Vertex " << i << ": Distance = " << dist[i] << ", Path = ";
       	   nl    
       }
}

int main() {
    int tc;
    cin >> tc;
    TC(tc){
        result();
    }
    return 0;
}
