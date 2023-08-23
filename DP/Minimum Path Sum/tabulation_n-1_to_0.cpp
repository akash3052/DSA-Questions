#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n,0));
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == m-1 && j == n-1){
                dp[i][j] = grid[m-1][n-1];
            }else{
                long long right = INT_MAX;
                long long down = INT_MAX;
                if(j+1 <= n-1){
                    right = grid[i][j] + dp[i][j+1];
                }
                if(i+1 <= m-1){
                    down = grid[i][j] + dp[i+1][j];
                }
                dp[i][j] = min(right, down);
            }
        }
    }
    return dp[0][0];
    // return solve(0, 0, row, col, grid, dp);
}

// TC = O(m*n)
// SC = O(m*n)

// we have reduced the recursion space by using tabulation method.
