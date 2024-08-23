#include <utilties.h>

void dfs(vi& res,usi& vis,vvi&adj,int i)
{
    if(vis.count(i))
    return;

    res.pb(i);
    vis.insert(i);
    
    for(int it = 0;it<adj[i].size();++it)
        dfs(res,vis,adj,adj[i][it]);
}
void result() {
    // Placeholder for result processing function
    int V;
    int E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    while(E)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        E--;
    }
    usi vis;
    vi res;
    dfs(res,vis,adj,0);

    if(res.size()==V){
        yes;}
    else{
        no;
    }
    show(res);

}

int main() {
    int tc;
    cin >> tc;
    TC(tc){
        result();
    }
    return 0;
}
