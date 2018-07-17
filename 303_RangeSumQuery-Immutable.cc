class NumArray {
public:
    NumArray(vector<int> nums) {
        array = nums;
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        for(int k = i; k <= j; k++)
            res += array[k];
        return res;
    }
private:
    vector<int> array;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
