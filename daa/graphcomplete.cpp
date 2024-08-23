#include<utilties.h>
class Graph{
public:
    int V;
    int E;
    vector<vector<pair<int,int>>> adj;
    Graph(int num=1){
        V=num;
        adj.resize(V);
        E=0;
    }
    Graph(int num,vvii& adj)
    {
        V=num;
        E=0;
        this->adj = adj;
    }

    void add_edges_bidirectional_not_weighted(int E){
        this->E = E;
        while(E)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back({b,0});
            adj[b].push_back({a,0});
            E--;
        }
    }

    void add_edges_unidirectional_not_weighted(int E){
        this->E = E;
        while(E)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back({b,0});
            E--;
        }
    }

    void add_edges_bidirectional_weighted(int E){
        this->E = E;
        while(E)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            E--;
        }
    }

    void add_edges_unidirectional_weighted(int E){
        this->E = E;
        while(E)
        {
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            E--;
        }
    }

    void dfs(vi& res,ust<int>& s,int vertex)
    {
        if(s.count(vertex))
        return;

        s.insert(vertex);
        res.push_back(vertex);
        
        for(int i =0;i<adj[vertex].size();++i)
            dfs(res,s,adj[vertex][i].F);
    }

    void bfs(vi& res,usi& vis,int v)
    {
        if(vis.count(v))
            return;
        
        queue<int> q;
        q.push(v);
        vis.insert(v);
        while(!q.empty())
        {
            for(int i =0;i<adj[q.front()].size();++i)
            {
                if(!vis.count(adj[q.front()][i].F))
                {
                    q.push(adj[q.front()][i].F);
                    vis.insert(adj[q.front()][i].F);
                }
                
            }
            res.push_back(q.front());
            q.pop();
        }
        
    }

    void TopologicalSort(vi&s,usi& vis,int v)
    {
        if(vis.count(v))
            return;
        
        vis.insert(v);
        for(int i =0;i<adj[v].size();++i)
            TopologicalSort(s,vis,adj[v][i].F);
        s.push_back(v);
        
    }

};

void result(){
    int V,E,ch;
    cout<<"Enter the number of vertices  ";
    cin>>V;nl;
    Graph* G = new Graph(V);
    cout<<"Enter the number of edges and the type of graph to create :";nl;
    cout<<"1. Bidirectional Weighted\n2. Bidirectional not Weighted\n3. Unidirectional Weighted\n4. Unidirectional not Weighted";nl;
    cin>>E>>ch;
    cout<<"Add edges in this format \tA B (weight)\n(skip weight if not needed)\n";
    switch (ch)
    {
        case 1:
            G->add_edges_bidirectional_weighted(E);
            break;
        case 2:
            G->add_edges_bidirectional_not_weighted(E);
            break;
        case 3:
            G->add_edges_unidirectional_weighted(E);
            break;
        case 4:
            G->add_edges_unidirectional_not_weighted(E);
            break;
        default:
            break;
    }
    nl nl nl nl nl
    cout<<"*************************************************menu*************************************************";nl;
    cout<<"1. DFS \n2. BFS\n3.Topological Sort\n4. Dijkstra\n5. Prim's Algorithm\n6. Floyd Warshall's Algorithm";nl;
    cout<<"******************************************************************************************************";nl;
    cin>> ch;
    
    switch(ch)
    {
        case 1:{
            int v;
            vector<int> res;
            unordered_set<int> vis;
            cout<<"ENter the first vertex \t";cin>>v;
            
            int i =v;
            do{
                G->dfs(res,vis,i);
                i = (i+1)%G->V;
            }while(i!=v);
            
            cout<<"\nresult = \t";
            show(res);
            break;
        }
        case 2:{
            int v;
            vector<int> res;
            unordered_set<int> vis;
            cout<<"Enter the first vertex \t";cin>>v;
            
            int i =v;
            do{
                G->bfs(res,vis,i);
                i = (i+1)%G->V;
            }while(i!=v);

            cout<<"\nresult = \t";
            show(res);
            break;
        }
        case 3:{
            int v;
            vector<int> res;
            unordered_set<int> vis;
            cout<<"Enter the first vertex \t";cin>>v;
            
            int i =v;
            do{
                G->TopologicalSort(res,vis,i);
                i = (i+1)%G->V;
            }while(i!=v);

            cout<<"\nresult = \t";
            REVERSE(res);
            show(res);
            break;
        }
        // case 4:
            // G->add_edges_unidirectional_not_weighted(E);
            // break;
        default:
            break;
    }

}

int main() {

    int tc;
    cin>>tc;
    TC(tc)
    {
        result();
    }
    return 0;
}
