class Solution
{
    public:
    int solve(int arr[],int n,vector<int> &dp){
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        // There are 2 choice, either loot that house or not loot that house.
        // If we are looting a house, then we can't loot its adjacent house and we have decremented n by 2 while making recursive call.
        int take = arr[n-1] + solve(arr,n-2,dp);
        int leave = solve(arr,n-1,dp);
        return dp[n] = max(take,leave);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int res =0;
        vector<int> dp(n+1,-1);
        return solve(arr,n,dp);

    }
};
