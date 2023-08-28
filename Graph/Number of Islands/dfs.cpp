class Solution {
public:
    vector<int> delx = {0, -1, 0, 1};
    vector<int> dely = {-1, 0, 1, 0};
    bool isValid(int i, int j, int row, int col, vector<vector<char>> &grid){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0'){
            return false;
        }
        return true;
    }

    void dfs(int i, int j, int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited){
        visited[i][j] = true;
        for(int k = 0;  k < 4; k++){
            int newi = i + delx[k];
            int newj = j + dely[k];
            if(isValid(newi, newj, row, col, grid) && !visited[newi][newj]){
                dfs(newi, newj, row, col, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int cnt = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, row, col, grid, visited);
                }
            }
        }
        return cnt;
    }
};


