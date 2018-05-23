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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        
        
        if(root->val == p->val || root->val == q->val)
            return root;
        
        
        if(p == q)
            return p;
        
        
        stack<vector<TreeNode*>> Stack;
        
        
        vector<vector<TreeNode*>> table;
        
        vector<TreeNode*> tmp = {root};
        Stack.push(tmp);
        
        bool findP = false;
        bool findQ = false;
        
        while(!Stack.empty())
        {
            
            if(findP == true && findQ == true)
                break;
            
            vector<TreeNode*> currV = Stack.top();
            Stack.pop();
            
            TreeNode* lastNode = currV.back();
            
            if(lastNode == p)
            {
                table.push_back(currV);
                findP = true;
            }
            
            if(lastNode == q)
            {
                table.push_back(currV);
                findQ = true;
            }

            
            if(lastNode->right != nullptr)
            {
                vector<TreeNode*> tmpV = currV;
                tmpV.push_back(lastNode->right);
                Stack.push(tmpV);
            }

            if(lastNode->left != nullptr)
            {
                vector<TreeNode*> tmpV = currV;
                tmpV.push_back(lastNode->left);
                Stack.push(tmpV);
            }
            
            
        }
        
        
        
        vector<TreeNode*> v1 = table[0];
        vector<TreeNode*> v2 = table[1];
        
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
  
        if(v1.size() == v2.size())
        {
            int i = 0;
            while(i < v1.size())
            {
                if(v1[i] == v2[i])
                    return v1[i];
                i++;
            }
        }
        
        if(v1.size() > v2.size())
        {
            int diff = v1.size() - v2.size();
            
            int i1 = diff;
            int i2 = 0;
            
            while(i2 < v2.size())
            {
                if(v1[i1] == v2[i2])
                    return v1[i1];
                i1++;
                i2++;
            }
        }
        
        if(v1.size() < v2.size())
        {
            int diff = v2.size() - v1.size();
            
            int i1 = 0;
            int i2 = diff;
            while(i1 < v1.size())
            {
                if(v1[i1] == v2[i2])
                    return v1[i1];
                i1++;
                i2++;
            }
        }
        
        return nullptr;  
    }
};
