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
    
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        stack<vector<TreeNode*>> Stack;
        vector<TreeNode*> List = {root};
        Stack.push(List);
        
        vector<vector<TreeNode*>> res;
        
        
        while(!Stack.empty())
        {
            vector<TreeNode*> currList = Stack.top();
            Stack.pop();
            
            TreeNode* lastNode = currList.back();
            
            if(lastNode->left == nullptr && lastNode->right == nullptr)
                res.push_back(currList);
            
            if(lastNode->left != nullptr)
            {
                currList.push_back(lastNode->left);
                Stack.push(currList);
                currList.pop_back();
            }
            
            if(lastNode->right != nullptr)
            {
                currList.push_back(lastNode->right);
                Stack.push(currList);
                currList.pop_back();
            }
        }
        
        int sum = 0;
        
        for(auto& v: res)
        {
            int length = v.size();
            for(auto& node: v)
            {
                sum += pow(10, length - 1) * node->val;
                length--;
            }
        }
        
        return sum;
    }
};
