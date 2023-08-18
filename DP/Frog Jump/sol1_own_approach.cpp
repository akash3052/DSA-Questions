//Generally we check if(index == 0) and do solve(n-1) and solve(n-2) but here we are doing opposite of that.
// we are checking if(index >= n) and doing solve(n+1) and solve(n+2) -> Purpose of doing this is to demonstrate, we can 
// solve both way. Generally you will find above approach, this approach is not seen anywhere.

#include <bits/stdc++.h> 
int solve(int index, int n, vector<int> &heights, vector<int> &dp){
    if(index >= n){
        return INT_MAX;
    }
    if(index == n-1){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int oneJump = INT_MAX;
    int twoJump = INT_MAX;
    // Note -> There are 2 possibilites either take 1 jump or take 2 jump and cost are associated to both, 
    // consider both approach and take minm among them.
    
    // Since, we are doing heights[index+1] - heights[index], that's why we are checking index+1 <= n-1 because it might go
    //  out of index.
    if(index+1 <= n-1){
        oneJump = solve(index+1, n, heights, dp) + abs(heights[index+1] - heights[index]);
    }
    if(index+2 <= n-1){
        twoJump = solve(index+2, n, heights, dp) + abs(heights[index+2] - heights[index]);
    }
    return dp[index] = min(oneJump, twoJump);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return solve(0, n, heights, dp);
}



// TC = O(n) because we are solving only one time for different value of index and later we are using the stored answer.

// SC = O(n) [recursion stack size] + O(n) [dp array size]



