class Solution
{
    public:
    // <bool, maxm, minm> 
    tuple<bool,int, int> checkBst(Node *root){
        tuple<bool,int, int> left,right;
        if(!root){
            return make_tuple(true,INT_MIN,INT_MAX);
        }
        left = checkBst(root->left);
        right = checkBst(root->right);
        if(get<0>(left) && get<0>(right) && root->data > get<1>(left) && root->data < get<2>(right) ){
            // maxm = max(root's value , maxm of right subtree) as root->val is already greater than maxm of left subtree and same logic for minm value.
            return make_tuple(true, max(root->data, get<1>(right)), min(root->data, get<2>(left)) );
        }else{
            // returning minm of (left subtree minm, right subtree minm, root->data) and same for maxm.
            return make_tuple(false, max({root->data, get<1>(left), get<1>(right)}), min({root->data, get<2>(left), get<2>(left)}) );
        }
    }
    bool isBST(Node* root) {
        return get<0>(checkBst(root));
    }
};
