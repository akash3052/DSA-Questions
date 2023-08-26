// Note : Instead of storing entire table just store previous row.
// So, we need just 2 vectors : one for current row and one for previous row.

#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> nextrow(n,0);
	for(int j = 0; j < n; j++){
		// omitting the ith part and keeping only jth part.
		nextrow[j] = triangle[n-1][j];
	}
	for(int i = n-2; i >= 0; i--){
		vector<int> currRow(n,0);
		for(int j = n-2; j >= 0; j--){
			// Wherever dp[i+1] is used : use nextrow in place of that.
      // ith part will also be removed. keep only jth part.
			int down = triangle[i][j] + nextrow[j];
			int diag = triangle[i][j] + nextrow[j+1];
			// Wherever dp[i] is use -> use currRow in place of that.
			currRow[j] = min(down, diag);
		}
		nextrow = currRow;
	}
	return nextrow[0];
	// return solve(0, 0, n, triangle, dp);
}


// TC = O(n^2)
// SC = O(n)
// We have reduced the space complexity from n^2 to n.

