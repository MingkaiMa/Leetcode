class Solution {
public:
    void coreDFS(string s, char ch, int last) {
        for(int i = 0, cnt = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == ')')
                s[i] == ch ? cnt++ : cnt--;
            
            if(cnt <= 0)
                continue;
            
            for(int j = last; j <= i; j++)
            {
                if(s[j] == ch && (j == last || s[j - 1] != ch))
                    coreDFS(s.substr(0, j) + s.substr(j + 1), ch, j);
            }
            return;
        }
        reverse(s.begin(), s.end());
        if(ch == ')')
            return coreDFS(s, '(', 0);
        ans.push_back(s);
    }
    vector<string> removeInvalidParentheses(string s) {
        coreDFS(s, ')', 0);
        return ans;
    }
private:
    vector<string> ans;
};
