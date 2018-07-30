class Solution {
public:

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int, int>> res;
        multimap<int, pair<int, int>> Heap;

        for(int i = 0; i < min((int)nums1.size(), k); i++){
            for(int j = 0; j < min((int)nums2.size(), k); j++){
                Heap.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        
        for(auto it = Heap.begin(); it != Heap.end(); it++){
            res.push_back(it->second);
            if(--k <= 0)
                return res;
        }
        
        return res;
    }
};
