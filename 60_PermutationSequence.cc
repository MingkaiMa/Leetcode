class Solution {
public:
    void nextPermutation(string& s)
    {

        if(s.size() <= 1)
            return;
    
        int count_flag = s.size() - 1;
        
        while(count_flag - 1 >= 0 && s[count_flag - 1] > s[count_flag])
            count_flag--;
        
        
        if(count_flag == s.size() - 1)
        {
            swap(s[count_flag - 1], s[count_flag]);
            return;
        }
        
        
        if(count_flag == 0)
        {
            sort(s.begin(), s.end());
            return;
        }
        
        int key_value = s[count_flag - 1];
        
        int count2 = s.size() - 1;
        
        int count_find = -1;
        
        while(count2 >= 0)
        {
            if(s[count2] > key_value)
            {
                count_find = count2;
                break;
            }
            
            count2--;
        }
        
        swap(s[count_find], s[count_flag - 1]);
        
        sort(s.begin() + count_flag, s.end());
        
        
        
        

    }
    string getPermutation(int n, int k) {
        
        
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            s += to_string(i);
        }
        
        if(k == 1)
            return s;
        
        k -= 1;
        
        while(k > 0)
        {
            nextPermutation(s);
            //cout << s << "\n";
            k -= 1;
        }
        

        return s;
    }
};
