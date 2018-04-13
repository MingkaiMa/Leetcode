/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int heightCore(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        
        return max(heightCore(root->left), heightCore(root->right)) + 1;
    }
    
    
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
            return true;
        
        
        int left = heightCore(root->left);
        int right = heightCore(root->right);

        if(abs(left - right) > 1)
            return false;
        
        
        return isBalanced(root->left) && isBalanced(root->right);

        
        
    }
};
