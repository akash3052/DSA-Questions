int solve(int index, int lastDayAct, int n, vector<vector<int>> &points, vector<vector<int>> &dp){
    // when we are at last index, we will return maxm of all the 3 activities except the activity which we performed lastday.
    if(index == n-1){
        int res = 0;
        for(int act = 0; act < 3; act++){
            if(act != lastDayAct){
                res= max(res, points[index][act]);
            }
        }
        return res;
    }
    if(dp[index][lastDayAct] != -1){
        return dp[index][lastDayAct];
    }
    int res = 0;
    // try all the possible 3 activities and return the maxm among them.
    for(int act = 0; act < 3; act++){
        if(act != lastDayAct){
            res = max(res, points[index][act] + solve(index + 1,act, n, points, dp));
        }
    }
    return dp[index][lastDayAct] = res;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));
    // Note -> we are passing lastDayIndex = 3 because in we want to try all 3 activities at index 0 and if we pass 
    // lastDayIndex as 3, then it will bypass the if condition if(act != lastDayActivity) and it will try all the 3 activites.
    return solve(0, 3, n, points, dp);
}

// TC = O(n * 4) * 3 -> there are n*4 different states and for each state, we are running loop of 3, that's why multiplying by 3.
// SC = O(n)[recursion space] + O(n *4 ) [dp space]

