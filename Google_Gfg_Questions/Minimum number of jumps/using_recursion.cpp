class Solution{
  public:
    int solve(int arr[], int index, int n ){
        if(index >= n -1)
            return 0;
        int jumps = INT_MAX;
        // Considering every index which can be reached from index i, and making recursive call from that index.
        for(int i=1; i<= arr[index]; i++){
        	jumps = min(jumps, solve(arr, index+i,n));
        }
        return jumps + 1;
    }

    int minJumps(int arr[], int n){
        return solve(arr,0, n);
    }
};
