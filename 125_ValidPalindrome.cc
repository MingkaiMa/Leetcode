class Solution {
public:
    bool isPalindrome(string s) {

        if(s.size() <= 0)
            return true;

        
        bool emptyFlag = true;
        
        for(auto c: s)
        {
            if(c != ' ')
            {
                emptyFlag = false;
                break;
            }
        }
        
        
        if(emptyFlag == true)
            return true;

        
        string new_s = "";
        
        
        for(auto c: s)
        {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {

                if(c >= 'A' && c <= 'Z')
                    new_s += (c + 32);
                else
                    new_s += c;
            }
        }
        

        cout << new_s << "\n";
        int i = 0;
        int j = new_s.size() - 1;
        
        
        while(i <= j)
        {
            if(new_s[i] != new_s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
};
