class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        ;
    }
    
    void addNum(int num) {
        if(nums.size() == 0)
        {
            nums.push_back(num);
            return;
        }
        
        int i = 0;
        for(; i < nums.size(); i++)
        {
            if(nums[i] >= num)
            {
                nums.insert(nums.begin() + i, num);
                return;
            }
        }
        
        if(i == nums.size())
            nums.push_back(num);
        return;
    }
    
    double findMedian() {
        if(nums.size() % 2)
        {
            return nums[nums.size() / 2];
        }
        else
        {
            int le = nums.size();
            int res = nums[le / 2] + nums[le / 2 - 1];
            if(res % 2)
                return res / 2.0;
            else
                return res / 2;
        }
    }
private:
    vector<int> nums;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
