class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    bool findPath(Node* root, int key, vector<Node*> &path){
        if(root == NULL)
            return false;
        path.push_back(root);
        if(root->data == key)
            return true;
        bool left = findPath(root->left, key, path);
        bool right = findPath(root->right, key, path);
        if(left || right)
            return true;
        // If key is not present either in left subtree or right subtree, then there is no need of root node in our answer. So, we will pop_back() root from path,
       // and return false.
        path.pop_back();
        return false;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<Node*> path1,path2;
       // finding path for node n1 and n2, and also checking if n1 and n2 exist or not.
       bool isn1Exist = findPath(root,n1,path1);
       bool isn2Exist = findPath(root,n2,path2);
       // If any of them doesn't exist, then lca will not exist.
       if(!isn1Exist || !isn2Exist)
         return nullptr;
       int i;
       for(i=0;i<min(path1.size(), path2.size()); i++){
           if(path1[i]->data != path2[i]->data)
                break;
       }
       return path1[i-1];
    }
};



//Time Complexity: O(n). The tree is traversed twice, and then path arrays are compared. 
//Auxiliary Space: O(n). Extra Space for path1 and path2.


