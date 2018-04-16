class Solution {
public:
    
    
    void numDistinctCore(string s, string t, int sStart, int tStart, int& count)
    {
        
        if((s.size() - sStart) < (t.size() - tStart))
            return;
        
        if(tStart == t.size())
        {
            count++;
            return;
        }
        
        
        for(int i = sStart; i < s.size(); i++)
        {
            if(s[i] == t[tStart])
                numDistinctCore(s, t, i + 1, tStart + 1, count);
        }
    }
    
    
    
    int numDistinct(string s, string t) {
        if(s.size() == 0 && t.size() == 0)
            return 1;
        
        if(s.size() == 0 || t.size() == 0)
            return 0;
        
        
        int count = 0;
        numDistinctCore(s, t, 0, 0, count);
        
        return count;
        
    }
};