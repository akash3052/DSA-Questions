#include <bits/stdc++.h> 
int solve(int index, int n, vector<int> &nums, vector<int> &dp){
    if(index == 0){
        return nums[index];
    }
    if(index <= 0){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int pick = nums[index] + solve(index-2, n, nums, dp);
    int notPick = solve(index-1, n, nums, dp);
    return dp[index] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n-1, n, nums, dp);
}
