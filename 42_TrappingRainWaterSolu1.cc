class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;
        
        int res = 0;
        int size = height.size();
        
        for(int i = 1; i < size - 1; ++i){
            int leftMax = 0, rightMax = 0;
            for(int j = i; j >= 0; --j)
                leftMax = max(leftMax, height[j]);
            for(int j = i; j < size; ++j)
                rightMax = max(rightMax, height[j]);
            
            res += min(leftMax, rightMax) - height[i];
        }
        return res;
    }
};
