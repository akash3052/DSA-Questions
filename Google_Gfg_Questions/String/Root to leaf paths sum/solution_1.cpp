void solve(Node*root, long long currSum, long long &overallSum){
    if(!root)
        return;
    if(!root->left && !root->right){
        currSum = currSum*10 + root->data;
        overallSum += currSum;
        return;
    }
    solve(root->left, currSum*10+root->data, overallSum);
    solve(root->right, currSum*10+root->data, overallSum);
}

long long treePathsSum(Node *root)
{
    long long overallSum=0;
    long long currSum = 0;
    solve(root,currSum, overallSum);
    return overallSum;
}
