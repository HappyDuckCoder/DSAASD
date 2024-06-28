#include<iostream>
#include<cstring>
#include<queue> 

using namespace std;

char a[100][100];
bool visited[100][100];
int n;

int dx[4] = {-1, 0, 1, 0};
int dy[4] ={0, -1, 0, 1};

void init(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    memset(visited, false, sizeof(visited));
}

void dfs(int x, int y){
    visited[x][y] = true;
    cout << "(" << x << ", " << y << ") \n";
    for(int i = 0; i < 4; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && !visited[x1][y1] && a[x1][y1] == 'x'){
            dfs(x1, y1);
        }
    }
}

int Dem_Lien_Thong_DFS(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'x' && !visited[i][j]){
                cout << "thanh phan lien thong thu " << cnt + 1 << " : \n";
                dfs(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        cout << "(" << x << ", " << y << ") \n";
        q.pop();
        for(int i = 0; i < 4; i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && !visited[x1][y1] && a[x1][y1] == 'x'){
                q.push({x1,y1});
                visited[x1][y1] = true;
            }
        } 
    }
}

int Dem_Lien_Thong_BFS(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'x' && !visited[i][j]){
                cout << "thanh phan lien thong thu " << cnt + 1 << " : \n";
                bfs(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){

    //init();
    //cout << Dem_Lien_Thong_DFS();

    init();
    cout << Dem_Lien_Thong_BFS();

    return 0;
}