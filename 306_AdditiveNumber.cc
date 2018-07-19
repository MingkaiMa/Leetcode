class Solution {
public:
    
    bool stringIsSum(string a1, string a2, string s){

        string str2 = a2;
        long int len1 = a1.length();
        long int len2 = str2.length();
        int n_size = max(len1, len2);

        vector<int> op1(n_size);    //for large_num
        vector<int> op2(n_size);    //for param
        vector<int> res(n_size + 1);

        int count = abs(len1 - len2);

        //cout << "count is: " << count << "\n";
        for(int i = 0; i < n_size; i++){
            if(n_size == a1.size()){
                op1[i] = a1[i] - '0';
            }
            else if(i < count){
                op1[i] = 0;
            }
            else{
                op1[i] = a1[i - count] - '0';
            }
        }

        for(int i = 0; i < n_size; i++){
            if(n_size == str2.size()){
                op2[i] = str2[i] - '0';
            }
            else if(i < count){
                op2[i] = 0;
            }
            else{
                op2[i] = str2[i - count] - '0';
            }
        }

        reverse(op1.begin(), op1.end());
        reverse(op2.begin(), op2.end());

        int carry = 0;

        for(int i = 0; i < n_size; i++){
            res[i] = (op1[i] + op2[i] + carry) % 10;
            carry = (op1[i] + op2[i] + carry) / 10;
            if(i == n_size - 1 && carry != 0){
                res[n_size] = 1;
            }
            else if(i == n_size - 1 && carry == 0){
                res[n_size] = 0;
            }

        }

        reverse(res.begin(), res.end());


        int flag = 1;
        string R;
        for(int i = 0; i < n_size + 1; i++){
            if(res[i] == 0 && flag == 1){
                continue;
            }
            else{
                R += to_string(res[i]);
                flag = 0;
            }
        }

        if(R.size() == 0)
            R = "0";
        
         // cout << "^" << R << "^" << s << "^" << endl;

            // cout << "===fuck^" << R;
        return R == s;
    }
    
    
    bool core(string num, string first, string second, int start) {
        
        if(start == num.size())
        {
            // cout << "return:" << first<< "^" << second << endl;
            return true;
        }
        
        if(first.size() > 1 && first[0] == '0')
            return false;
        
        if(second.size() > 1 && second[0] == '0')
            return false;
        
        // cout << "satrt is: " << start << endl;
        for(int i = start + 1; i <= num.size(); i++)
        {
            // cout << "i : " << i << endl;
            string temps = num.substr(start, i - start);

            // cout << temps << endl;
            
            
            if(temps[0] == '0' && temps.size() > 1)
                return false;
            
            // cout << "first: " << first  << " second: " << second << " s: " << temps<< endl;
            if(stringIsSum(first, second, temps))
            {
                // cout << "new start i : " <<  i << endl;
                return core(num, second, temps, i);
            }
            // cout << "no\n";
            
        }
        
        return false;
        
        
    }
    
    bool core2(string num, string first, string second, int start)
    {
        //cout << "new start: " << start << endl;
        if(start == num.size())
            return false;
        return core(num, first, second, start);
        
    }
    
    
    bool isAdditiveNumber(string num) {
        
        for(int f1 = 0; f1 < num.size(); f1++)
        {
            for(int s2 = f1 + 1; s2 < num.size(); s2++)
            {
                string a1 = num.substr(0, s2);
                for(int k = 1; k <= num.size() - s2; k++)
                {
                    string a2 = num.substr(s2, k);
                    if(core2(num, a1, a2, s2 + k))
                        return true;
                }
                
            }
        }

        return false;
    }
};
