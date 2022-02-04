class Solution {
  public:
    long long mod = 1000000007;
    long long int solve(long long int i, vector<int> &dp){
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = (solve(i-1,dp) + solve(i-2,dp))%mod;
    }
    
    long long int nthFibonacci(long long int n){
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        if(n==0)
            return dp[0];
        if(n==1)
            return dp[1];
        return solve(n, dp)%mod;
    }
};
