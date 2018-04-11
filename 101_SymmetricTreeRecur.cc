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
    
    bool isSymmetricCore(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == nullptr && node2 == nullptr)
            return true;
        
        if(node1 == nullptr || node2 == nullptr)
            return false;
        
        if(node1->val != node2->val)
            return false;
        
        return isSymmetricCore(node1->right, node2->left) && isSymmetricCore(node1->left, node2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;

        return isSymmetricCore(root->left, root->right);
    }
};
