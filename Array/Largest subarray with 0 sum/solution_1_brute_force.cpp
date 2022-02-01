class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
       int finalLength =0;
       // considering all subarrays and checking sum in that subarray , if that equal to 0, we are updating finalLength's value(which is basically lenght of the subarray).
       for(int i=0;i<n;i++){
           int sum = A[i];
           // length can be 1 also, that's why considering if single element's value is 0, if it is then update finalLength to max(finalLenght,1).
           if(sum == 0){
               finalLength = max(finalLength,1);
           }
           for(int j=i+1;j<n;j++){
               sum+=A[j];
               if(sum ==0){
                   finalLength = max(finalLength , j-i+1);
               }
           }
       }
       return finalLength;
    }
};
// TC = O(n^2)
// SC = O(1)
