class Solution
{
    public:
    void connect(Node *root)
    {
        if(!root)
            return;
        queue<Node*> q;
        q.push(root);
        // Connecting nodes which are present at the same level.
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* front = q.front();
                q.pop();
                // If size becomes 0, then it means there are no more nodes present at that level. So, we are pointing it's nextRight to NULL. 
                // Otherwise, we are pointing nextRight to next element present in the queue(which is basically next element in that level).
                if(size == 0)
                    front->nextRight = NULL;
                else
                    front->nextRight = q.front();
              
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
        }
    }    
      
};
