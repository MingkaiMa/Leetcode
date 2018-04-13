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
    
    bool hasPathSumCore(TreeNode* root, int currSum)
    {
        if(root == nullptr && currSum == 0)
            return true;
        
        if(root == nullptr && currSum != 0)
            return false;
        
        
        if(currSum == root->val && root->left == nullptr && root->right == nullptr)
            return true;
        
        
        if(root->left == nullptr && root->right == nullptr && currSum != root->val)
            return false;
        
        
        
        if(root->right == nullptr)
            return hasPathSumCore(root->left, currSum - root->val);
        
        else if(root->left == nullptr)
            return hasPathSumCore(root->right, currSum - root->val);
        
        else
            return hasPathSumCore(root->left, currSum - root->val) || hasPathSumCore(root->right, currSum - root->val);
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root == nullptr)
            return false;
        
        return hasPathSumCore(root, sum);
    }
};
