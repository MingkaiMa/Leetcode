/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int> nums;
        
        ListNode* curr = head;
        while(curr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        
        return sortedArrayToBSTCore(nums);
    }
};
