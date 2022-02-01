class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
       int maxLength =0;
       unordered_map<int,int> prefixSum;
       int currSum = 0;
       for(int i=0;i<n;i++){
           currSum += A[i];
           if(currSum == 0 && maxLength == 0){
               maxLength = 1;
           }
           if(currSum == 0){
               maxLength = i+1;
           }
           if(prefixSum.find(currSum) != prefixSum.end()){
               maxLength = max(maxLength, i-prefixSum[currSum]);
           }else{
               prefixSum[currSum] = i;
           }
       }
       return maxLength;
    }
};

// Algorithm: - 
   -----------
// prefix(i) = arr[0] + arr[1] +…+ arr[i] 
// prefix(j) = arr[0] + arr[1] +…+ arr[j], j>i 
// if prefix(i) == prefix(j) then prefix(j) – prefix(i) = 0 that means arr[i+1] + .. + arr[j] = 0, So a sub-array has zero sum , and the length of that sub-array is j-i,
// j-i => j = current_index and i is the value of index stored in the map.

// Time Complexity: O(n), as use of the good hashing function, will allow insertion and retrieval operations in O(1) time.
// Space Complexity: O(n), for the use of extra space to store the prefix array and hashmap.
