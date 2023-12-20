#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    int Vertix;
    vector<list<int>> adj;

    public:
    Graph(int V)
    {
        Vertix = V;
        adj.resize(V);
    }
    void addEdge(int v,int w);
    void BFS(int s);
};
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(Vertix,false);

    list<int> queue;

    visited[s]=true;
    queue.push_back(s);

    while(!queue.empty())
    {
        s=queue.front();
        cout<< s<<' ';
        queue.pop_front();
         
    }
}
