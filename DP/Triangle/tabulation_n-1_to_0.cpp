#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n,0));
  // write base case condition
	for(int j = 0; j < n; j++){
		dp[n-1][j] = triangle[n-1][j];
	}
  // write for loop to cover all the possible states.
  // If recursion is going from 0 to n-1, then in memoization go opposite (n-1 to 0) and viceversa.
	for(int i = n-2; i >= 0; i--){
    // below j loop can be run form i to 0 because j can go from 0 to i value max since it is triangle.
    // for(int j = i; j >= 0; j--) -> this will reduce some time.
		for(int j = n-2; j >= 0; j--){
			int down = triangle[i][j] + dp[i+1][j];
			int diag = triangle[i][j] + dp[i+1][j+1];
			dp[i][j] = min(down, diag);
		}
	}
	return dp[0][0];
	// return solve(0, 0, n, triangle, dp);
}

// TC = O(n^2)
// SC = O(n^2) 
// Recursion stack space is removed.

