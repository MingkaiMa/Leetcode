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
        
        
//         int count = 0;
//         numDistinctCore(s, t, 0, 0, count);
        
//         return count;
        
        
        int** matrix = new int*[t.size()];
        for(int i = 0; i < t.size(); i++)
            matrix[i] = new int[s.size()];
        
        
        for(int i = 0; i < t.size(); i++)
        {
            for(int j = 0; j < s.size(); j++)
                matrix[i][j] = 0;
        }
        
        
        for(int i = 0; i < t.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                // if(j - 1 >= 0 && t[i] == s[j])
                //     matrix[i][j] = 1 + matrix[i][j - 1];
                
                if(t[i] == s[j])
                    matrix[i][j] = 1;
            }
        }
        
        
        
//         for(int i = 0; i < t.size(); i++)
//         {
//             for(int j = 0; j < s.size(); j++)
//                 cout << matrix[i][j] << ", ";
//             cout << "\n";
//         }
        
        
        
        for(int i = 1; i < t.size(); i++)
        {
            for(int j = 1; j < s.size(); j++)
            {
                
                if(matrix[i][j] == 1)
                {
                    int count = 0;
                    for(int k = j - 1; k >= 0; k--)
                    {

                        count += matrix[i - 1][k];
                    }

                    matrix[i][j] = count;
                }
                    
            }
        }
        
        // cout << "\n\n";
        // for(int i = 0; i < t.size(); i++)
        // {
        //     for(int j = 0; j < s.size(); j++)
        //         cout << matrix[i][j] << ", ";
        //     cout << "\n";
        // }
        
        
        int res = 0;
        
        for(int j = 0; j < s.size(); j++)
            res += matrix[t.size() - 1][j];
        
        
        return res;
        
        
    }
};
