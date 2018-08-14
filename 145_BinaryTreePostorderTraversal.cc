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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};

        
        vector<int> res;
        
        stack<TreeNode*> Stack;
        
        
        Stack.push(root);
        
        unordered_map<TreeNode*, int> Map;
        
        
        while(!Stack.empty())
        {
            TreeNode* currNode = Stack.top();
            
            if(Map.count(currNode) <= 0)
            {
                Map[currNode] = 1;
                if(currNode->right != nullptr)
                    Stack.push(currNode->right);
                if(currNode->left != nullptr)
                    Stack.push(currNode->left);
            }
            else
            {
                Stack.pop();
                res.push_back(currNode->val);
            }
        }
        
        return res;
    }
};
