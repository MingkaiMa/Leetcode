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
    
    int leftHeight(TreeNode* root)
    {
        int height = 0;
        while(root != nullptr)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    
    int rightHeight(TreeNode* root)
    {
        int height = 0;
        while(root != nullptr)
        {
            height++;
            root = root->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int l = leftHeight(root);
        int r = rightHeight(root);
        
        if(l == r)
        {
            return ((1 << l) - 1);
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;
        
    }
};
