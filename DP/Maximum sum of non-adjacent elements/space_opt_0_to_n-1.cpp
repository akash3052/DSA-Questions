#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // Since, we require only last 2 dp array value(dp[i-1] and dp[i-2]) everytime. So, we are removing dp array and using
    // only 2 variables instead of that dp array. Now, SC will be reduced to constant(O(1)) instead of O(n) previously.
    int prev= nums[0];
    int prev2 = 0;
    for(int index = 1 ; index < n ; index++){
        int pick = nums[index];
        if(index >= 2){
            pick += prev2;
        }
        int notPick = prev;
        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;;
}

// TC = O(n)
// SC = O(1)

  
