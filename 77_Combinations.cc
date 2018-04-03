class Solution {
public:
    
    void Helper(vector<vector<int>>& res, int* arr, vector<int>& data, int start, int end, int index, int k)
    {
        if(index == k)
        {
            res.push_back(data);
            return;
        }
        
        for(int i = start; i <= end && end - i + 1 >= k - index; i++)
        {
            data[index] = arr[i];
            Helper(res, arr, data, i + 1, end, index + 1, k);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
            cout << arr[i] << ", ";
        }
        
        cout << "\n";
        
        vector<vector<int>> res;
        vector<int> data(k);
        Helper(res, arr, data, 0, n - 1, 0, k);
        return res;
    }
};
