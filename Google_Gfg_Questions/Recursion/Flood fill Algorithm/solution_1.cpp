class Solution {
public:
   int row , col;
    vector<int> delx = {0, 0, -1, 1};
    vector<int> dely = {-1, 1, 0, 0};
    vector<vector<int>> visited;
    
    bool isValid(int i, int j){
        if(i<0 || j<0 || i>=row || j>=col)
            return false;
        return true;
    }
    
    // Note -> Initially I was not using visited array but it will give error when both oldColor and newColor will be same.
    // If oldColor and newColor will not be same, then we can solve this question without using visited array.
    void solve(vector<vector<int>> &image, int i, int j, int newColor, int oldColor, vector<vector<int>> &visited){
        image[i][j] = newColor;
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int newi = i + delx[k];
            int newj = j + dely[k];
            if(isValid(newi, newj) && image[newi][newj] == oldColor && !visited[newi][newj]){
                solve(image, newi, newj, newColor, oldColor, visited);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        row = image.size(), col = image[0].size();
        vector<vector<int>> visited(row,vector<int>(col));
        solve(image, sr, sc, newColor, oldColor, visited);
        return image;
    }
};
