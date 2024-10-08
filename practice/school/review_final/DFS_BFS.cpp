#include<iostream>
#include<vector> 
#include<queue>

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vb vector<bool> 

using namespace std;

int V, E;
vb visited(1001, false);
vi adj[1001];

void init(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
} 

void DFS(int u){
    cout << u << " ";

    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v]) 
            DFS(v);
}

void BFS(int u){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;

    while(!qu.empty()){
        int size = qu.size();
        while(size--){
            int tmp = qu.front();
            qu.pop();

            cout << tmp << " ";

            for(auto i : adj[tmp]){
                if(!visited[i]){
                    qu.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << "\n";
    }
}

int component(){
    int cnt = 0;
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            cout << "component " << cnt + 1 << ": ";
            DFS(i);
            cnt++; 
            cout << endl;
        }
    }

    return cnt;
}

int main(){
    init();
    cout << component();

    return 0;
}