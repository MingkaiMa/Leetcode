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
    void connect(TreeLinkNode *root) 
    {
        
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
         
            if(currNode->next == nullptr)
            {
                if(currNode->left != nullptr)
                {
                    currNode->left->next = currNode->right;
                }

                if(currNode->right != nullptr)
                {
                    currNode->right->next = nullptr;
                }
                
                
                if(currNode->left != nullptr)
                {
                    currNode = currNode->left;
                    continue;
                }
                else if(currNode->right != nullptr)
                {
                    currNode = currNode->right;
                    continue;
                }
                else
                    break;
                
            }

            
            TreeLinkNode* reserveNextNode = nullptr;
            
            TreeLinkNode* tempNode2 = currNode;
            while(tempNode2)
            {
                if(tempNode2->left != nullptr)
                {
                    reserveNextNode = tempNode2->left;
                    break;
                }
                
                if(tempNode2->right != nullptr)
                {
                    reserveNextNode = tempNode2->right;
                    break;
                }
                tempNode2 = tempNode2->next;
            }
            
            
            
            TreeLinkNode* levelLoop = currNode;


            while(levelLoop != nullptr)
            {

                if(levelLoop->next == nullptr)
                {
                    if(levelLoop->left != nullptr)
                    {
                        levelLoop->left->next = levelLoop->right;
                    }

                    if(levelLoop->right != nullptr)
                    {
                        levelLoop->right->next = nullptr;
                    }
                    break;
                }

                if(levelLoop->left != nullptr)
                {

                    if(levelLoop->right != nullptr)
                        levelLoop->left->next = levelLoop->right;
                    else
                    {
                        TreeLinkNode* tempNode = levelLoop->next;
                        while(true)
                        {
                            if(tempNode->left != nullptr)
                            {
                                levelLoop->left->next = tempNode->left;
                                break;
                            }

                            if(tempNode->right != nullptr)
                            {
                                levelLoop->left->next = tempNode->right;
                                break;
                            }

                            if(tempNode->next == nullptr)
                            {
                                levelLoop->left->next = nullptr;
                                break;
                            }
                            tempNode = tempNode->next;
                        }    
                    }
                }
                if(levelLoop->right != nullptr)
                {
                    TreeLinkNode* tempNode = levelLoop->next;
                    while(true)
                    {
                        if(tempNode->left != nullptr)
                        {
                            levelLoop->right->next = tempNode->left;
                            break;
                        }
                        if(tempNode->right != nullptr)
                        {
                            levelLoop->right->next = tempNode->right;
                            break;
                        }
                        
                        if(tempNode->next == nullptr)
                        {
                            levelLoop->right->next = nullptr;
                            break;
                        }
                        tempNode = tempNode->next;
                    }
                    

                }
                levelLoop = levelLoop->next;
            }    
            currNode = reserveNextNode;   
        }    
    }
};
