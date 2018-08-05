cclass Solution {
public:

    int maxRotateFunction(vector<int>& A) {
        
        int allSum = 0, n = A.size(), F = 0;
        
        for(int i = 0; i < n; ++i){
            F = F + i * A[i];
            allSum += A[i];
        }
        
        int res = F;
        for(int i = n - 1; i >= 1; --i){
            F = F + allSum - n * A[i];
            res = max(res, F);
        }
        return res;

    }
};


class Solution {
public:
    void rotate(vector<int>& A){
        int key = A[A.size() - 1];
        for(int i = A.size() - 2; i >= 0; --i){
            A[i + 1] = A[i];
        }
        A[0] = key;
    }
    int maxRotateFunction(vector<int>& A) {
        
        if(A.size() == 0)
            return 0;
        
        if(A.size() == 1)
            return 0;
        
        if(A.size() == 2){
            int n1 = 0 * A[0] + 1 * A[1];
            int n2 = 0 * A[1] + 1 * A[0];
            if(n1 >= n2)
                return n1;
            return n2;
        }
        
        
        int res = INT_MIN;
        
        for(int i = 0; i < A.size(); i++){
            // for(auto& a: A)
            //     cout << a << ", ";
            // cout << endl;
            
            int tmp = 0;
            
            for(int j = 0; j < A.size(); j++){
                tmp = tmp + j * A[j];
            }
            
            if(tmp > res)
                res = tmp;
            
            rotate(A);
        }
        return res;
    }
};

