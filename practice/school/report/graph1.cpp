#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> adj, int V, vector<bool> &visited, int i){
    visited[i] = true;
    cout << i << " ";

    for(auto j : adj[i]){
        if(!visited[j]){
            dfs(adj, V, visited, j);
        }
    }
}

int main(){

    int V, E; 
    cin >> V >> E;
    
    vector<vector<int>> adj(V, vector<int> ());

    for(int i = 0; i < E; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(1001, false);

    int cnt = 0;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            cout << "component " << cnt + 1 << ": \n";
            dfs(adj, V, visited, i);
            cout << endl;
            cnt++; 
        }
    }

    cout << "total components: " << cnt << endl;    

    return 0;
}