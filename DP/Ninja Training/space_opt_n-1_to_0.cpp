
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> next(4,0);
    // writing base case here.
    next[0] = max(points[n-1][1], points[n-1][2]);
    next[1] = max(points[n-1][0], points[n-1][2]);
    next[2] = max(points[n-1][0], points[n-1][1]);
    next[3] = max(points[n-1][0], max(points[n-1][1], points[n-1][2]));

    // Run 2 for loops for all possible values of index and lastDayAct and 
    // inside that for loop copy all the code which is written in recursive function and change recursive call with dp array value.
    for(int index = n-2; index >= 0; index--){
        vector<int> temp(4,0);
        for(int lastDayAct = 0; lastDayAct < 4; lastDayAct++){
            int res = 0;
            // try all the possible 3 activities and return the maxm among them.
            for(int act = 0; act < 3; act++){
                if(act != lastDayAct){
                    // next[act] because we are considering only 4 values.
                    res = max(res, points[index][act] + next[act]);
                }
            }
            // everything here we are considering on the basis of activity, that's why temp[lastDayAct]
            temp[lastDayAct] = res;
        }
        next = temp;
    }
    return next[3];
}

// TC = O(n*4*3)
// SC = O(4) which is almost constant time.
  
