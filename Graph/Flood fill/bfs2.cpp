class Solution {
public:
    vector<int> delx = {-1, 1, 0, 0};
    vector<int> dely = {0, 0, -1, 1};

    bool isValid(int x, int y, int row, int col){
        if(x < 0 || x >= row || y < 0 || y >= col){
            return false;
        }
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color){
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int row = image.size(), col = image[0].size();
        image[sr][sc] = color;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int newx = x + delx[i];
                int newy = y + dely[i];
                if(isValid(newx, newy, row, col) && image[newx][newy] == oldColor ){
                    image[newx][newy] = color;
                    q.push({newx, newy});
                }
            }
        }
        return image;
    }
};

