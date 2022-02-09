class Solution
{
    public:
    void solve(vector<int> &input, int k,int index){
        if(input.size()==1)
            return;
        // Making input smaller by deleting the person present at kth position.
        index = (index+k-1)%input.size();
        input.erase(input.begin()+index);
        // Hypothesis Step
        solve(input,k,index);
        // No Induction step required beacuse after deletion we don't want that element to be present in the vector as that person is dead.
    }
    
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> input;
       // Placing person no 1 to n so that we can delete it later.
       for(int i=1;i<=n;i++){
           input.push_back(i);
       }
       // will start from 0th index.
       int index =0;
       solve(input,k,index);
       return input[0];
    }
};
