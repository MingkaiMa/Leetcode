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
    
    TreeNode* buildTreeCore(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 1 && postorder.size() == 1)
        {
            TreeNode* root = new TreeNode(inorder[0]);
            return root;
        }
        
        if(inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder.back());
        
        int findIndex = 0;
        
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
            {
                findIndex = i;
                break;
            }
        }
        
        
        
        vector<int> new_in_left(inorder.begin(), inorder.begin() + findIndex);
        vector<int> new_post_left(postorder.begin(), postorder.begin() + findIndex);
        
        vector<int> new_in_right(inorder.begin() + findIndex + 1, inorder.end());
        vector<int> new_post_right(postorder.begin() + findIndex, postorder.end() - 1);
        
        root->left = buildTreeCore(new_in_left, new_post_left);
        root->right = buildTreeCore(new_in_right, new_post_right);
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 && postorder.size() == 0)
            return nullptr;
        
        return buildTreeCore(inorder, postorder);
    }
};
