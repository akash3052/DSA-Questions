#include <bits/stdc++.h> 
int solve(int index, int n, vector<int> &nums, vector<int> &dp){
    // we would have reached n-1 only from n-3, hence we are adding its value in the answer. 
    // we could not reached n-1 from n-2 because of adjacent constraints.
    // This condition is little bit confusing. See, below solution for better understanding.
    // Even if we remove below condition, our code will work because same thing will be done in line 17.
    if(index == n-1){
        return nums[index];
    }
    // For better understanding draw recursion tree for smaller input and check by putting values.
    if(index >= n){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int pick = nums[index] + solve(index+2, n, nums, dp);
    int notPick = solve(index+1, n, nums, dp);
    return dp[index] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(0, n, nums, dp);
}

// TC = O(n)
// SC = O(n) + O(n)


// Solution for better understanding
int solve(int index, int n, vector<int> &nums, vector<int> &dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        // if(index == n-1) condn is handled in below line.
        int rob = nums[index] + solve(index + 2, n, nums, dp);
        int notrob = solve(index+1, n, nums, dp);
        return dp[index] = max(rob, notrob);
}



