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
    void dfs(int i, int j, int row, int col, int oldColor, int newColor, vector<vector<int>> &image){
        image[i][j] = newColor;
        for(int k = 0; k < 4; k++){
            int newi = i + delx[k];
            int newj = j + dely[k];
            // note -> instead of !visited[newi][newj], we are image[newi][newj] != newColor because if it's value is newColor, it means we have already visited that node previously.
            if(isValid(newi, newj, row, col) && image[newi][newj] != newColor && image[newi][newj] == oldColor){
                dfs(newi, newj, row, col, oldColor, newColor, image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int oldColor = image[sr][sc];
        dfs(sr, sc, row, col, oldColor, color, image);
        return image;
    }
};

// TC = O(row*col)
// SC = O(row*col)

