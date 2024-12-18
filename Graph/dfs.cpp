#include<iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node,vector<vector<int>> &adj, vector<int> &visited, vector<int> &res){

    visited[node]=1;
    res.push_back(node);
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor,adj,visited,res);
        }
    }
   
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
    int n=adj_list.size();
    vector<int> res;
    vector<int> visited(n,0);
    
    for(int i=1;i<n;i++){
        if(!visited[i]){
            dfs(i,adj_list,visited,res);
        }
    }
    
    for(auto node:res){
        cout<<node<<" ";
    }
    cout<<"\n";
    return 0;
}