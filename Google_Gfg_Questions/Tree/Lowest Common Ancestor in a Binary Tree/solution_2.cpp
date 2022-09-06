class Solution
{
    public:
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
            return NULL;
        if(root->data == n1 || root->data == n2){
            return root;
        }
        Node* left = lca(root->left,n1,n2);
        Node* right = lca(root->right,n1, n2);
        if(!left && !right)
            return NULL;
        if(left && right)
            return root;
        return left?left:right; 
    }
};

https://www.youtube.com/watch?v=_-QHfMDde90&ab_channel=takeUforward

Time Complexity: O(n) as the method does a simple tree traversal in a bottom-up fashion. 
Auxiliary Space: O(h), where h is the height of the tree.
