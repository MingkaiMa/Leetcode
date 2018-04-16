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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        
        
        TreeNode* curr = root;

        
        while(curr != nullptr)
        {

            TreeNode* reserveLeft = curr->left;
            TreeNode* reserveRight = curr->right;
            
            if(reserveLeft != nullptr && reserveRight != nullptr)
            {
                curr->left = nullptr;
                curr->right = reserveLeft;
                
                TreeNode* tempNode = reserveLeft;
                while(tempNode->right != nullptr)
                {
                    tempNode = tempNode->right;
                }
                
                tempNode->right = reserveRight;
                
                curr = reserveLeft;
                
            }
            
            else if(reserveLeft == nullptr)
                curr = reserveRight;
            
            else if(reserveRight == nullptr)
            {
                curr->left = nullptr;
                curr->right = reserveLeft;
                curr = curr->right;
            }
        }
        
    }
};
