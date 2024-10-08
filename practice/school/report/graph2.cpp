#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> adj, int V, vector<bool> &visited, int S, int D, int &cnt){
    visited[S] = true;

    if(S == D) cnt++;
    else{
        for(auto j : adj[S]){
            if(!visited[j]){
                dfs(adj, V, visited, j, D, cnt);
            }
        }
    }

    visited[S] = false;
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

    int S, D; 
    cin >> S >> D;

    vector<bool> visited(1001, false);

    int cnt = 0;
    dfs(adj, V, visited, S, D, cnt);

    cout << "total path: " << cnt << endl;    

    return 0;
}