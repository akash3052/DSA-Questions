class Solution {
  public:
    void dfs(int i, int j, int row, int col, vector<vector<char>>& grid, vector<vector<int>> &visited){
        visited[i][j] = true;
        // delx can vary from -1 to +1 and same for dely. So, total there will be 9 cases.
        // in which (0,0) will be eliminated because it will be already visited.
        for(int delx = -1; delx <= 1; delx++){
            for(int dely = -1; dely <=1 ; dely++){
                int newi = i + delx;
                int newj = j + dely;
                if(newi >= 0  && newi <= row-1 && newj >= 0 && newj <= col-1 && grid[newi][newj] == '1' && !visited[newi][newj]){
                    dfs(newi, newj, row, col, grid, visited);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col,0));
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

// TC = O(n^2)
// SC = O(n^2)

  
