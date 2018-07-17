// reference: https://www.cnblogs.com/grandyang/p/4913869.html
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
private:

    void serializeCore(TreeNode* root, ostringstream &out)
    {
        if(root == nullptr)
            out << "# ";
        else
        {
            out << root->val << ' ';
            serializeCore(root->left, out);
            serializeCore(root->right, out);
        }
    }
    
    TreeNode* deserializeCore(istringstream &in){
        
        string val;
        in >> val;
        
        if(val == "#") 
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeCore(in);
        node->right = deserializeCore(in);
        return node;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeCore(root, out);
        return out.str();
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        istringstream in(data);
        return deserializeCore(in);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
