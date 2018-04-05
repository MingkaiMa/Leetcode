class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        
        if(heights.size() <= 0)
            return 0;
        
        if(heights.size() == 1)
            return heights[0];
        
        
        int maxArea = 0;
        
        stack<int> Stack;
        
        for(int i = 0; i < heights.size(); i++)
        {
            if(Stack.empty() || Stack.top() <= heights[i])
                Stack.push(heights[i]);
            else
            {
                int count = 0;
                while(!Stack.empty() && Stack.top() > heights[i])
                {
                    count++;
                    maxArea = max(maxArea, Stack.top() * count);
                    Stack.pop();
                }
                while(count--)
                    Stack.push(heights[i]);
                Stack.push(heights[i]);
            }
        }
        
        int count = 1;
        while(!Stack.empty())
        {
            maxArea = max(maxArea, Stack.top() * count);
            Stack.pop();
            count++;
        }
        
        return maxArea;
    }
};
