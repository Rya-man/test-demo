#include <utilties.h>

void result() {
    // Placeholder for result processing function
    int V,E;
    cin>> V;
    cin>> E; 
    vector<vector<int>> adj(V);
    while(E)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        E--;
    }

    int starting_node;
    cin>>starting_node;
    vector<int> res;
    queue<int> q;
    usi vis;

    
    int starting_node;
    cin>>starting_node;
    int x = starting_node;
    do{
        if(vis.count(x))
        continue;
        q.push(starting_node);
        vis.insert(starting_node);
        while(!q.empty())
        {
            for(int i =0;i<adj[q.front()].size();++i)
            {
                if(!vis.count(adj[q.front()][i]))
                {
                    vis.insert(adj[q.front()][i]);
                    q.push(adj[q.front()][i]);
                }
            }
            res.pb(q.front());
            q.pop();
        }
        x++;
    }while(x!=starting_node);
    nl;show(res);nl

}

int main() {
    int tc;
    cin >> tc;
    TC(tc){
        result();
    }
    return 0;
}
