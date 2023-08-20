// Here we are not using dp array since we requrie only 2 variables. So, its space complexity has been reduced to O(1).


#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int firstNext = 0; // dp[n-1] = 0 (initially)
    int secondNext = 0;
    for(int index = n-2; index >= 0; index--){
        int oneJump = INT_MAX;
        int twoJump = INT_MAX;
        if(index+1 <= n-1){
            oneJump = firstNext + abs(heights[index+1] - heights[index]);
        }
        if(index+2 <= n-1){
            twoJump = secondNext + abs(heights[index+2] - heights[index]);
        }
        int currVal = min(oneJump, twoJump);
        secondNext = firstNext;
        firstNext = currVal;
    }
    return firstNext;
}

// TC = O(n)
// SC = 0(1) since we are not using extra space for recursion stack and for dp array as well.




