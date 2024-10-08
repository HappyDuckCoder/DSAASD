#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> // for reverse()

#define vi vector<int> 
#define vii vector<vector<int>>  
#define vb vector<bool>

using namespace std;

// Print the list of directly connected city pairs
void printListDirectConnected(const vii &adj, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(adj[i][j] != 0){
                cout << i << "->" << j << "\n";
            }
        }
    }
}

// Find the path with the fewest cities from S to D
void printMinRoadFromStoD(int S, int D, const vii &adj, int n){
    vb visited(n, false);
    vi parent(n, -1);
    queue<int> qu;
    qu.push(S);
    visited[S] = true;

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        if(u == D){
            // If destination is reached, print the path
            vi path;

            for(int v = D; v != -1; v = parent[v]){
                path.push_back(v);
            }
            reverse(path.begin(), path.end());

            cout << "Shortest path from " << S << " to " << D << " is: ";

            for(int v : path){
                cout << v << "->";
            }

            cout << path.size() - 1 << endl;

            return;
        }

        for(int i = 0; i < n; i++){
            if(adj[u][i] != 0 && !visited[i]){
                qu.push(i);
                visited[i] = true;
                parent[i] = u;
            }
        }
    }
}

void totalRoadFromStoD(int S, int D, const vii &adj, int n, vb &visited, int &cnt){
    visited[S] = true;

    if(S == D){
        cnt++;
    } else {
        for(int v = 0; v < adj[S].size(); v++){
            if(adj[S][v] != 0 && !visited[v]){
                totalRoadFromStoD(v, D, adj, n, visited, cnt);
            }
        }
    }

    visited[S] = false;
}


int main(){
    int n; 
    cin >> n;
    vii adj(n, vi(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }

    printListDirectConnected(adj, n);

    int S, D; 
    cin >> S >> D;
    
    printMinRoadFromStoD(S, D, adj, n);

    vb visited(1001, false);
    int cnt = 0;
    totalRoadFromStoD(S, D, adj, n, visited, cnt);

    cout << cnt << "\n";

    return 0;
}
