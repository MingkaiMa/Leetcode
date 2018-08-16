class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        
        
        
        if(tokens.size() == 0)
            return 0;
        
        regex number("^[\+\-]?[0-9]+$");
        

            
        stack<int> Stack;
        
        unordered_set<string> Set = {"+", "-", "*", "/"};
        
        for(int i = 0; i < tokens.size(); i++)
        {
            if(regex_match(tokens[i], number))
            {
                // cout << tokens[i] << endl;
                Stack.push(stoi(tokens[i]));
            }
            
            else
            {
                if(Set.count(tokens[i]) > 0)
                {
                    int firstNb = 0, secondNb = 0, res = 0;
                    
                    if(!Stack.empty())
                    {
                        firstNb = Stack.top();
                        Stack.pop();
                    }
                    else
                        return 0;
                    
                    if(!Stack.empty())
                    {
                        secondNb = Stack.top();
                        Stack.pop();
                    }
                    else
                        return 0;
                    
                    
                    if(tokens[i] == "+")
                        res = firstNb + secondNb;
                    else if(tokens[i] == "-")
                        res = secondNb - firstNb;
                    
                    else if(tokens[i] == "*")
                        res = secondNb * firstNb;
                    
                    else
                        res = secondNb / firstNb;
                    
                    Stack.push(res);
                    
                }
                else
                    return 0;
            }
        }
        
        int finalres = Stack.top();
        Stack.pop();
        
        if(!Stack.empty())
            return 0;
        
        return finalres;
    }
};
