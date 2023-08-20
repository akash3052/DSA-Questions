#include<bits/stdc++.h>
using namespace std;

int solve(int index, int k, int n, vector<int> &heights, vector<int> &dp){
  // Note -> In below line, generally I write if(index == n ) because of that I got error many times. So, keep that in mind.
  if(index == n-1){
    return 0;
  }
  if(dp[index] != -1){
      return dp[index];
  }
  int res = INT_MAX;
  // Here we can take k steps, so we are taking all of them and taking minm among them.
  for(int i = index + 1; i <= index + k; i++){
    if(i < n){
      res = min(res, solve(i, k, n, heights, dp) + abs(heights[i] - heights[index]));
    }
  }
  return dp[index] = res;
}

int main(){
  int n, k;
  cin>>n>>k;
  vector<int> heights(n);
  for(int i = 0; i < n; i++){
    cin>>heights[i];
  }
  vector<int> dp(n,-1);
  cout<< solve(0, k, n, heights, dp)<<endl;
}
