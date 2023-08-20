#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n,-1);
    // dp[0] = 0;
    int firstPrev = 0; //dp[0] = 0;
    int secondPrev = 0;
    // Note-> Replace dp[i-1] -> firstPrev and dp[i-2] = secondPrev and dp[i] = curr
    for(int i = 1; i < n; i++){
        int oneJump = firstPrev + abs(heights[i-1] - heights[i]);
        int twoJump = INT_MAX;
        if(i > 1){
            twoJump = secondPrev + abs(heights[i-2] - heights[i]);
        }
        int curr = min(oneJump, twoJump);
        secondPrev = firstPrev;
        firstPrev = curr;
    }
    return firstPrev;
}

// TC = O(n)
// SC = 0(1) since we are not using extra space for recursion stack and for dp array as well.

