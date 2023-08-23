#include <bits/stdc++.h> 
int solve(int i, int j, int &m, int &n, vector<vector<int>> &dp){
	if(i == m-1 && j == n-1){
		return 1;
	}
	if(i >= m || j >= n){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int right = solve(i, j+1, m, n, dp);
	int down = solve(i+1, j, m, n, dp);
	return dp[i][j] = right + down;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n,-1));
	return solve(0, 0, m, n, dp);
}

// For Recursion
// TC = O(2 ^ (m+n)) -> for every cell, there are 2 possibilities and there are (m+n) cells in total.
// SC = O((m-1)+ (n-1))

// Using DP
// TC = O(m*n)
// SC = O((m-1)+ (n-1)) [Recursion stack size] + O(m*n) [dp array size]


