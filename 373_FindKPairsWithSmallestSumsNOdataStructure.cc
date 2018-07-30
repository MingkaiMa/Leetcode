class Solution {
public:

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int len1 = nums1.size();
        int len2 = nums2.size();
        int cnt = min(k, len1 * len2);
        
        vector<int> index(len1, 0);
        vector<pair<int, int>> res;
        while(cnt-- > 0){
            int tmpMin = INT_MAX, m = 0;
            for(int i = 0; i < len1; i++){
                if(index[i] < len2 && nums1[i] + nums2[index[i]] < tmpMin){
                    tmpMin = nums1[i] + nums2[index[i]];
                    m = i;
                }
            }
            res.push_back({nums1[m], nums2[index[m]++]});
        }
        return res;
    }
};
