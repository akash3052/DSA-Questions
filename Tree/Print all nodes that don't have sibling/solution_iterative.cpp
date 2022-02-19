vector<int> noSibling(Node* node)
{
    // code here
    vector<int> res;
    if(node == NULL){
        res.push_back(-1);
        return res;
    }     
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        // If there is only one child present for a node, then that child must be present in our answer.
        // Having 2 children or having both childeren as NULL, means there is siblings. We have to consider internal node/root node who is having only one child.
        if((front->left && !front->right) || (front->right && !front->left)){
            if(front->left)
                res.push_back(front->left->data);
            if(front->right)
                res.push_back(front->right->data);
        }
        if(front->left)
            q.push(front->left);
        if(front->right)
            q.push(front->right);
    }
    // If there is no such nodes, who have single child, then we will return -1.
    if(res.empty()){
        res.push_back(-1);
        return res;
    }
    else
        sort(res.begin(),res.end());
    return res;
}
