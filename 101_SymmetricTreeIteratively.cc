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

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;

        TreeNode* node1 = root;
        TreeNode* node2 = root;
        
        
        stack<TreeNode*> Stack1;
        stack<TreeNode*> Stack2;
        
        
        while(node1 != nullptr)
        {
            Stack1.push(node1);
            node1 = node1->left;
        }
        
        while(node2 != nullptr)
        {
            Stack2.push(node2);
            node2 = node2->right;
        }
        
        
        while(!Stack1.empty() && !Stack2.empty())
        {
            TreeNode* curr1 = Stack1.top();
            TreeNode* curr2 = Stack2.top();
            Stack1.pop();
            Stack2.pop();
            
            if(Stack1.size() != Stack2.size())
                return false;
            
            if(curr1->val != curr2->val)
                return false;
            
            
            if(curr1->right != nullptr && curr2->left != nullptr)
            {
                TreeNode* temp_curr1 = curr1->right;
                while(temp_curr1 != nullptr)
                {
                    Stack1.push(temp_curr1);
                    temp_curr1 = temp_curr1->left;
                }
                
                TreeNode* temp_curr2 = curr2->left;
                while(temp_curr2 != nullptr)
                {
                    Stack2.push(temp_curr2);
                    temp_curr2 = temp_curr2->right;
                }
            }

        }
        
        return true;
        
    }
};
