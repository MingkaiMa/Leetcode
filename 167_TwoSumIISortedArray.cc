class Solution {
public:
    
    int binarySearch(const vector<int>& numbers, int start,  int target)
    {
        int left = start;
        int right = numbers.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            
            if(numbers[mid] == target)
                return mid;
            
            if(numbers[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        
        for(int i = 0; i < numbers.size(); i++)
        {
            int j = binarySearch(numbers, i + 1,  target - numbers[i]);
            if(j != -1)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
        }
        
        return res;
    }
};
