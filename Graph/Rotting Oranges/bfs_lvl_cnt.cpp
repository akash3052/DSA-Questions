class Solution {
public:
    vector<int> delx = {0, 0, -1, +1};
    vector<int> dely = {-1, +1, 0, 0};
    bool isValid(int i, int j, int row, int col){
        if(i < 0 || j < 0 || i >= row || j >= col){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        int time = 0;
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        while(!q.empty()){
            int qsize = q.size();
            if(!freshOranges){
                return time;
            }
            while(qsize--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int newi = i + delx[k];
                    int newj = j + dely[k];
                    // we are not using visited array because we are already changing grid[newi][newj] = 2. So, basically 
                    // we are marking them visited.
                    if(isValid(newi, newj, row, col) && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        freshOranges--;
                        q.push({newi, newj});
                    }
                }
            }
            // Note -> Basically we are counting number of levels.
            time++;
        }
        return freshOranges ? -1 : time;
    }
};


// TC = O(row * col) * 4 = O(row*col) 
// Here, we are visiting every cells at most one time and for each cell, we are running a for loop of size 4.

// SC = O(1) 
// beacuse we are not using extra space for visited array, we are using grid only and changing the value in grid only.
// Ideally we should not alter input data.




