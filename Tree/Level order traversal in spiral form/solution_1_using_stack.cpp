vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if(!root){
        return res;
    }
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        // Print nodes of current level from s1 and push nodes of next level to s2
        while(!s1.empty()){
            Node *top = s1.top();
            s1.pop();
            res.push_back(top->data);
            // Note that is right is pushed before left
            if(top->right){
                s2.push(top->right);
            }
            if(top->left){
                s2.push(top->left);
            }
        }
        // Print nodes of current level from s2 and push nodes of next level to s1
        while(!s2.empty()){
            Node *top = s2.top();
            res.push_back(top->data);
            s2.pop();
            // Note that is left is pushed before right
            if(top->left)
                s1.push(top->left);
            if(top->right){
                s1.push(top->right);
            }
        }
    }
    return res;
}

// Algorithm
// ----------
// We can print spiral order traversal in O(n) time and O(n) extra space. The idea is to use two stacks.
// We can use one stack for printing from left to right and other stack for printing from right to left. 
// In every iteration, we have nodes of one level in one of the stacks. We print the nodes, and push nodes of next level in other stack. 
  
// TC = O(n)
// SC = O(n)
