class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> array(s.size() + 1, false);
        
        array[0] = true;
        
        for(int i = 1;i < s.size() + 1; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(array[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {                    
                    array[i] = true;
                    break;
                }
            }
        }
        
        return array[s.size()];
    }
};
