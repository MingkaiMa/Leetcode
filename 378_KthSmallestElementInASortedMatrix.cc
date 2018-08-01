class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> S;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                S.insert(matrix[i][j]);
            }
        }
        
 
        for(auto it = S.begin(); it != S.end(); it++){
            if(k == 1)
                return *it;
            else
                k--;
        }
    }
};
