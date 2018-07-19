

class Solution {
public:
    
    struct TreeNode {
        int val;
        unordered_set<TreeNode*> neig;
        TreeNode(int v) : val(v) {}
    };

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        map<int, TreeNode*> val_node;
        
        for(int i = 0; i < n; i++) {
            TreeNode* tmp = new TreeNode(i);
            val_node[i] = tmp;
        }
        
        for(int i = 0; i < edges.size(); i++) {
            pair<int, int> pp = edges[i];
            val_node[pp.first]->neig.insert(val_node[pp.second]);
            val_node[pp.second]->neig.insert(val_node[pp.first]);
        }
        
        map<int, TreeNode*>::iterator m_iter;
        
        while(val_node.size() > 2) {
            list<TreeNode*> lstg;
            
            for(m_iter = val_node.begin(); m_iter != val_node.end(); m_iter++) {
                if(m_iter->second->neig.size() == 1)
                    lstg.push_back(m_iter->second);
            }
            list<TreeNode*>::iterator l_iter;
            for(l_iter = lstg.begin(); l_iter != lstg.end(); l_iter++){
                TreeNode* p = (*(*l_iter)->neig.begin());
                p->neig.erase(*l_iter);
                (*l_iter)->neig.erase(p);
                
                val_node.erase((*l_iter)->val);
            }    
        }
        
        vector<int> res;
        for(m_iter = val_node.begin(); m_iter != val_node.end(); m_iter++) {
            res.push_back(m_iter->first);
        }
        return res;
        
    }
};
