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
            
            if(s[i] == '(' || s[i] == ')')
            {
                string ts = "";
                ts += s[i];
                
                expression.push_back(ts);
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
            
            if(s[i] == '+' || s[i] == '-')
            {
                string ts = "";
                ts += s[i];
                
                expression.push_back(ts);
                i++;
                continue;
            }
        
        }
        
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

            if(expression[j] == "(")
            {
                ope.push(expression[j]);
                j++;
                continue;
            }


            if(expression[j] == "+" || expression[j] == "-")
            {
                if(isdigit(expression[j + 1][0]))
                {
                    int new_int = nums.top();
                    nums.pop();

                    if(expression[j] == "+")
                    {
                        new_int += stoi(expression[j + 1]);
                        nums.push(new_int);
                    }
                    else if(expression[j] == "-")
                    {
                        new_int = new_int - stoi(expression[j + 1]);
                        nums.push(new_int);
                    }
                    
                    j = j + 2;
                }
                else
                {
                    ope.push(expression[j]);
                    j++;
                    
                }
                continue;
            }
            
            if(expression[j] == ")")
            {
                ope.pop();
                if(ope.empty())
                {
                    j++;
                    continue;
                }
                
                string ts = ope.top();
                if(ts != "(")
                {
                    ope.pop();
                    int n1 = nums.top();
                    nums.pop();
                    int n2 = nums.top();
                    nums.pop();
                    
                    if(ts == "+")
                    {
                        int new_int = n1 + n2;
                        nums.push(new_int);
                    }
                    else if(ts == "-")
                    {
                        int new_int = n2 - n1;
              
                        nums.push(new_int);
                    }
                    j++;
                    continue;
                }
            }


        }

        int res = nums.top();
        return res;
        

    }
};
