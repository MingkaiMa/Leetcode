#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        vector<int> R;

        std::map<int, int> dic;
        for(int i = 0; i < nums.size(); i++){
            dic[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int other = target - nums[i];
            auto search = dic.find(other);

            if(search != dic.end() && search->second != i){
                R = {i, search->second};
                break;

            }

        }


        return R;
    }
};
