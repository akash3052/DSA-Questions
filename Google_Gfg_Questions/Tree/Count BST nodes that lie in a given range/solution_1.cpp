class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      if(!root)
        return 0;
      // If root is falling in range, then we will go both on left and right side.
      if(root->data >= l && root->data<=h ){
          return 1+getCount(root->left,l,h) + getCount(root->right,l,h);
      }else if(root->data <l){ 
        // If root is less than l, then all the nodes in its left will be less than l. So, there is no point going in left side of the tree. 
        // Hence we will go only on right side because on right side element will be greater than root and it might fall in the range.
          return getCount(root->right,l,h);
      }else if(root->data > h){
          return getCount(root->left,l,h);
      }
    }
};

// 2nd solution is simple. Traverese the tree and check if any node is falling in the range then increment the count and return that count.

TC = O(n) in worst case.
