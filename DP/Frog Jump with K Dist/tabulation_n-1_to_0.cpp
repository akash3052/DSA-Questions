#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin>>n>>k;
  vector<int> heights(n);
  for(int i = 0; i < n; i++){
    cin>>heights[i];
  }
  vector<int> dp(n,-1);
  dp[n-1] = 0;
  // Run loop for different value of index which can occur in recursion.
  for(int index = n-2; index >= 0 ; index--){
      int res = INT_MAX;
      for(int i = index + 1; i <= index + k; i++){
        if(i < n){
          // replace every recursive call(solve(i)) with dp[i].
          res = min(res, dp[i] + abs(heights[i] - heights[index]));
        }
      }
      dp[index] = res;
  }
  cout<< dp[0];
}


// TC = O(n * k) -> for each value of n, we are iteration k times.
// SC = O(n) -> recursion stack space has been reduced in tabulation


