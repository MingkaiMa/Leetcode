class Solution {
public:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr)
            return nullptr;   
        
        if(hash.count(node)) return hash[node];
        
        hash[node] = new UndirectedGraphNode(node->label);

        for(auto& n: node->neighbors)
        {
            hash[node]->neighbors.push_back(cloneGraph(n));
        }
        return hash[node];
    }
};
