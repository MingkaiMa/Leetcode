class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0 && b.size() == 0)
            return "0";
        
        if(a.size() == 0)
            return b;
        
        if(b.size() == 0)
            return a;
        
        
        if(a.size() > b.size())
        {
            string s = "";
            for(int i = 0; i < (a.size() - b.size()); i++)
                s += '0';
            
            b = s + b;                
        }
        
        else if(a.size() < b.size())
        {
            string s = "";
            for(int i = 0; i < (b.size() - a.size()); i++)
                s += '0';
            
            a = s + a;
        }
        
        
        
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        string res = "";
        
        while(i >= 0 && j >= 0)
        {
            int aValue = a[i] - '0';
            int bValue = b[j] - '0';
            
            int cValue = (aValue + bValue + carry) % 2;
            carry = (aValue + bValue + carry) / 2;
            
            res += to_string(cValue);
            
            i--;
            j--;    
        }
        
        if(carry != 0)
            res += to_string(carry);
        
        
        string ss = "";
        for(int i = res.size() - 1; i >= 0; i--)
            ss += res[i];
        return ss;
    }
    
};
