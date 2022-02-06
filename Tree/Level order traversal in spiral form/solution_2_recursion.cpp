// Printing nodes at a particular level in the way function was called (either leftToRight or RightToLeft)
void printGivenLevel(Node *root, int level, bool ltr, vector<int> &res){
    if(!root || level < 1)
        return ;
    if(level == 1){
        res.push_back(root->data);
        return;
    }
    if(ltr){
        printGivenLevel(root->left, level -1, ltr,res);
        printGivenLevel(root->right,level-1, ltr , res);
    }
    else{
        printGivenLevel(root->right, level-1, ltr, res);
        printGivenLevel(root->left, level-1, ltr, res);
    }
}
int findHeight(Node *root){
    if(!root)
        return 0;
    int l = findHeight(root->left);
    int r = findHeight(root->right);
    return 1+ max(l,r);
}
// code start form here
vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if(!root){
        return res;
    }
    int height = findHeight(root);
    bool ltr = false;
    for(int i=1 ;i<=height;i++){
        printGivenLevel(root,i,ltr, res);
        ltr = !ltr;
    }
    return res;
}

// TC = O(n^2)

