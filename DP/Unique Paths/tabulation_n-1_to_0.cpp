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
	vector<vector<int>> dp(m, vector<int>(n,0));
  // Run for loops for all the possible states in recursive call.
	for(int i = m-1; i >= 0; i--){
		for(int j = n-1; j >= 0; j--){
			if(i == m-1 && j == n-1){
				dp[i][j] = 1;
 			}else{
				int right = 0;
				int down = 0;
				if(j+1 <= n-1){
					right = dp[i][j+1];
				}
				if(i+1 <= m-1){
					down = dp[i+1][j];
				}
				dp[i][j] = right + down;
			}
		}
	}
	return dp[0][0];
}


// TC = O(m*n)
// SC = O(m*n)

// we have reduced the recursion space by using tabulation method.

