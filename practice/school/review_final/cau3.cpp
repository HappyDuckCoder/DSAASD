#include<iostream>
#include<vector>
#include<string>

#define vi vector<int>         

using namespace std;

void DFS(vector<int> list[], vector<int> &parent, bool &flag, vector<bool> &visited, int u){
    visited[u] = true;

    for(auto i : list[u]){
        if(!visited[i]){
            parent[i] = u;
            DFS(list, parent, flag, visited, i);
        } else {
            if(parent[i] != u) flag = true;
        }
    }

    // flag = false;
}

int main(){
    int V, E; //so dinh, canh
    cin >> V >> E;

    vector<int> list[V]; 
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++){
        parent[i] = i;
    }
    
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);   
    }

    bool flag = false;
    DFS(list, parent, flag, visited, 0);
    flag ? cout << 1 : cout << 0;

    return 0;
}