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

    
    int maxValue = INT_MIN;
    
    int maxPathSumCore(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        int currValue = root->val;
        
        int leftValue = maxPathSumCore(root->left);
        int rightValue = maxPathSumCore(root->right);
        
        if(leftValue > 0)
            currValue += leftValue;
        
        if(rightValue > 0)
            currValue += rightValue;
        
        if(currValue > maxValue)
            maxValue = currValue;
        
        return max(root->val, max(root->val + leftValue, root->val + rightValue));
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return -2147483648;
        
        maxPathSumCore(root);
        
        return maxValue;
        
    }
};

