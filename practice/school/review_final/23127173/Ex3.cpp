#include<iostream>
#include<vector>

using namespace std;

// Function to perform DFS and count all paths from source to destination
void DFS(const vector<vector<int>> &list, int S, int D, vector<bool> &visited, int &cnt) {
    visited[S] = true;

    if(S == D) {
        cnt++;
    } else {
        for(int i = 0; i < list[S].size(); i++) {
            int next = list[S][i];
            if(!visited[next]) {
                DFS(list, next, D, visited, cnt);
            }
        }
    }

    visited[S] = false;
}

int countPaths(const vector<vector<int>> &list, int V, int S, int D) {
    vector<bool> visited(V, false);
    int cnt = 0;

    // Start DFS from the source
    DFS(list, S, D, visited, cnt);

    return cnt;
}

int main() {
    int V, E, S, D;
    cin >> V >> E >> S >> D;

    vector<vector<int>> list(V);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    cout << countPaths(list, V, S, D) << endl;

    return 0;
}
