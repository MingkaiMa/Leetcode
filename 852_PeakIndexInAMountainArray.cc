class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        
        int res = 0;
        
        while(left < right){
            
            int mid = left + (right - left) / 2;
            int m1 = mid - 1;
            int m2 = mid + 1;
            
            if(A[mid] > A[m1] && A[mid] > A[m2]){
                return mid;
            }
            
            else if(A[mid] > A[m1] && A[mid] < A[m2]){
                left = m2;
            }
            
            else if(A[mid] < A[m1] && A[mid] > A[m2]){
                right = m1;
            }
            
        }
        
        return left;
    }
};
