// Here, we are going from n-1 to n unlike sol 1 approach.

// 

#include <bits/stdc++.h> 
int solve(int index, vector<int> &heights, vector<int> &dp){
    if(index == 0){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int oneJump = solve(index-1, heights, dp) + abs(heights[index-1] - heights[index]);
    int twoJump = INT_MAX;
    // only for twoJump, we are checking index value because for oneJump, it is already handled in if(index == 0)
    if(index > 1){
        twoJump = solve(index-2, heights, dp) + abs(heights[index-2] - heights[index]);
    }
    return dp[index] = min(oneJump, twoJump);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    // note -> here we are passing n-1 not n.
    return solve(n-1, heights, dp);
}
