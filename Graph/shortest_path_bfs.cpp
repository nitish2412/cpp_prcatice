#include<iostream>
#include <vector>
#include <queue>
using namespace std;

// assumption of this graph is node start with 1 not 0, if start with 0 we should adjust index;
//both function will work but this is more consise.
vector<int> shortestPath(vector<vector<int>> &adj, int src) {
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> distance(n, INT16_MAX); // Use INT_MAX for standard practice
    queue<int> q;

    // Start BFS from the source node
    q.push(src);
    visited[src] = 1;
    distance[src] = 0; // Distance to the source node is 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Process each neighbor of the current node
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                distance[neighbor] = distance[node] + 1; // Update distance
                q.push(neighbor);
            }
        }
    }

    return distance;
}
// this function also work but in this some reduant check and no need to store pair also.
vector<int> shortestPath(vector<vector<int>> &adj, int src){

    int n=adj.size();
    vector<int> visited(n,0);
    vector<int> distance(n,INT16_MAX);
    queue<pair<int,int>> q;
    q.push({src,0});
    visited[src]=1;
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(dist<distance[node]){
            distance[node]=dist;
        }
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                q.push({neighbor,dist+1});
                visited[neighbor]=1;
            }
        }
    }

    return distance;
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
    vector<int> res=shortestPath(adj_list,1);
    for(auto node:res){
        cout<<node<<" ";
    }
    cout<<"\n";
    return 0;
}