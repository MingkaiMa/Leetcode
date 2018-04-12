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
    
    TreeNode* sortedArrayToBSTCore(vector<int>& nums)
    {
        if(nums.size() == 1)
        {
            TreeNode* node = new TreeNode(nums[0]);
            return node;
        }
        
        if(nums.size() == 0)
            return nullptr;
        
        
        int rootIndex = nums.size() / 2;
        
        TreeNode* root = new TreeNode(nums[rootIndex]);
        
        vector<int> left(nums.begin(), nums.begin() + rootIndex);
        vector<int> right(nums.begin() + rootIndex + 1, nums.end());
        
        root->left = sortedArrayToBSTCore(left);
        root->right = sortedArrayToBSTCore(right);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTCore(nums);
    }
};
