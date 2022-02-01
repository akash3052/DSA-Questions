class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
       int maxLength =0;
       for(int i=0;i<n;i++){
           // Initialize currr_sum for every starting point
           int currSum = 0;
           
           // try all subarrays starting with 'i'
           for(int j=i;j<n;j++){
               currSum+=A[j];
               
               // If curr_sum becomes 0, then update maxLength if required
               if(currSum ==0){
                   maxLength = max(maxLength , j-i+1);
               }
           }
       }
       return maxLength;
    }
};

// Algorithm:  
// 1. Consider all sub-arrays one by one and check the sum of every sub-array.
// 2. Run two loops: the outer loop picks the starting point i and the inner loop tries all sub-arrays starting from i.

// TC = O(n^2)
// SC = O(1)
