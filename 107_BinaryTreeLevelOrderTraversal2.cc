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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == nullptr)
            return res;
        
        
        queue<TreeNode*> Queue;
        
        Queue.push(root);
        
        int levelCount = 0;
        vector<int> array;
        
        
        while(!Queue.empty())
        {
            if(levelCount == 0)
            {
                levelCount = Queue.size();
            }
            
            TreeNode* curr = Queue.front();
            Queue.pop();
            levelCount--;
            
            
            if(levelCount == 0)
            {
                array.push_back(curr->val);
                res.push_back(array);
                array.clear();
            }
            else
                array.push_back(curr->val);
            
            
            if(curr->left != nullptr)
                Queue.push(curr->left);
            
            if(curr->right != nullptr)
                Queue.push(curr->right);

        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};
