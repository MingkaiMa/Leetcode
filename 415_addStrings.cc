class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int len1 = num1.size();
        int len2 = num2.size();
        
        string res = "";
        string s1, s2;
        
        if(len1 >= len2){
            s1 = num1;
            s2 = num2;
        }
        else{
            s1 = num2;
            s2 = num1;
        }
        
        
        int n1 = s1.size() - 1;
        int n2 = s2.size() - 1;
        
        int carry = 0, s;
        
        while(n1 >= 0){
            if(n2 >= 0){
                s = s1[n1] - '0' + s2[n2] - '0' + carry;
                
                carry = s / 10;
                s = s % 10;
                
                res.push_back('0' + s);
                
                --n1;
                --n2;
            }
            else{
                s = s1[n1] - '0' + carry;
                
                carry = s / 10;
                s = s % 10;
                
                res.push_back('0' + s);
                
                --n1;
            }
        }
        
        if(carry != 0){
            res.push_back('0' + carry);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
