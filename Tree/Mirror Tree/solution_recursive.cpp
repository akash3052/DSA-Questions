class Solution {
  public:
    void mirror(Node* node) {
        // code here
        if(node == NULL)
            return;
        // Induction step (mirroing the current node)
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        // Hypothesis step (Assuming it will mirror for left and right subtree)
        mirror(node->left);
        mirror(node->right);
    }
};
