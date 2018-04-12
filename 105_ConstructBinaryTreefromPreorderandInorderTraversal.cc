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
    
    TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size() == 1 && inorder.size() == 1)
        {
            TreeNode* node = new TreeNode(preorder[0]);
            return node;
        }
        
        if(preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int findIndex = 0;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
            {
                findIndex = i;
                break;
            }
        }
        
        vector<int> new_pre_left(preorder.begin() + 1, preorder.begin() + findIndex + 1);
        vector<int> new_in_left(inorder.begin(), inorder.begin() + findIndex);
        
        vector<int> new_pre_right(preorder.begin() + findIndex + 1, preorder.end());
        vector<int> new_in_right(inorder.begin() + findIndex + 1, inorder.end());
        
        
        root->left = buildTreeCore(new_pre_left, new_in_left);
        root->right = buildTreeCore(new_pre_right, new_in_right);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
            return nullptr;

        return buildTreeCore(preorder, inorder);

    }
};
