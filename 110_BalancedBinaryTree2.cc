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
    
    bool isBalancedCore(TreeNode* root, int& depth){
        if(root == nullptr){
            depth = 0;
            return true;
        }
        
        int left, right;
        
        if(isBalancedCore(root->left, left) && isBalancedCore(root->right, right)){
            int diff = left - right;
            
            if(diff <= 1 && diff >= -1){
                depth = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }
    
    
    bool isBalanced(TreeNode* root) 
    {
        int depth = 0;
        return isBalancedCore(root, depth);
    }
};
