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
    void bfs(int i, int j, int row, int col, int oldColor, int newColor, vector<vector<int>> &image){
        image[i][j] = newColor;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int newi = i + delx[k];
                int newj = j + dely[k];
                // note -> instead of !visited[newi][newj], we are image[newi][newj] != newColor because if it's value is newColor, it means we have already visited that node previously.
                if(isValid(newi, newj, row, col) && image[newi][newj] != newColor && image[newi][newj] == oldColor){
                   image[newi][newj] = newColor;
                   q.push({newi, newj});
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int oldColor = image[sr][sc];
        bfs(sr, sc, row, col, oldColor, color, image);
        return image;
    }
};

TC = O(row*col) , in worst case queue can have row*col no. of elements.
SC = O(row*col), in worst case we can put row*col nodes in queue when all the values in the image of oldColor


