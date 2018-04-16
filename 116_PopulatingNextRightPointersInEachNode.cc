/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            root->next = nullptr;
            return;
        }
        
        
        TreeLinkNode* currNode = root;
        currNode->next = nullptr;
        
        while(currNode != nullptr)
        {
            
            if(currNode->left == nullptr || currNode->right == nullptr)
                return;
            
            
            if(currNode->next == nullptr)
            {
                currNode->left->next = currNode->right;
                currNode->right->next = nullptr;
                currNode = currNode->left;
                continue;
            }
            
            TreeLinkNode* reserveNextNode = currNode->left;
            TreeLinkNode* levelLoop = currNode;
            
            
            while(levelLoop != nullptr)
            {
                
                if(levelLoop->next == nullptr)
                {
                    levelLoop->left->next = levelLoop->right;
                    levelLoop->right->next = nullptr;
                    break;
                }
                levelLoop->left->next = levelLoop->right;
                levelLoop->right->next = levelLoop->next->left;
                levelLoop = levelLoop->next;
            }    
            currNode = reserveNextNode;
        }
    }
};
