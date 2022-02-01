class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        int j=0;
        int temp[n];
        for(int i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                temp[j++] = a[i];
            }
        }
        // Store the last element as whether
        // it is unique or repeated, it hasn't
        // stored previously
        temp[j++] = a[n-1];
        for(int i=0;i<j;i++){
            a[i] = temp[i];
        }
        return j;
    }
};
