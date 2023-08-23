#include <bits/stdc++.h> 
long long solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<long long>> &dp){
    if(i == m-1 && j == n-1){
        return grid[m-1][n-1];
    }
    // Note -> we are INT_MAX because we don't this path to be considered in our answer. When we are going out of boundary ,
    // It has to return something that this path summation is not taken into consideration.
    if(i >= m || j >= n)
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];
    long long right = grid[i][j] + solve(i, j+1, m, n, grid, dp);
    long long down = grid[i][j] + solve(i+1, j, m, n, grid, dp);
    return dp[i][j] = min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<long long>> dp(row, vector<long long>(col,-1));
    return solve(0, 0, row, col, grid, dp);
}

// TC = O(m*n)
// SC = O((m-1)+ (n-1)) [Recursion stack size] + O(m*n) [dp array size]


