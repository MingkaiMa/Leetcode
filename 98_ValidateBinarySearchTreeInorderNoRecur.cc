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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        stack<TreeNode*> Stack;
        
        TreeNode* tempNode = root;
        
        while(tempNode != nullptr)
        {
            Stack.push(tempNode);
            tempNode = tempNode->left;
        }
        
        vector<TreeNode*> list;
        
        
        
        while(!Stack.empty())
        {
            TreeNode* curr = Stack.top();
            Stack.pop();
            
            if(list.size() > 0)
            {
                if(list.back()->val >= curr->val)
                    return false;
            }
            
            
            
            list.push_back(curr);
            
            
            if(curr->right != nullptr)
            {
                TreeNode* now = curr->right;
                while(now != nullptr)
                {
                    Stack.push(now);
                    now = now->left;
                }
            }
            
            
        }
        
        return true;
    
    }
};
