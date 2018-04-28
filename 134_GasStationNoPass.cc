class Solution {
public:
    

    bool isValid(vector<int>& gas, vector<int>& cost, int start)
    {
        int remainGas = 0;
        int count = 0;
        int i = start;
        
        while(count < gas.size())
        {
            count++;
            
            if(gas[i] + remainGas < cost[i])
                return false;
            
            remainGas = gas[i] + remainGas - cost[i];
            i = (i + 1) % gas.size();
        }
        
        return true;
    }
    
    
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int length = gas.size();
        
        int remainGas = 0;
        
        for(int start = 0; start < length; start++)
        {
            if(gas[start] < cost[start])
                continue;
            
            if(isValid(gas, cost, start))
                return start;
        }
        
        return -1;
    }
};
