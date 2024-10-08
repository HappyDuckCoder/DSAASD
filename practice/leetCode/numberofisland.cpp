#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // trai - len - phai - xuong
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};
    vector<vector<bool>> visited;

    void DFS(vector<vector<char>> &grid, int i, int j){
        visited[i][j] = true;

        for(int k = 0; k < 4; k++){
            int i1 = i + x[k];
            int j1 = j + y[k];
            if(i1 >= 0 && i1 < grid.size() && j1 >= 0 && j1 < grid[0].size() && !visited[i1][j1] && grid[i1][j1] == '1'){
                DFS(grid, i1, j1);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        visited.assign(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    DFS(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution s;
    int cnt = s.numIslands(grid);

    cout << cnt;

    return 0;
}