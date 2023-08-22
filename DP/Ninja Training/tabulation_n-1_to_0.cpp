
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));
    // writing base case here.
    dp[n-1][0] = max(points[n-1][1], points[n-1][2]);
    dp[n-1][1] = max(points[n-1][0], points[n-1][2]);
    dp[n-1][2] = max(points[n-1][0], points[n-1][1]);
    dp[n-1][3] = max(points[n-1][0], max(points[n-1][1], points[n-1][2]));

    // Run 2 for loops for all possible values of index and lastDayAct and 
    // inside that for loop copy all the code which is written in recursive function and change recursive call with dp array value.
    for(int index = n-2; index >= 0; index--){
        for(int lastDayAct = 0; lastDayAct < 4; lastDayAct++){
            int res = 0;
            // try all the possible 3 activities and return the maxm among them.
            for(int act = 0; act < 3; act++){
                if(act != lastDayAct){
                    res = max(res, points[index][act] + dp[index + 1][act]);
                }
            }
            dp[index][lastDayAct] = res;
        }
    }
    // returning dp[0][3] because initial call of recursion was solve(0,3)
    return dp[0][3];
}

// TC = O(n*4) * 3
// SC = 0(n*4) -> recursion stack space has beeen removed.

  
