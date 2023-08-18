// See sol1_own_approach for conversion of memoization to tabulation.

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[n-1] = 0;
    for(int index = n-2; index >= 0; index--){
        int oneJump = INT_MAX;
        int twoJump = INT_MAX;
        if(index+1 <= n-1){
            oneJump = dp[index+1] + abs(heights[index+1] - heights[index]);
        }
        if(index+2 <= n-1){
            twoJump = dp[index+2] + abs(heights[index+2] - heights[index]);
        }
        dp[index] = min(oneJump, twoJump);
    }
    return dp[0];
}
