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
        queue<pair<pair<int,int>,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0){
            return 0;
        }
        int maxTime = -1;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            maxTime = max(time, maxTime);
            for(int k = 0; k < 4; k++){
                int newi = i + delx[k];
                int newj = j + dely[k];
                if(isValid(newi, newj, row, col) && grid[newi][newj] == 1){
                    grid[newi][newj] = 2;
                    freshOranges--;
                    q.push({{newi, newj}, time+1});
                }
            }
        }
        return freshOranges ? -1 : maxTime;
    }
};


// TC = O(row*col)
// SC = O(1) , since we are not using visited array.

  
