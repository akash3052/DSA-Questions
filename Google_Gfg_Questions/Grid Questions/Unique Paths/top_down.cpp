//1st method (2 solutions exists)

//Top Down Approach 

class Solution {
public:
    
    int findpaths(int i, int j,vector<vector<int>> &dp)
    {
        //Base condition
        if(i<0 || j<0)
            return 0;
        else if(i==0 || j==0)
        {
            dp[i][j]=1;
            return dp[i][j];
        }
        
        //Memoization
        else if(dp[i][j]>0)
            return dp[i][j];
        else
        {
            dp[i][j]=findpaths(i,j-1,dp)+findpaths(i-1,j,dp);//Recursive step and self work.
            return dp[i][j];
        }
    }
    
    int uniquePaths(int col, int row) {
        
        vector<vector<int>> dp(row,vector<int>(col,-1));//Initialising dp array to store values.
        int cnt=0;
        findpaths(row-1,col-1,dp);
        return dp[row-1][col-1];
    }
};


