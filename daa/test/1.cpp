#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

// Typedefs
#define nl cout<<'\n';
typedef vector<int> vi;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
#define ump unordered_map
#define ust unordered_set
#define pq priority_queue
typedef unordered_map<int,int> umpii;
typedef unordered_map<char,int> umpci;
typedef unordered_map<int,bool> umpib;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;

// Debugging
#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif


// Constants
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
double EPS = 1e-9;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

// Macros
#define show(arr) for (auto i: arr) {cout << i << ' ';} cout << "\n"
#define inp(arr,n) for(int i=0;i<n;i++) {cin>> arr[i];}
#define ALL(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

// Fast I/O
auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};//();

// Modular arithmetic
inline LL mod(LL a, LL m) {
    return (a % m + m) % m;
}

// Power function with modulo
inline LL power(LL x, LL y, LL m){
    if (y == 0)
        return 1;
    LL p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

// Prime number check
inline bool isPrime(int n) {
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

//sum of array
inline LL sum_of_array(vi arr,int n)
{
    LL sum =0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    return sum;
}

inline string IntToString(LL a){
    char x[100];
    sprintf(x,"%lld",a); string s = x;
    return s;
}

inline LL StringToInt(string a){
    char x[100]; LL res;
    strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
    return res;
}

inline string GetString(void){
    char x[1000005];
    scanf("%s",x); string s = x;
    return s;
}

inline string uppercase(string s){
    int n = SIZE(s); 
    REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    return s;
}

inline string lowercase(string s){
    int n = SIZE(s); 
    REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    return s;
}


inline void OPEN (string s) {
    #ifndef TESTING
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
    #endif
}

inline int binsearch(vi arr,int a)
{
    int l=0,h=SIZE(arr)-1;
    while(l<=h)        
    {
        int m=l+(h-l)>>1;
        if(arr[m]==a)
            return m;
        else if(arr[m]>a)
            h=m-1;
        else
            l=m+1;
    }
    return -1;
}

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
