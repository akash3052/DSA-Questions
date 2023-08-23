#include <bits/stdc++.h> 
long long solve(int i, int j, int m, int n, vector<vector<int>> &grid){
    if(i == m-1 && j == n-1){
        return grid[m-1][n-1];
    }
    if(i >= m || j >= n)
        return INT_MAX;
    long long right = grid[i][j] + solve(i, j+1, m, n, grid);
    long long down = grid[i][j] + solve(i+1, j, m, n, grid);
    return min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    return solve(0, 0, row, col, grid);
}

// TC = O( 2 ^ (m*n)) 
// SC = O(m+n)
