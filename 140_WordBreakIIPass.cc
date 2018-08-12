class Solution {
public:
    vector<vector<string>> mem;
    vector<int> visit;
    
    void DFS(string& s, vector<string>& wordDict, int pos)
    {
        visit[pos] = 1;
        for(int i = pos + 1; i <= s.size(); i++)
        {
            
            if(find(wordDict.begin(), wordDict.end(), s.substr(pos, i - pos)) == wordDict.end())
                continue;
            if(i == s.size())
            {
                mem[pos].push_back(s.substr(pos, i - pos));
                continue;
            }
            
            if(!visit[i])
                DFS(s, wordDict, i);
            for(auto& str: mem[i])
                mem[pos].push_back(s.substr(pos, i - pos) + " " + str);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        visit.resize(s.size());
        mem.resize(s.size());
        DFS(s, wordDict, 0);
        vector<string> res = mem[0];
        mem.clear();
        visit.clear();
        return res;
    }
};
