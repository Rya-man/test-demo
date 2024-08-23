#include <utilties.h>

void topo(vi& res,usi& vis,vvi& adj,int i)
{
    if(vis.count(i))
    return;

    vis.insert(i);
    for(int j =0;j<adj[i].size();++j)
    {
        topo(res,vis,adj,adj[i][j]);
    }
    res.pb(i);
}
void result() {
    // Placeholder for result processing function
    int V;int E;
    cin>>V>>E;
    vvi adj(V);
    while(E)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        E--;
    }

    vi st;
    usi vis;
    
    auto start_time = clock();
    topo(st,vis,adj,0);
    auto end_time = clock();


    REVERSE(st);

    show(st);
    cout<<"\n\n\n Time complexity = "<<double(end_time-start_time)/CLOCKS_PER_SEC*1000;nl
}

int main() {
    int tc;
    cin >> tc;
    TC(tc){
        result();
    }
    return 0;
}
