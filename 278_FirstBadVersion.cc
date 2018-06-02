// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1)
        {
            return isBadVersion(n) ? 1 : 0;
        }
        
        
        int left = 1, right = n;
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(isBadVersion(mid) && (mid == 1 || !isBadVersion(mid - 1)))
            {
                return mid;
            }
            
            else if(isBadVersion(mid))
            {
                right = mid - 1;
            }
            else
                left = mid + 1;

        }
        
        return -1;
        
    }
};
