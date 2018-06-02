class Solution {
    
    vector<string> res;
    
public:
    
    void Core(string num, int target, string tmp, long currRes, long prevNum)
    {
        if(currRes == target && num.size() == 0)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i = 1; i < num.size() + 1; i++)
        {
            string currStr = num.substr(0, i);
            
            if(currStr.size() > 1 && currStr[0] == '0')
                return;
            
            long currNum = stol(currStr);
            
            string next = num.substr(i);
            
            if(tmp.size() != 0)
            {
                Core(next, target, tmp+"*"+ to_string(currNum), (currRes - prevNum) + prevNum * currNum, prevNum * currNum);
                Core(next, target, tmp+"+"+to_string(currNum), currRes + currNum, currNum);  
                Core(next, target, tmp+"-"+to_string(currNum), currRes - currNum, -currNum); 
            }else
                Core(next, target, currStr, currNum, currNum); 
        }
    }
    
    vector<string> addOperators(string num, int target) {
        Core(num, target, "", 0, 0);
        return res;
    }
};
