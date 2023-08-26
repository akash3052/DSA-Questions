#include <bits/stdc++.h> 
int solve(int i, int j, int n, vector<vector<int>> &traingle){
	// we are giving base case only for i because j can go beyond only in last roe.
	// and we are already returning when we are reaching the last row. 
	// Hence, check for j is not requried.
	if(i == n-1){
		return traingle[i][j];
	}
	int down = traingle[i][j] + solve(i+1, j, n, traingle);
	int diag = traingle[i][j] + solve(i+1, j+1, n, traingle);
	return min(down, diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return solve(0, 0, n, triangle);
}

// TC = 2^(n*n+1/2)
// There are 2 options for each cell(either go down or go diagonally) and there are (n*n+1)/2 cells. (1 + 2 + 3 + 4 +...+n )

// SC = O(n) 
// Recursion stack space (can go from 0th row to last row)

