#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// assumption of this graph is node start with 1 not 0, if start with 0 we should adjust index;
vector<int> bfs(vector<vector<int>> &adj, int src){

    int n=adj.size();
    vector<int> visited(n,0);
    vector<int> res;
    queue<int> q;
    q.push(src);
    visited[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor]=1;
            }
        }
    }

    return res;
}

int main(){
    cout<<"Hello world\n";
    int V,E;
    cout<<"Please insert number of nodes and edges in graph\n";
    cin>>V>>E;
    vector<vector<int>> adj_list(V+1);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    vector<int> res=bfs(adj_list,1);
    for(auto node:res){
        cout<<node<<" ";
    }
    cout<<"\n";
    return 0;
}