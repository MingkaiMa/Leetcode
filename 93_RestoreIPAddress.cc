class Solution {
public:
    
    
    void restoreCore(string& s, int num, int pos, string& path, vector<string>& res)
    {
        if(pos == s.size() && num == 4)
        {
            res.push_back(path.substr(0, path.size() - 1));
            return;
        }
        
        if(s.size() - pos > 3 * (4 - num))
            return;
        
        if(pos< s.size())
        {
            path += s.substr(pos, 1) + '.';
            restoreCore(s, num + 1, pos + 1, path, res);
            path = path.substr(0, path.size() - 2);
        }
        
        if(pos < s.size() - 1 && s[pos] != '0')
        {
            path += s.substr(pos, 2) + '.';
            restoreCore(s, num + 1, pos + 2, path, res);
            path = path.substr(0, path.size() - 3);
        }
        
        if(pos < s.size() - 2 && s[pos] != '0' && s.substr(pos, 3) <= "255")
        {
            path += s.substr(pos, 3) + '.';
            restoreCore(s, num + 1, pos + 3, path, res);
            path = path.substr(0, path.size() - 4);
        }
        
        
    }
    
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        restoreCore(s, 0, 0, path, res);
        return res;
    }
};
