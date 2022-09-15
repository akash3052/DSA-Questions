class Solution
{
     public:
    void solve(int open, int close, string op, vector<string> &res){
        if(open==0 && close==0){
            res.push_back(op);
            return;
        }
        // Note -> Initially I forgot to give below if condition. Because of that, it was giving going in infinite loop. 
        // It was going till maxm negative value of open. Hence, it is important to give this condition.
        if(open>0){
            string op1 = op;
            op1.push_back('(');
            solve(open-1, close, op1, res);
        }
        if(close>open){
            string op2=op;
            op2.push_back(')');
            solve(open, close-1, op2, res);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        int open = n, close=n;
        string op = "";
        solve(open, close, op, res);
        return res;
    }
};


