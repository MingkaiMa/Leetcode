#include <iostream>
#include <vector>

using namespace std;

int splitArray(vector<int>& nums, int m) {

    
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; ++i)
        sums[i] = sums[i - 1] + nums[i - 1];
    
    
    for(int i = 0; i < sums.size(); ++i)
        cout << sums[i] << ", ";
    cout << endl;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = i - 1; k < j; ++k){
                cout << "i: " << i << " j: " << j << " k: " << k << endl;
                int val = max(dp[i - 1][k], sums[j] - sums[k]);
                dp[i][j] = min(dp[i][j], val);

                for(auto& r: dp){
                    for(auto& rr: r)
                        cout << rr << ", ";
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    return dp[m][n];
}

int main(){
    vector<int> nums = {7,2,5,10,8};
    int m = 2;

    cout << splitArray(nums, m) << endl;
}