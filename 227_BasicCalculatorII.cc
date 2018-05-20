class Solution {
public:
    int calculate(string s) {
        vector<string> expression;
        
        
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            
                        
            if(isdigit(s[i]))
            {
                int start = i;
                while(isdigit(s[start]))
                    start++;
                
 
                string ds = s.substr(i, start - i);                
                expression.push_back(ds);
                i = start;
                continue;
            }
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                string ts = "";
                ts += s[i];
                
                expression.push_back(ts);
                i++;
                continue;
            }
        
        }
        
        
        for(auto& i: expression)
            cout << i << ", ";
        cout << endl;
        
        
        stack<string> ope;
        stack<int> nums;

        int j = 0;
        
        while(j < expression.size())
        {
            if(isdigit(expression[j][0]))
            {
                nums.push(stoi(expression[j]));
                j++;
                continue;
            }
            
            if(expression[j] == "+" || expression[j] == "-")
            {
                if(ope.empty())
                {
                    ope.push(expression[j]);
                    j++;
                    continue;
                }
                
                while(!ope.empty())
                {
                    string opp = ope.top();
                    ope.pop();
                    
                    int n1 = nums.top();
                    nums.pop();
                    int n2 = nums.top();
                    nums.pop();
                    
                    if(opp == "+")
                    {
                        int tmp = n1 + n2;
                        nums.push(tmp);
                    }
                    else if(opp == "-")
                    {
                        int tmp = n2 - n1;
                        nums.push(tmp);
                    }
                }
                
                ope.push(expression[j]);
                j++;
                continue;
            }
            
            if(expression[j] == "*" || expression[j] == "/")
            {
                int nextNb = stoi(expression[j + 1]);
                int preNb = nums.top();
                nums.pop();
                
                if(expression[j] == "*")
                {
                    int tmp = preNb * nextNb;
                    nums.push(tmp);
                }
                else if(expression[j] == "/")
                {
                    int tmp = preNb / nextNb;
                    nums.push(tmp);
                }
                
                j += 2;
            }
            
        }
        
        
        if(ope.empty())
        {
            return nums.top();
        }
        
        
        string opp = ope.top();
        ope.pop();
        
        int n1 = nums.top();
        nums.pop();
        int n2 = nums.top();
        nums.pop();
        
        if(opp == "+")
            return n1 + n2;
        return n2 - n1;
        
    }
};
