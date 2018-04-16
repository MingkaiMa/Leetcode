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
    
    
    void pathSumCore(TreeNode* root, int currSum, vector<vector<int>>& res, vector<int>& currPath)
    {
        if(root == nullptr)
            return;
        
        if(root != nullptr && root->left == nullptr && root->right == nullptr && root->val == currSum)
        {
            currPath.push_back(root->val);
            res.push_back(currPath);
            currPath.pop_back();
            return;
        }
        
        currPath.push_back(root->val);
        pathSumCore(root->left, currSum - root->val, res, currPath);
        pathSumCore(root->right, currSum - root->val, res, currPath);
        currPath.pop_back();

    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        
        if(root == nullptr)
            return res;
        
        vector<int> currPath;
        pathSumCore(root, sum, res, currPath);
        
        return res;
    }
};
