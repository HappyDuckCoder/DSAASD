#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

char a[100][100];
bool visited[100][100];
int dp[100][100]; 
pii parent[100][100]; 
int n;
int pos1, pos2;
int pos3, pos4;

void init(){
    cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) cin >> a[i][j];
    memset(visited, false, sizeof(visited));
    FOR(i, 0, 100) FOR(j, 0, 100) dp[i][j] = INT_MAX;

    cin >> pos1 >> pos2;
    cin >> pos3 >> pos4;
}

void dfs(int x, int y, int dist){
    if(dp[x][y] <= dist) return;
    dp[x][y] = dist;
    
    visited[x][y] = true;

    FOR(i, 0, 4){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && !visited[x1][y1] && (a[x1][y1] == 'x' || (x1 == pos3 && y1 == pos4))){
            parent[x1][y1] = {x, y};
            dfs(x1, y1, dist + 1);
        }
    }

    visited[x][y] = false;  
}

int minRoadDFS(){
    dfs(pos1, pos2, 0);
    return (dp[pos3][pos4] == INT_MAX) ? -1 : dp[pos3][pos4];
}

void printPath(){
    vector<pii> path;
    int x = pos3, y = pos4;

    while(!(x == pos1 && y == pos2)) {
        path.push_back({x, y});
        pii p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    path.push_back({pos1, pos2});

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (auto p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main(){
    init();

    int result = minRoadDFS();
    if(result != -1) {
        cout << "Minimum distance: " << result << endl;
        printPath();
    } else {
        cout << "No path found" << endl;
    }

    return 0;
}
