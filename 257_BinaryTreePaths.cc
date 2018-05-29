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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<TreeNode*> tmp = {root};
        vector<vector<TreeNode*>> res;
        
        stack<vector<TreeNode*>> Stack;
        
        Stack.push(tmp);
        
        
        while(!Stack.empty())
        {
            vector<TreeNode*> currList = Stack.top();
            Stack.pop();
            
            TreeNode* lastNode = currList.back();
            
            if(lastNode->left == nullptr && lastNode->right == nullptr)
            {
                res.push_back(currList);
                continue;
            }
            
            if(lastNode->right != nullptr)
            {
                vector<TreeNode*> temp = currList;
                temp.push_back(lastNode->right);
                Stack.push(temp);
            }
            
            if(lastNode->left != nullptr)
            {
                vector<TreeNode*> temp = currList;
                temp.push_back(lastNode->left);
                Stack.push(temp);
            }
        }
        
        vector<string> ret;
        
        for(auto& v: res)
        {
            string s = "";
            for(int i = 0; i < v.size(); i++)
            {
                if(i == v.size() - 1)
                {
                    s += to_string(v[i]->val);
                    continue;
                }
                
                
                s += to_string(v[i]->val);
                s += "->";
            }
            
            ret.push_back(s);
        }
        
        return ret;
        
    }
};
