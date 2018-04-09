
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

    vector<TreeNode*> core(int start, int end)
    {
        vector<TreeNode*> res;
        
        if(start > end)
        {
            res.push_back(NULL);
            return res;
        }
        
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftVector = core(start, i - 1);
            vector<TreeNode*> rightVector = core(i + 1, end);
            for(auto left: leftVector)
            {
                for(auto right: rightVector)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        
        }
        
        return res;
    
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)
        {
            vector<TreeNode*> res;
            return res;
        }
        
        return core(1, n);
    }
};
