void solve(Node* root, vector<int> &res){
    if(root == NULL)
        return ;
    // if only one child is present, then push that child in our answer.
    if((root->left && !root->right) || (root->right && !root->left)){
        if(root->left)
            res.push_back(root->left->data);
        if(root->right)
            res.push_back(root->right->data);
    }
    // check for left and right subtree
    solve(root->left,res);
    solve(root->right,res);
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int> res;
    if(node == NULL){
        res.push_back(-1);
        return res;
    }
    solve(node, res);
    if(res.empty()){
        res.push_back(-1);
        return res;
    }
    else
        sort(res.begin(),res.end());
    return res;
}
