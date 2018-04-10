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
    
    TreeNode* one = nullptr;
    TreeNode* two = nullptr;
    TreeNode* pre = nullptr;
    
    
    void inorderRecur(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        inorderRecur(root->left);


        if(pre != nullptr && pre->val >= root->val)
        {
            if(one == nullptr)
            {
                one = pre;
                two = root;
            }
            else
            {
                two = root;
            }
                
        }
        
        pre = root;
        
        inorderRecur(root->right);
    }
    
    
    void recoverTree(TreeNode* root){
        
        if(root == nullptr)
            return;
        

        inorderRecur(root);
        
        if(one != nullptr && two != nullptr)
        {
            int temp = one->val;
            one->val = two->val;
            two->val = temp;
        }

        
        
    }
};
