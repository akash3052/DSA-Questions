//2nd method (2 solutions exists)

//Bottom Up Approach

//Since the robot can only move right and down, when it arrives at a point, it either arrives from left or above. If we use dp[i][j] for the number of unique paths to arrive at the point (i, j), then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j]. Moreover, we have the base cases dp[0][j] = dp[i][0] = 1 for all valid i and j.

//Since we need only 2 rows , we can also optimise space to O(n) by using 2 vectors.   

//TC= O(m*n) and SC=O(m*n)

class Solution {
public:
   
        int uniquePaths(int col, int row) {
        
        vector<vector<int>> dp(row,vector<int>(col,1));//Initialising dp array to store values.
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]; 
            }
        }
        return dp[row-1][col-1];
    }
};


