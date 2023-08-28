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

    void bfs(int i, int j, int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited){
        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
            for(int k = 0;  k < 4; k++){
                int newi = i + delx[k];
                int newj = j + dely[k];
                if(isValid(newi, newj, row, col, grid) && !visited[newi][newj]){
                    visited[newi][newj] = true;
                    q.push({newi, newj});
                }
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
                    bfs(i, j, row, col, grid, visited);
                }
            }
        }
        return cnt;
    }
};


// TC = O(n^2) * 4 = O(n^2), 
// where O(n^2) is the maxm number of cells for which we can call bfs and for each bfs call we are running loop for 4 times
// and doing constant operation in that loop

// SC = O(n^2) for visited array.



    
