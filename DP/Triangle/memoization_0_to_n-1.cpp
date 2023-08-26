#include <bits/stdc++.h> 
int solve(int i, int j, int n, vector<vector<int>> &traingle, vector<vector<int>> &dp){
	// we are giving base case only for i because j can go beyond only in last roe.
	// and we are already returning when we are reaching the last row. 
	// Hence, check for j is not requried.
	if(i == n-1){
		return traingle[i][j];
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int down = traingle[i][j] + solve(i+1, j, n, traingle, dp);
	int diag = traingle[i][j] + solve(i+1, j+1, n, traingle, dp);
	return dp[i][j] = min(down, diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n,-1));
	return solve(0, 0, n, triangle, dp);
}

// TC is basically no of states.
// TC = O(number of cells) = O(n*n+1/2) = O(n^2)
// SC = O(n^2)  

