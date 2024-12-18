#include<iostream>
#include <vector>
using namespace std;
int main(){
    cout<<"hello world\n";
    cout<<"lease insert number of nodes and edeges in graph\n";
    int V, E;
    cin>>V>>E;
    int u,v;
    vector<vector<int>> adj_matrix(V+1,vector<int>(V+1,0));
    for(int i=0;i<E;i++){
        cin>>u>>v;
        adj_matrix[u][v]=1;
        adj_matrix[v][u]=1;

    }
    for(int i=0;i<=V;i++){
        for(int j=0;j<=V;j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}