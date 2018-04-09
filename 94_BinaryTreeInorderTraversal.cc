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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL)
            return res;
        
        stack<TreeNode*> Stack;
        
        TreeNode* curr = root;
        
        while(curr != NULL)
        {
            Stack.push(curr);
            curr = curr->left;
        }
        
        while(!Stack.empty())
        {
            
            
            TreeNode* now = Stack.top();
            Stack.pop();
            
            if(now != NULL)
                res.push_back(now->val);
            
            
            if(now->right != NULL)
            {
                TreeNode* now_right = now->right;
                while(now_right != NULL)
                {
                    Stack.push(now_right);
                    now_right = now_right->left;
                }
            }
        }
        
        return res;
    }
};
