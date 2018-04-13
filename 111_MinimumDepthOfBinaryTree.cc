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
        
        if(root->left == nullptr)
        {
            return heightCore(root->right) + 1;
        }
        
        if(root->right == nullptr)
        {
            return heightCore(root->left) + 1;
        }
        
        return min(heightCore(root->left), heightCore(root->right)) + 1;
        
    }
    
    int minDepth(TreeNode* root) {
        
        
        if(root == nullptr)
            return 0;
        
        
        
        
        return heightCore(root);
    }
};
