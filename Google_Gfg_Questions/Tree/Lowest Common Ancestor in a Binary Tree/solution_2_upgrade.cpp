Note that the above method assumes that keys are present in Binary Tree. 
If one key is present and the other is absent, then it returns the present key as LCA (Ideally should have returned NULL). 
We can extend this method to handle all cases by checking if n1 and n2 are present in the tree first and then finding the LCA of n1 and n2.
  
bool find(Node* root, int k)
{
    // Base Case
    if (root == NULL)
        return false;
    if (root->key == k)
        return true;
    bool left = find(root->left, k);
    bool right = find(root->left, k);
    if(left || right )
      return true;
    return false;
}
Node* findLCA(Node* root, int n1, int n2)
{
    if (find(root, n1) and find(root, n2))
        return findLCA(root, n1, n2);
    return NULL;
}
