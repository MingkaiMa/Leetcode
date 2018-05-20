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
    void Core(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        Core(root->left);
        res.push_back(root->val);
        Core(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        Core(root);
        
        return res[k - 1];
    }
private:
    vector<int> res;
};
