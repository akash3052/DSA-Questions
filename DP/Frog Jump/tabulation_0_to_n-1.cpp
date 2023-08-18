step 1 : In memoization, how much dp array used. Initialize same for tabulation also.
step 2 : look at the base case. whatever is done in recursion, do same here also.
          e.g. in rec : if(index == 0 ) return 0 -> so, here we will do dp[0] = 0
step 3 : See in recursion, for what value of index, recursion will be executed.
         Run a for loop for all those values.
step 4 : wherever recursive call is there, replace that recursive call with dp array value.
         e.g solve(index

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int oneJump = dp[i-1] + abs(heights[i-1] - heights[i]);
        int twoJump = INT_MAX;
        if(i > 1){
            twoJump = dp[i-2] + abs(heights[i-2] - heights[i]);
        }
        dp[i] = min(oneJump, twoJump);
    }
    return dp[n-1];
}
