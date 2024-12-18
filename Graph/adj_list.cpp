#include<iostream>
#include <vector>
using namespace std;

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
    for(int i=0;i<=V;i++){
        cout<<i<<" ->";
        for(auto node:adj_list[i]){
            cout<<node<<" ";
        }
        cout<<"\n";
    }
    return 0;
}