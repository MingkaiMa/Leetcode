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
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() <= 0)
            return 0;
        
        vector<vector<int>> intMatrix(matrix.size());
        
        for(int i = 0; i < matrix.size(); i++)
        {
            vector<int> t;
            for(int j = 0; j < matrix[0].size(); j++)
                t.push_back(matrix[i][j] - '0');
            
            intMatrix[i] = t;
        }
        

        
        for(int i = 1; i < intMatrix.size(); i++)
        {

            for(int j = 0; j < intMatrix[0].size(); j++)
            {
                if(intMatrix[i][j] != 0)
                    intMatrix[i][j] += intMatrix[i - 1][j];
                
            }

        }
        
        
        int maxArea = -1;
        
        for(int i = 0; i < intMatrix.size(); i++)
        {
            int currArea = largestRectangleArea(intMatrix[i]);
            if(currArea > maxArea)
                maxArea = currArea;
        }
        
        return maxArea;
    }
};
