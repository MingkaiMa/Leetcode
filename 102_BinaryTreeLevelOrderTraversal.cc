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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        
        if(root == nullptr)
            return res;
        
        
        queue<TreeNode*> Queue;
        
        Queue.push(root);
        
        int popLength = 0;
        
        vector<int> helperRes;
        
        
        while(!Queue.empty())
        {

            if(popLength == 0)
                popLength = Queue.size();
            
            TreeNode* node = Queue.front();

            Queue.pop();
            popLength -= 1;
            
            
            if(popLength == 0)
            {
                helperRes.push_back(node->val);
                res.push_back(helperRes);
                helperRes.clear();
            }
            else
            {
                helperRes.push_back(node->val);
            }
            
            
            if(node->left != nullptr)
                Queue.push(node->left);
            
            if(node->right != nullptr)
                Queue.push(node->right);
        }
        
        return res;
    }
};
